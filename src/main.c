/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/26 19:00:29 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "test.h"
#include "tuple.h"

int main()
{
	t_img	img;
	t_mlx	mlx;
	t_data data;
	int		i;

	i = 1;
	init_mlx(&mlx, &img);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);
	test_cube();
	test_cube_normalat();
	data = cube_scene(&img, &mlx);
	data.img = img;
	data.mlx = mlx;
	render(data.cam, data.world, &img, &mlx);
	mlx_key_hook(mlx.win_ptr, &key_manager, &data);
	// sleep(5);
	// data = watchful_eye_scene(&img, &mlx);
	// render(data.cam, data.world, &img, &mlx);
	// test_negative_intersection();
	mlx_mouse_hook(mlx.win_ptr, &mouse_manager, &data);
	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
	printf("AK out!\n");
	return (0);
}
