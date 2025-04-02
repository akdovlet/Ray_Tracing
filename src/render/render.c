/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:22:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 21:29:35 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shapes.h"

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
		cam_update(&data->world.cam, data->world.cam.from, data->world.cam.to, data->world.cam.up);
		cache_ray(data->rays, &data->world.cam);
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
