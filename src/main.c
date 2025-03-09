/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/09 18:11:28 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "test.h"
#include "tuple.h"
#include <X11/X.h>

void	print_image(char *file)
{
	char	*buff;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd <0)
		return ;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		printf("%s", buff);
		free(buff);
	}
}

int main(int ac, char **av)
{
	t_img	img;
	t_mlx	mlx;
	t_data	data;

	init_mlx(&mlx, &img);
	
	// data = scene_spherical_pattern(&mlx);
	data = scene_walled();
	data.img = img;
	data.mlx = mlx;
	data.frame_index = 1;
	data.ts_last = 0;
	data.moved = false;
	data.accumulation = malloc(sizeof(t_tuple) * WIDTH * HEIGHT);
	data.rays = malloc(sizeof(t_ray) * WIDTH * HEIGHT);
	cache_ray(data.rays, &data.cam);

	if (ac > 1)
		print_image(av[1]);
	mlx_mouse_hook(mlx.win_ptr, &mouse_manager, &data);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &key_manager, &data);
	mlx_loop_hook(mlx.mlx_ptr, &render_accumulation, &data);
	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
	
	free(data.rays);
	free(data.accumulation);
	return (0);
}
