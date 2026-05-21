/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:00:00 by akdovlet          #+#    #+#             */
/*   Updated: 2026/05/20 12:05:43 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shapes.h"

static void	*render_band(void *arg)
{
	t_thread_arg	*ta;
	t_data			*data;
	t_tuple			color;
	t_tuple			final_color;
	int				x;
	int				y;

	ta = arg;
	data = ta->data;
	y = ta->y_start - 1;
	while (++y < ta->y_end)
	{
		x = -1;
		while (++x < WIDTH)
		{
			color = trace_rays(&data->world, data->rays[x + y * WIDTH],
					(x + y * WIDTH) * data->frame_index, data->frame_index);
			if (data->frame_index == 1)
				data->accumulation[x + y * WIDTH] = color;
			else
				data->accumulation[x + y * WIDTH] = tuple_add(
						data->accumulation[x + y * WIDTH], color);
			final_color = tuple_divide(data->accumulation[x + y * WIDTH],
					data->frame_index);
			ak_mlx_pixel_put(&data->img, x, y, tuple_tocolor(final_color));
		}
	}
	return (NULL);
}

static void	path_tracing_mt(t_data *data)
{
	pthread_t		threads[THREADS];
	t_thread_arg	args[THREADS];
	int				band;
	int				i;

	band = HEIGHT / THREADS;
	i = -1;
	while (++i < THREADS)
	{
		args[i].data = data;
		args[i].y_start = i * band;
		args[i].y_end = (i == THREADS - 1) ? HEIGHT : (i + 1) * band;
		pthread_create(&threads[i], NULL, render_band, &args[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->img.img_ptr, 0, 0);
}

int	render_accumulation_mt(t_data *data)
{
	clock_t	start;
	clock_t	end;

	start = clock();
	if (data->moved)
	{
		data->frame_index = 1;
		cam_update(&data->world.cam, data->world.cam.from,
			data->world.cam.to, data->world.cam.up);
		cache_ray(data->rays, &data->world.cam);
		data->moved = false;
	}
	path_tracing_mt(data);
	end = clock();
	data->ts = ((double)(end - start)) / CLOCKS_PER_SEC;
	// printf("\rframe %d time: %.f ms  [%d threads]",
		// data->frame_index, data->ts * 1000, THREADS);
	fflush(stdout);
	data->frame_index++;
	return (0);
}
