#ifndef GRAPHICS_H
#define GRAPHICS_H

# include "data_struct.h"

typedef struct s_env t_env;

#define RAYLIB

#ifdef RAYLIB
#include "raylib.h"

typedef Color t_color;
typedef Image t_img;

struct s_env {
	int width;
	int height;
	const char* title;
	t_camera	camera;
	t_world		world;

    t_img  image;
};

#elif
#include "X11/keysym.h"
#include "mlx.h"

typedef	union u_color			t_color;
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

void	put_pixel(int dx, int dy, t_color color);

typedef void(*t_fn_render)(t_camera*, t_world*);
void	loop(t_env *env, t_fn_render render);

#endif // GRAPHICS_H

