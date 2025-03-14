/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:22:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/14 11:45:09 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shapes.h"

void	rand_cache_ray(t_ray *ray, t_camera *cam, uint32_t seed);

void	path_tracing(t_data *data)
{
	int		y;
	int		x;
	t_tuple	color;
	t_tuple	final_color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			color = trace_rays(&data->world, data->rays[x + y * WIDTH], (x + y
						* WIDTH) * data->frame_index, data->frame_index);
			if (data->frame_index == 1)
				data->accumulation[x + y * WIDTH] = color;
			else
				data->accumulation[x + y
					* WIDTH] = tuple_add(data->accumulation[x + y * WIDTH],
						color);
			final_color = data->accumulation[x + y * WIDTH];
			final_color = tuple_divide(final_color, data->frame_index);
			ak_mlx_pixel_put(&data->img, x, y, tuple_tocolor(final_color));
		}
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->img.img_ptr, 0, 0);
}

void	rand_pixel(t_camera *cam, t_ray *ray, double x, double y, uint32_t seed)
{
	double	world_y;
	double	world_x;
	t_tuple	pixel;

	world_x = cam->half_width - ((x + 0.5) * cam->psize);
	world_y = cam->half_height - ((y + 0.5) * cam->psize);
	pixel = matrix_multiply_tuple(cam->transform, point_new(world_x
				+ random_range(&seed, 0, 0.5), world_y + random_range(&seed, 0,
					0.5), -1));
	ray->direction = tuple_normalize(tuple_substract(pixel, ray->origin));
}

void	rand_cache_ray(t_ray *ray, t_camera *cam, uint32_t seed)
{
	int		y;
	int		x;
	t_tuple	origin;

	y = 0;
	origin = matrix_multiply_tuple(cam->transform, point_new(0, 0, 0));
	while (y < HEIGHT)
	{
		x = 0;
		seed += y;
		while (x < WIDTH)
		{
			ray[x + y * WIDTH].origin = origin;
			rand_pixel(cam, &ray[x + y * WIDTH], x, y, seed);
			x++;
		}
		y++;
	}
}

int	render_accumulation(t_data *data)
{
	clock_t	start;
	clock_t	end;
	double	cpu_time;

	start = clock();
	if (data->moved)
	{
		data->skip = 5;
		data->frame_index = 1;
		cam_update(&data->cam, data->cam.from, data->cam.to, data->cam.up);
		cache_ray(data->rays, &data->cam);
		data->moved = false;
	}
	path_tracing(data);
	end = clock();
	cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
	data->ts = cpu_time;
	printf("\rframe %d time: %.f ms", data->frame_index, data->ts * 1000);
	fflush(stdout);
	data->frame_index++;
	return (0);
}
