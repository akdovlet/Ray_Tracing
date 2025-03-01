/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/01 17:00:58 by akdovlet         ###   ########.fr       */
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
	t_data data;

	init_mlx(&mlx, &img);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);
	data = scene_complex();
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
	mlx_loop_hook(mlx.mlx_ptr, &render_and_move, &data);
	// test_cylinder_intersect();
	// test_cylinder_normalat();
	test_truncated_cylinder();
	test_capped_cylinder();
	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
	free(data.rays);
	free(data.accumulation);
	printf("AK out!\n");
	return (0);
}
