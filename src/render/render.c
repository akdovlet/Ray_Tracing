/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:22:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/14 14:27:50 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shapes.h"

void	ray_for_pixel(t_camera *cam, t_ray *ray, double x, double y)
{
	double	world_y;
	double	world_x;
	v4	pixel;

	world_x = cam->half_width - ((x + 0.5) * cam->psize);
	world_y = cam->half_height - ((y + 0.5) * cam->psize);
	pixel = matrix_multiply_tuple(cam->transform, point_new(world_x, world_y, -1.0));
	// ray->origin = point_new(0, 0, 0);
	ray->origin = matrix_multiply_tuple(cam->transform, (v4){0.0, 0.0, 0.0, 1.0});
	ray->direction = v4_normalize(pixel - ray->origin);
}

void	cache_ray(t_ray *ray, t_camera *cam)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
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

void	 render(t_camera cam, t_world world, t_img *img, t_mlx *mlx)
{
	int	y;
	int	x;
	t_ray	*ray;
	v4	color;

	y = 0;
	ray = aligned_alloc(sizeof(t_ray), sizeof(t_ray) * (HEIGHT * WIDTH));
	if (!ray)
		return ;
	cache_ray(ray, &cam);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = color_at(&world, ray[x + y * WIDTH], 10);
			ak_mlx_pixel_put(img, x, y, tuple_tocolor(color));
			x++;
		}
		y++;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
	}
	free(ray);
}

void	path_tracing(t_ray *ray, t_camera cam, t_world world, t_img *img, t_mlx *mlx, double frame_index, v4 *accumulation)
{
	int				y;
	int				x;
	v4				color;
	v4				final_color;

	y = 0;
	(void)cam;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = bounce_rays(&world, ray[x + y * WIDTH], (x + y * WIDTH) * frame_index);
			accumulation[x + y * WIDTH] += color;
			final_color = accumulation[x + y * WIDTH] / frame_index;
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
	v4					*accumulation;
	t_ray				*ray;

	frame_index = 1;
	ray = aligned_alloc(sizeof(t_ray), sizeof(t_ray) * (WIDTH * HEIGHT));
	accumulation = aligned_alloc(sizeof(v4), sizeof(v4) * (WIDTH * HEIGHT));
	if (!accumulation || !ray)
		return ;
	// ft_memset(accumulation, 0, sizeof(v4) * (WIDTH * HEIGHT));
	cache_ray(ray, &cam);
	while (frame_index)
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
	v4	color;

	y = 0;
	camera_update_transform(&data->cam, data->cam.from,
									data->cam.to,
									data->cam.up);
	ray = malloc(sizeof(t_ray) * (WIDTH * HEIGHT));
	if (!ray)
		return (1);
	cache_ray(ray, &data->cam);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
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

