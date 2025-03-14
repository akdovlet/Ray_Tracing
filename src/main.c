/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/14 16:07:11 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "test.h"

int	main(int ac, char **av)
{
	// t_img	img;
	// t_mlx	mlx;
	// t_data	data;

	// init_mlx(&mlx, &img);
	// (void)ac;
	// (void)av;
	// data = scene_spherical_pattern(&mlx);
	// data = scene_single_sphere();
	// data.img = img;
	// data.mlx = mlx;
	// data.frame_index = 1;
	// data.ts_last = 0;
	// data.moved = false;
	if (ac > 1)
	{
		test_atof(av[1]);
		test_parsing(av[1]);
	}
	// data.accumulation = malloc(sizeof(t_tuple) * WIDTH * HEIGHT);
	// data.rays = malloc(sizeof(t_ray) * WIDTH * HEIGHT);
	// cache_ray(data.rays, &data.cam);
	// mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);
	// mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &key_manager, &data);
	// mlx_loop_hook(mlx.mlx_ptr, &render_accumulation, &data);
	// mlx_loop(mlx.mlx_ptr);
	// mlx_clear(&mlx, &img);
	// free(data.rays);
	// free(data.accumulation);
	return (0);
}

int	setup_data(char **av, t_data *data, t_mlx *mlx, t_img *img)
{
	(void)av;
	*data = (t_data){};
	data->img = *img;
	data->mlx = *mlx;
	data->frame_index = 1;
	data->rays = malloc(sizeof(t_ray) * WIDTH * HEIGHT);
	if (!data->rays)
		return (1);
	data->accumulation = malloc(sizeof(t_tuple) * WIDTH * HEIGHT);
	if (!data->accumulation)
		return (free(data->rays), 1);
	cache_ray(data->rays, &data->cam);
	return (0);
}

int	main_two(int ac, char **av)
{
	t_img	img;
	t_mlx	mlx;
	t_data	data;

	if (ac <= 1)
		return (1);
	init_mlx(&mlx, &img);
	// data = scene_complex();
	if (setup_data(av, &data, &mlx, &img))
		return (1);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &key_manager, &data);
	mlx_loop_hook(mlx.mlx_ptr, &render_accumulation, &data);
	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
	free(data.rays);
	free(data.accumulation);
	return (0);
}
