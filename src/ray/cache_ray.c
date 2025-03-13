/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:36:39 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 18:11:04 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_for_pixel(t_camera *cam, t_ray *ray, double x, double y)
{
	double	world_y;
	double	world_x;
	t_tuple	pixel;

	world_x = cam->half_width - ((x + 0.5) * cam->psize);
	world_y = cam->half_height - ((y + 0.5) * cam->psize);
	pixel = matrix_multiply_tuple(cam->transform, point_new(world_x, world_y,
				-1));
	ray->direction = tuple_normalize(tuple_substract(pixel, ray->origin));
}

void	cache_ray(t_ray *ray, t_camera *cam)
{
	int		y;
	int		x;
	t_tuple	origin;

	y = 0;
	origin = matrix_multiply_tuple(cam->transform, point_new(0, 0, 0));
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray[x + y * WIDTH].origin = origin;
			ray_for_pixel(cam, &ray[x + y * WIDTH], x, y);
			x++;
		}
		y++;
	}
}
