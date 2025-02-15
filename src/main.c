/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/15 19:38:46 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "test.h"
#include "tuple.h"
#include <X11/X.h>

int main()
{
	t_img	img;
	t_mlx	mlx;
	t_data data[4];
	t_ray	*ray_cache;
	pthread_t	threads[4];
	int			job_start;
	pthread_mutex_t	img_mutex;

	init_mlx(&mlx, &img);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);
	job_start = 0;
	ray_cache = malloc(sizeof(t_ray) * (HEIGHT * WIDTH));
	pthread_mutex_init(&img_mutex, NULL);
	for (size_t i = 0; i < 4; i++)
	{
		data[i] = scene_complex();
		if (i == 0)
			cache_ray(ray_cache, &data->cam);
		data[i].img = img;
		data[i].img_mutex = &img_mutex;
		data[i].mlx = mlx;
		data[i].cache = ray_cache;
		data[i].job_start = job_start;
		data[i].job_end = job_start + (HEIGHT / 4);
		pthread_create(&threads[i], NULL, &render_threads, &data[i]);
		job_start += (HEIGHT / 4);
	}
	mlx_mouse_hook(mlx.win_ptr, &mouse_manager, &data);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &key_manager, &data);
	// mlx_key_hook(mlx.win_ptr, &key_manager, &data);
	// render_accumulation(data.cam, data.world, &img, &mlx);
	for(size_t i = 0; i < 4; i++)
	{
		pthread_join(threads[i], NULL);
	}
	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
	printf("AK out!\n");
	return (0);
}
