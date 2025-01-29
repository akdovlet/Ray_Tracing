/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/29 18:24:27 by akdovlet         ###   ########.fr       */
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
	test_refraction();
	test_cylinder_intersect();
	test_cube();
	test_cube_normalat();
	data = cube_scene(&img, &mlx);
	data.img = img;
	data.mlx = mlx;
	render(data.cam, data.world, &img, &mlx);
	mlx_key_hook(mlx.win_ptr, &key_manager, &data);
	mlx_mouse_hook(mlx.win_ptr, &mouse_manager, &data);
	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
	printf("AK out!\n");
	return (0);
}
