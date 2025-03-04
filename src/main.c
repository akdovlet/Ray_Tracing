/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/04 15:40:11 by akdovlet         ###   ########.fr       */
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
	data = scene_triangle();
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
	// test_capped_cylinder();
	// test_cylinder_normal_at_caps();
	// test_cylinder_normalat();
	// test_cone_intersect();
	// test_triangle_normal();
	test_triangle_intersect();
	mlx_loop_hook(mlx.mlx_ptr, &render_accumulation, &data);
	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
	free(data.rays);
	free(data.accumulation);
	return (0);
}
