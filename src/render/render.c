/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:22:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/21 16:33:44 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"
#include "objects.h"

t_ray	ray_for_pixel(t_camera cam, double x, double y)
{
	double	world_y;
	double	world_x;
	t_tuple	pixel;
	t_ray	ray;

	world_x = cam.half_width - ((x + 0.5) * cam.psize);
	world_y = cam.half_height - ((y + 0.5) * cam.psize);
	pixel = matrix_multiply_tuple(cam.transform, point_new(world_x, world_y, -1));
	ray.origin = matrix_multiply_tuple(cam.transform, point_new(0, 0, 0));
	ray.direction = tuple_normalize(tuple_substract(pixel, ray.origin));
	return (ray);
}

void	render(t_camera cam, t_world world, t_img *img, t_mlx *mlx)
{
	int	y;
	int	x;
	t_ray	ray;
	t_tuple	color;

	y = 0;
	while (y < cam.vsize)
	{
		x = 0;
		while (x < cam.hsize)
		{
			ray = ray_for_pixel(cam, x, y);
			color = color_at(world, ray, 10);
			ak_mlx_pixel_put(img, x, y, tuple_tocolor(color));
			x++;
		}
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
		y++;
	}
}

int	render_and_move(t_data *data)
{
	int		y;
	int		x;
	t_ray	ray;
	t_tuple	color;

	y = 0;
	camera_update_transform(&data->cam, data->cam.from,
									data->cam.to,
									data->cam.up);
	while (y < data->cam.vsize)
	{
		x = 0;
		while (x < data->cam.hsize)
		{
			ray = ray_for_pixel(data->cam, x, y);
			color = color_at(data->world, ray, 10);
			ak_mlx_pixel_put(&data->img, x, y, tuple_tocolor(color));
			x++;
		}
		y++;
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->img.img_ptr, 0, 0);
	}
	return (0);
}
