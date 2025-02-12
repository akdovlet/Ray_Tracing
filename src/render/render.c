/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:22:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/12 20:03:52 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shapes.h"

int g_i = 0;

void	ray_for_pixel(t_camera *cam, t_ray *ray, double x, double y)
{
	double	world_y;
	double	world_x;
	v4	pixel;

	world_x = cam->half_width - ((x + 0.5) * cam->psize);
	world_y = cam->half_height - ((y + 0.5) * cam->psize);
	pixel = matrix_multiply_tuple(cam->transform, point_new(world_x, world_y, -1.0));
	printf("here\n");
	ray->origin = matrix_multiply_tuple(cam->transform, (v4){0.0, 0.0, 0.0, 1.0});
	printf("here2\n");
	ray->direction = v4_normalize(pixel - ray->origin);
	printf("her3\n");
	g_i++;
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

void	 render(t_camera cam, t_world world, t_img *img, t_mlx *mlx)
{
	int	y;
	int	x;
	t_ray	*ray;
	v4	color;

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

void	path_tracing(t_ray *ray, t_camera cam, t_world world, t_img *img, t_mlx *mlx, double frame_index, unsigned int *accumulation)
{
	int				y;
	int				x;
	v4				color;
	unsigned int	final_color;

	y = 0;
	while (y < cam.vsize)
	{
		x = 0;
		while (x < cam.hsize)
		{
			color = bounce_rays(&world, ray[x + y * WIDTH], (x + y * WIDTH) * frame_index);
			accumulation[x + y * WIDTH] += tuple_tocolor(color);
			final_color = accumulation[x + y * WIDTH] / frame_index;
			ak_mlx_pixel_put(img, x, y, final_color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
}

void	render_accumulation(t_camera cam, t_world world, t_img *img, t_mlx *mlx)
{
	double				frame_index;
	unsigned int		*accumulation;
	t_ray				*ray;

	frame_index = 1;
	ray = malloc(sizeof(t_ray) * (WIDTH * HEIGHT));
	accumulation = malloc(sizeof(unsigned int) * (WIDTH * HEIGHT));
	if (!accumulation || !ray)
		return ;
	ft_memset(accumulation, 0, sizeof(unsigned int) * (WIDTH * HEIGHT));
	cache_ray(ray, &cam);
		path_tracing(ray, cam, world, img, mlx, frame_index, accumulation);
		frame_index++;
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

