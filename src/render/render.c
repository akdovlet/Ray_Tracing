/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:22:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/21 16:52:16 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shapes.h"

void	ray_for_pixel(t_camera *cam, t_ray *ray, double x, double y)
{
	double	world_y;
	double	world_x;
	t_tuple	pixel;

	world_x = cam->half_width - ((x + 0.5) * cam->psize);
	world_y = cam->half_height - ((y + 0.5) * cam->psize);
	pixel = matrix_multiply_tuple(cam->transform, point_new(world_x, world_y, -1));
	ray->origin = matrix_multiply_tuple(cam->transform, point_new(0, 0, 0));
	ray->direction = tuple_normalize(tuple_substract(pixel, ray->origin));
}

void	cache_ray(t_ray *ray, t_camera *cam)
{
	int	y;
	int	x;

	y = 0;
	while (y < cam->vsize)
	{
		x = 0;
		while (x < cam->hsize)
		{
			ray_for_pixel(cam, &ray[x + y * cam->hsize], x, y);
			x++;
		}
		y++;
	}
}

void	cache_ray_threads(t_ray *ray, t_camera *cam, int y, int max)
{
	int	x;

	printf("y is: %d, max is: %d\n", y, max);
	while (y < max)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray_for_pixel(cam, &ray[x + y * WIDTH], x, y);
			x++;
		}
		y++;
	}
}

void	*render_threads(void *stuff)
{
	int	y;
	int	x;
	t_tuple	color;
	t_data *data;

	data = (t_data *) stuff;
	y = data->job_start;
	while (y < data->job_end)
	{
		x = 0;
		while (x < HEIGHT)
		{
			color = color_at(&data->world, data->cache[x + y * HEIGHT], 10);
			ak_mlx_pixel_put(&data->img, x, y, tuple_tocolor(color));
			x++;
		}
		y++;
	}
	// pthread_mutex_lock(data->img_mutex);
	// mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->img.img_ptr, 0, 0);
	// pthread_mutex_unlock(data->img_mutex);
	return (NULL);
}

void	render(t_camera cam, t_world world, t_img *img, t_mlx *mlx)
{
	int	y;
	int	x;
	t_ray	*ray;
	t_tuple	color;

	y = 0;
	ray = malloc(sizeof(t_ray) * (cam.vsize * cam.hsize));
	if (!ray)
		return ;
	cache_ray(ray, &cam);
	while (y < cam.vsize)
	{
		x = 0;
		while (x < cam.hsize)
		{
			color = color_at(&world, ray[x + y * cam.hsize], 10);
			ak_mlx_pixel_put(img, x, y, tuple_tocolor(color));
			x++;
		}
		y++;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
	}
	free(ray);
}

t_tuple clamp_color(t_tuple tcolor)
{
	t_tuple	color;
	double		r;
	double		g;
	double		b;

	r = fmin(tcolor.x, 1.0);
	r = fmax(r, 0.0);
	g = fmin(tcolor.y, 1.0);
	g = fmax(g, 0.0);
	b = fmin(tcolor.z, 1.0);
	b = fmax(b, 0.0);
	color.x = r;
	color.y = g;
	color.z = b;
	color.w = 0;
	return (color);
}

void	path_tracing(t_ray *ray, t_camera cam, t_world world, t_img *img, t_mlx *mlx, double frame_index,t_tuple *accumulation)
{
	int		y;
	int		x;
	t_tuple	color;
	t_tuple	final_color;

	y = 0;
	while (y < cam.vsize)
	{
		x = 0;
		while (x < cam.hsize)
		{
			color = trace_rays(&world, ray[x + y * WIDTH], (x + y * WIDTH) * frame_index);
			accumulation[x + y * WIDTH] = tuple_add(accumulation[x + y * WIDTH], color);
			final_color = accumulation[x + y * WIDTH];
			final_color = tuple_divide(final_color, frame_index);
			ak_mlx_pixel_put(img, x, y, tuple_tocolor(final_color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
}

void	render_accumulation(t_camera cam, t_world world, t_img *img, t_mlx *mlx)
{
	double				frame_index;
	t_tuple				*accumulation;
	t_ray				*ray;

	frame_index = 1;
	ray = malloc(sizeof(t_ray) * (WIDTH * HEIGHT));
	accumulation = malloc(sizeof(t_tuple) * (WIDTH * HEIGHT));
	if (!accumulation || !ray)
		return ;
	ft_memset(accumulation, 0, sizeof(accumulation) * (WIDTH * HEIGHT));
	cache_ray(ray, &cam);
	while (1)
	{
		path_tracing(ray, cam, world, img, mlx, frame_index, accumulation);
		frame_index++;
	}
	free(ray);
	free(accumulation);
}

int	render_and_move(t_data *data)
{
	int		y;
	int		x;
	t_ray	*ray;
	t_tuple	color;

	y = 0;
	camera_update_transform(&data->cam, data->cam.from,
									data->cam.to,
									data->cam.up);
	ray = malloc(sizeof(t_ray) * (WIDTH * HEIGHT));
	if (!ray)
		return (1);
	cache_ray(ray, &data->cam);
	while (y < data->cam.vsize)
	{
		x = 0;
		while (x < data->cam.hsize)
		{
			color = color_at(&data->world, ray[x + y * WIDTH], 10);
			ak_mlx_pixel_put(&data->img, x, y, tuple_tocolor(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->img.img_ptr, 0, 0);
	free(ray);
	return (0);
}

