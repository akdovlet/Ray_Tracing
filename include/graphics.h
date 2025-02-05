#ifndef GRAPHICS_H
#define GRAPHICS_H

# include "data_struct.h"
# include "quadtree.h"

typedef struct s_env t_env;

#define RAYLIB

#ifdef RAYLIB
#include "raylib.h"

typedef Color t_color;
typedef Image t_img;

struct s_env {
	int			width;
	int			height;
	const char* title;
	t_camera	camera;
	t_world		world;
	t_quadtree_node* quadtree;

	t_ray*		precomputed_ray;

    t_img  image;
};

# else

#include "X11/keysym.h"
#include "mlx.h"

typedef	union u_color	t_color;
union	u_color
{
	unsigned char	bytes[4];
	unsigned int	color;
};

struct s_color {
    unsigned int color;
};

struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_env {
	int width;
	int height;
	const char* title;
	t_camera	camera;
	t_world		world;

    t_img   image;
	void	*mlx_ptr;
	void	*win_ptr;
};

#endif

int     init_env(t_env *env);
void	put_pixel_to_image(t_img *image, int dx, int dy, t_color color);
int     put_image_to_window(t_env *env, t_img img, int x,int y);
void    destroy_env(t_env* env);

t_color	tuple_tocolor(t_tuple tcolor);
t_tuple	color_new(float red, float green, float blue);

// t_color	color_new(float red, float green, float blue);

void	put_pixel(t_vec2i pixel_position, t_color color);
void	put_circle(t_vec2i position, int radius, t_color color); //will be removed
void	put_rectangle(t_vec2i pos, t_vec2i size, t_color color); //will be removed
void	put_rectangle_line(t_vec2i pos, t_vec2i size, t_color color); //will be removed



void	loop(t_env *env);

#endif // GRAPHICS_H

