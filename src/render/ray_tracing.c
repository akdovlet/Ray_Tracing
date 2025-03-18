/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:43:11 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 12:29:18 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ray_tracing(t_data *data)
{
	int		y;
	int		x;
	t_tuple	color;

	y = 0;
	if (data->moved)
	{
		cam_update(&data->cam, data->cam.from,
			data->cam.to,
			data->cam.up);
		cache_ray(data->rays, &data->cam);
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = color_at(&data->world, data->rays[x + y * WIDTH], 5);
			ak_mlx_pixel_put(&data->img, x, y, tuple_tocolor(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->img.img_ptr, 0, 0);
	return (0);
}
