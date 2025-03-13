/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:27:50 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 16:29:05 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int main(int ac, char **av)
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
