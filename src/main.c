/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbekheir <mbekheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/01 16:50:32 by mbekheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "test.h"
#include "tuple.h"
#include <X11/X.h>

int main(int ac, char **av)
{
	t_img	img;
	t_mlx	mlx;
	t_data data;
	t_data_file data_file;

	if (ac != 2)
		return (printf("Error:\nargs\n"));

	if (_data_set(&data_file, av[1]))
		return (_data_unset(&data.data_file), printf("Error:\nParsing failed\n"), 1);


	init_mlx(&mlx, &img);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);

	
	data = scene_cylinder();
	data.img = img;
	data.mlx = mlx;
	data.frame_index = 1;
	data.ts_last = 0;
	data.moved = false;
	data.accumulation = malloc(sizeof(t_tuple) * WIDTH * HEIGHT);
	data.rays = malloc(sizeof(t_ray) * WIDTH * HEIGHT);
	cache_ray(data.rays, &data.cam);
	mlx_mouse_hook(mlx.win_ptr, &mouse_manager, &data);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &key_manager, &data);
	// mlx_key_hook(mlx.win_ptr, &key_manager, &data);
	// render(data.cam, data.world, &img, &mlx);
	// mlx_loop_hook(mlx.mlx_ptr, &render_and_move, &data);
	// test_cylinder_intersect();
	// test_cylinder_normalat();
	test_truncated_cylinder();
	test_capped_cylinder();
	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
	free(data.rays);
	free(data.accumulation);
	_data_unset(&data_file);
	printf("AK out!\n");
	return (0);
}
