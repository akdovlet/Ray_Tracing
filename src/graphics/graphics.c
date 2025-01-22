#include "graphics.h"
#include "minirt.h"
#include <math.h>
#include <stddef.h>

#include <stdio.h>

static t_env* static_env(t_env* env)
{
	static t_env* local_env = NULL;

	if (env != NULL)
		local_env = env;
	return (local_env);
}

void	put_pixel(t_vec2i pixel_position, t_color color)
{
	t_env*	env;

	env = static_env(NULL);
	put_pixel_to_image(&env->image, pixel_position.x, pixel_position.y, color);
}

void put_circle(t_vec2i position, int radius, t_color color)
{
	t_env*	env;

	env = static_env(NULL);
	ImageDrawCircle(&env->image, position.x, position.y, radius, color);
}

void put_rectangle(t_vec2i pos, t_vec2i size, t_color color)
{
	t_env*	env;

	env = static_env(NULL);
	ImageDrawRectangle(&env->image, pos.x, pos.y, size.x, size.y, color);
}

void put_rectangle_line(t_vec2i pos, t_vec2i size, t_color color)
{
	t_env*	env;
	Rectangle rec;

	env = static_env(NULL);
	rec = (Rectangle){
		.x = pos.x, .y = pos.y,
		.width = size.x, .height = size.y,
	};
	ImageDrawRectangleLines(&env->image, rec, 1, color);
}



#ifdef RAYLIB

 int	new_image(t_img* img, t_env* env, int width, int height)
{
	(void)env;
    (*img) = GenImageColor(width, height, BLACK);
    return (0);
}

int init_env(t_env *env)
{
    InitWindow(env->width, env->height, env->title);
    return (new_image(&env->image, env, env->width, env->height));
}

void	put_pixel_to_image(t_img *image, int dx, int dy, t_color color)
{
    ImageDrawPixel(image, dx, dy, color);
}

int     put_image_to_window(t_env *env, t_img img, int x, int y)
{
	(void)env;
    Texture2D texture = LoadTextureFromImage(img);
    DrawTexture(
        texture,
        x, //screenWidth/2 - texture.width/2,
        y, //screenHeight/2 - texture.height/2 - 40,
        WHITE);
	return (0);
}

void    destroy_env(t_env* env)
{
	UnloadImage(env->image);
    CloseWindow();
}

static int render_once = 1;
void	loop(t_env *env)
{
	init_env(env);
	static_env(env);

    Texture2D texture = LoadTextureFromImage(env->image);
    // SetTargetFPS(1);
    while (!WindowShouldClose())
    {
		if (render_once){
			render(env);
			Color *pixels = LoadImageColors(env->image);

			UpdateTexture(texture, pixels);
			UnloadImageColors(pixels);
			render_once = 0;
		}
        BeginDrawing();
            DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();
    }
    UnloadTexture(texture);
	destroy_env(env);
}

t_color	tuple_tocolor(t_tuple tcolor)
{
	t_color	color;

	color.b = fmin(roundf(tcolor.x * 255), 255);
	color.g = fmin(roundf(tcolor.y * 255), 255);
	color.r = fmin(roundf(tcolor.z * 255), 255);
	color.a = 255;
	return (color);
}

t_tuple	color_new(float red, float green, float blue)
{
	t_tuple	new;

	new.x = red;
	new.y = green;
	new.z = blue;
	new.w = 0;
	return (new);
}

// t_color	color_new(float red, float green, float blue)
// {
// 	return ((t_color){red, green, blue, 255});
// }

#elif

static int	new_image(t_img* img, t_env* env, int width, int height)
{
	img->img_ptr = mlx_new_image(env->mlx_ptr, width, height);
	if (!img->img_ptr)
		return (1);
	img->addr = mlx_get_data_addr(
        img->img_ptr,
        &img->bits_per_pixel,
		&img->line_length,
        &img->endian
    );
	if (!img->addr)
		return (1);
    return (0);
}

static int	key_manager(int keysym, void* mlx_ptr)
{
	if (keysym == XK_Escape)
		mlx_loop_end(mlx_ptr);
	return (0);
}

int init_env(t_env *env, int width, int height, const char* title)
{
    env->mlx_ptr = mlx_init();
	if (!env->mlx_ptr)
		return (1);
	env->win_ptr = mlx_new_window(env->mlx_ptr, widht, height, title);
	if (!env->win_ptr)
		return (1);

    if (new_image(&env->image, env, width, height))
        return (1);
    mlx_key_hook(env->win_ptr, &key_manager, env->mlx_ptr);
	mlx_hook(env->win_ptr, 17, 0, mlx_loop_end, env->mlx_ptr);
    return (0);
}

void	put_pixel_to_image(t_img *image, int dx, int dy, t_color color)
{
	char	*dst;

	// if (!is_within_bounds(dx, dy))
	// 	return ;
    img = env->image
    dst = img->addr;
    dst += (dy * img->line_length + dx * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int     put_image_to_window(t_env *env, t_img img, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img_ptr, x, y);
}

void    destroy_env(t_env* env)
{
    mlx_destroy_image(env->mlx_ptr, env->img->img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	mlx_destroy_display(env->mlx_ptr);
	free(env->mlx_ptr);
}

void	loop(t_fn_render render)
{
	t_env	env;
	init_env(&env, WIDTH, HEIGHT, "minirt");
	mlx_loop(mlx.mlx_ptr);

	destroy_env(&env);
}

t_color	tuple_tocolor(t_tuple tcolor)
{
	t_color	color;

	color.bytes[2] = fmin(roundf(tcolor.x * 255), 255);
	color.bytes[1] = fmin(roundf(tcolor.y * 255), 255);
	color.bytes[0] = fmin(roundf(tcolor.z * 255), 255);
	color.bytes[3] = 0;
	return (color);
}

t_color	color_new(float red, float green, float blue)
{
	return ((t_color){{blue, green, red, 0}});
}

#endif