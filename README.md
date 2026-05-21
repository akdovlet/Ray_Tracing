# miniRT — Software Ray Tracer

A from-scratch software ray tracer written in C, built without any graphics API for the actual rendering math. Implements three rendering modes — classic Whitted ray tracing, Monte Carlo path tracing, and multithreaded path tracing — all switchable at runtime. The project was written as part of the 42 school curriculum and guided by *The Ray Tracer Challenge* by Jamis Buck.

Generative AI was used only for bump mapping implementation and generating this README.

---

## Dependencies

| Dependency | Purpose | Notes |
|---|---|---|
| [minilibx-linux](https://github.com/42paris/minilibx-linux) | Window creation, image buffer, event loop | Cloned and built automatically by `make` |
| libft | Custom C standard library | Bundled under `libft/` |
| X11 / Xext | Display backend for MiniLibX | Must be installed on the system |
| zlib | Required by MiniLibX | Must be installed on the system |
| pthread | Multithreaded rendering | Part of glibc |
| libm | Math functions (`sin`, `cos`, `sqrt`, …) | Part of glibc |

### Installing system dependencies (Debian / Ubuntu)

```bash
sudo apt-get install libx11-dev libxext-dev zlib1g-dev
```

---

## Building

```bash
# Full build (fetches MiniLibX via git if not present, then compiles)
make

# Rebuild from scratch
make re

# Clean object files
make clean

# Clean everything including the binary
make fclean
```

The binary is output as `./minirt` in the project root.

Compilation flags: `-Wall -Werror -Wextra -std=gnu11`

---

## Usage

```
./minirt [flag] <scene.rt>
```

| Flag | Rendering mode |
|---|---|
| *(none)* | Ray tracing (Whitted-style, single-threaded) |
| `-p` | Path tracing (single-threaded, progressive accumulation) |
| `-t` | Path tracing (multithreaded, progressive accumulation) |

The flag and the scene file can be given in either order.

```bash
./minirt scenes/scene1.rt          # Ray tracing
./minirt -p scenes/cornell.rt      # Path tracing, single thread
./minirt -t scenes/cornell.rt      # Path tracing, 4 threads
```

### Runtime controls

| Key | Action |
|---|---|
| `W / S` | Move camera forward / backward |
| `A / D` | Strafe camera left / right |
| `Q / E` | Move camera down / up |
| `Tab` | Cycle through the three rendering modes |
| `Escape` | Quit |

Moving the camera resets the path tracing accumulation buffer so the image reconverges from scratch.

---

## Scene file format (`.rt`)

Lines starting with `#` are comments. Each object type is identified by a keyword at the start of the line.

```
# Ambient light
A  <ratio [0-1]>  <R,G,B>

# Camera
C  <x,y,z>  <dir_x,dir_y,dir_z>  <fov>

# Point light
L  <x,y,z>  <brightness [0-1]>  <R,G,B>

# Sphere
sp  <x,y,z>  <diameter>  <R,G,B>  [emission]  [bump.xpm]

# Plane
pl  <x,y,z>  <normal_x,normal_y,normal_z>  <R,G,B>  [emission]

# Cylinder
cy  <x,y,z>  <normal_x,normal_y,normal_z>  <diameter>  <height>  <R,G,B>  [emission]

# Cube
cu  <x,y,z>  <normal_x,normal_y,normal_z>  <side_length>  <R,G,B>  [emission]

# Cone
co  <x,y,z>  <normal_x,normal_y,normal_z>  <diameter>  <height>  <R,G,B>  [emission]
```

`emission` is a positive float. Set it to 0 for non-emissive surfaces; any value above 0 makes the object a light source (meaningful in path tracing mode). The optional `bump.xpm` path attaches a height-map texture for bump mapping.

Example scenes are provided in the `scenes/` directory:

| File | Description |
|---|---|
| `scenes/scene1.rt` | Simple ray-tracing reference scene |
| `scenes/cornell.rt` | Cornell box — classic global illumination benchmark |
| `scenes/bump_test.rt` | Demonstrates bump mapping on a sphere |
| `scenes/bonus.rt` | Combined features showcase |

---

## Rendering engines

### 1. Ray tracing (`RAY`, default)

Classic Whitted-style recursive ray tracing. For each pixel, one ray is cast from the camera and traced through the scene:

- **Phong / Blinn-Phong shading** — ambient, diffuse, and specular contributions computed per light source.
- **Hard shadows** — a shadow ray is cast from the intersection point toward each light. Transparent objects do not cast shadows.
- **Reflections** — mirror-like reflections computed recursively up to a depth of 5 bounces.
- **Refractions** — Snell's law refraction through transparent objects, also recursively traced.
- **Schlick approximation** — for objects that are both reflective and transparent, the Schlick formula blends the reflected and refracted contributions based on the viewing angle, approximating the Fresnel equations.

This mode renders instantaneously (one pass) but does not produce global illumination effects like soft shadows or diffuse inter-reflection.

### 2. Path tracing (`PATH`, `-p`)

Monte Carlo path tracing with progressive accumulation. Each frame fires one ray per pixel with a random offset, and the result is averaged over all frames into an accumulation buffer. The image converges toward ground-truth global illumination over time.

Key properties of the integrator:

- **5 bounces per path** — each ray scatters up to 5 times before being terminated.
- **Cosine-weighted hemisphere sampling** — scattered ray directions are chosen by adding a random unit vector to the surface normal, which approximates a cosine distribution over the hemisphere and naturally weights low-angle bounces less.
- **Stochastic specular** — at each bounce, a random number is compared against the object's `specular` probability. If the sample passes, the ray follows the perfect mirror direction; otherwise it takes the diffuse direction. The `roughness` parameter lerps between the two, allowing anything from matte to mirror.
- **Emissive objects as area lights** — any object with a non-zero emission value contributes light directly when hit, replacing the need for explicit shadow rays.
- **Russian roulette termination** — from bounce 3 onward, paths are stochastically terminated based on the current ray throughput (max channel value). Surviving paths are re-weighted to keep the estimator unbiased, and low-energy paths are culled early to avoid wasting samples.
- **Sky contribution** — rays that escape the scene pick up the sky color, serving as an environment light.

### 3. Multithreaded path tracing (`PATH_MT`, `-t`)

Identical to mode 2 but the screen is divided into horizontal bands, one per thread (4 threads by default, configurable via the `THREADS` constant in `include/minirt.h`). All threads share read access to the scene and write to disjoint regions of the accumulation buffer, so no locking is required.

---

## Techniques

### Geometry and intersection

All shapes implement a common function-pointer interface (`local_intersect`, `local_normalat`, `local_tangent`) stored directly in the shape struct. Supported primitives:

- Sphere
- Plane (infinite)
- Cylinder (finite, with end caps)
- Cone (finite, with end cap)
- Cube (axis-aligned)
- Triangle

Transformations (translation, rotation, scaling) are represented as 4×4 matrices. Each shape stores its transform as an inverse matrix; rays are transformed into object space before intersection testing, and normals are transformed back with the transpose of the inverse (the correct normal transformation).

### Materials

Each object carries a `t_material` struct with the following properties:

| Field | Effect |
|---|---|
| `color` | Base albedo |
| `ambient` | Ambient light multiplier |
| `diffuse` | Lambertian diffuse strength |
| `specular` | Specular highlight strength / stochastic specular probability |
| `shininess` | Phong shininess exponent |
| `roughness` | Lerp factor between diffuse and mirror direction (path tracing) |
| `reflective` | Mirror reflectance (ray tracing) |
| `transparency` | Opacity — 0 is opaque, 1 is fully transparent |
| `refractive_index` | Index of refraction (e.g. 1.5 for glass) |
| `emission_power` | Emission multiplier for path tracing area lights |
| `emission_color` | Tint of emitted light |
| `specular_color` | Color of specular highlights / mirror reflections |

### Patterns and UV mapping

A flexible pattern system supports procedural textures applied in UV space via a swappable `uv_mapping` function pointer:

- **Stripe** — alternating bands
- **Ring** — concentric rings
- **Radial** — polar gradient
- **Checker** — standard checkerboard (3D and UV-space variants)
- **Gradient** — linear color interpolation
- **Spherical map** — equirectangular projection for sphere textures
- **Cylindrical map** — wrapping projection for cylinders
- **Planar map** — flat projection for planes
- **Cube map** — six-face UV mapping for cubes, each face independently configurable
- **Image texture** — XPM images loaded via MiniLibX, projected via any of the above mappings

### Bump mapping

Height-map bump mapping is available for all primitives that expose a tangent function. The bump map is provided as an XPM image in the scene file. At each intersection the renderer:

1. Samples the height map at the UV coordinate and at ±1 pixel offsets to compute the gradient `(dh/du, dh/dv)`.
2. Constructs a TBN (tangent, bitangent, normal) matrix from the object's geometric normal and analytically computed tangent.
3. Perturbs the normal using the height gradient in tangent space, producing the illusion of surface relief without adding geometry.

### Refractions and Fresnel

The `pre_compute` function builds a container list tracking which transparent objects a ray is currently inside. This allows correct computation of `n1` (refractive index of the medium being exited) and `n2` (medium being entered) at each interface, enabling proper multi-layer refraction. Total internal reflection and the Fresnel blend are handled by the Schlick approximation.

### Random number generation

Path tracing uses a **PCG hash** (Permuted Congruential Generator) for all random numbers. The seed is derived from the pixel index and the current frame number, making each sample statistically independent without requiring any global state or atomic operations across threads.

---

## Optimizations

### Ray caching

The direction of every camera ray is fixed for a given camera pose. These directions are pre-computed once into a flat array of `WIDTH × HEIGHT` rays (`cache_ray`) when the program starts or when the camera moves. During rendering, each pixel simply reads its pre-computed ray from the cache instead of recomputing the view transform and pixel-to-world projection every frame. This is particularly beneficial in path tracing where the same ray is reused across hundreds of accumulation frames.

A jittered variant (`cache_fuzzy_ray`) applies a sub-pixel random offset per frame, providing free anti-aliasing in path tracing mode.

### Accumulation buffer

Instead of storing a full HDR framebuffer and re-rendering it every frame, the accumulation buffer holds a running sum of all samples. Each frame, the new sample is added to the sum and the average is computed per pixel in a single pass. This avoids any per-frame memory allocation and keeps the per-pixel work minimal.

### Multithreading with zero synchronization

The screen-space band decomposition means each thread owns exclusive rows of the accumulation buffer and image. There are no shared mutable data structures, no mutexes, and no atomic operations — threads run entirely independently and are simply joined at the end of each frame.

### Vector types via GCC extensions

The tuple type uses `__attribute__((vector_size(16)))` to expose 4-wide double-precision SIMD vectors (`v4`) to the compiler. This allows GCC/Clang to auto-vectorize inner loops over color and vector arithmetic (dot products, additions, scalar multiplies) using AVX or SSE2 instructions where available.

### Camera-space normal transform shortcut

The normal transform `N' = (M⁻¹)ᵀ · N` is computed by storing the **inverse** transform on the shape (not the forward transform) and using `matrix_transpose` at intersection time, avoiding a matrix inversion per ray.

---

## Project structure

```
.
├── include/         # All header files
├── src/
│   ├── camera/      # Camera setup and view transform
│   ├── colors/      # Color utilities
│   ├── light/       # Blinn-Phong shading, shadow testing
│   ├── math/        # Tuples, vectors, 4×4 matrices, random, interpolation
│   ├── mlx/         # MiniLibX wrapper, event loop, pixel write
│   ├── parsing/     # .rt scene file parser
│   ├── pattern/     # Procedural patterns, UV mapping, texture loading
│   ├── ray/         # Ray construction, cache, reflection, refraction, Schlick
│   ├── render/      # Ray tracer, path tracer, multithreaded path tracer
│   ├── shapes/      # Sphere, plane, cylinder, cone, cube, triangle, materials
│   └── world/       # World intersection, pre-compute, n1/n2 containers
├── scenes/          # Example .rt scene files
├── xpm/             # Texture assets
├── libft/           # Bundled custom libc
└── mlx_linux/       # MiniLibX (fetched at build time)
```

---

## Reference

- *The Ray Tracer Challenge* — Jamis Buck (primary algorithm reference)
