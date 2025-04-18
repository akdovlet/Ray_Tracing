/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/18 14:33:53 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "test.h"

void	free_data(t_data *data)
{
	free(data->accumulation);
	free(data->rays);
	free(data->world.obj);
	free(data->world.light);
}

int	setup_data(char **av, t_data *data)
{
	*data = (t_data){};
	data->frame_index = 1;
	if (build_world(av[1], &data->world))
		return (1);
	if (init_mlx(&data->mlx, &data->img))
		return (ft_dprintf(2, "Error: failed mlx initialization\n"), 1);
	data->rays = malloc(sizeof(t_ray) * WIDTH * HEIGHT);
	if (!data->rays)
	{
		mlx_clear(&data->mlx, &data->img);
		ft_dprintf(2, "Error: setup_data: rays: %s", strerror(errno));
		return (1);
	}
	data->accumulation = malloc(sizeof(t_tuple) * WIDTH * HEIGHT);
	if (!data->accumulation)
	{
		mlx_clear(&data->mlx, &data->img);
		ft_dprintf(2, "Error: setup_data: accumulation: %s", strerror(errno));
		free_data(data);
		return (1);
	}
	cache_ray(data->rays, &data->world.cam);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		return (ft_dprintf(2, "Error: missing scene file\n"), 1);
	if (setup_data(av, &data))
		return (1);
	mlx_hook(data.mlx.win_ptr, 17, 0, mlx_loop_end, data.mlx.mlx_ptr);
	mlx_hook(data.mlx.win_ptr, KeyPress, KeyPressMask, &key_manager, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, &ray_tracing, &data);
	mlx_loop(data.mlx.mlx_ptr);
	mlx_clear(&data.mlx, &data.img);
	free_data(&data);
	return (0);
}
