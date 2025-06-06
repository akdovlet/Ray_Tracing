/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:36:39 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 21:58:55 by akdovlet         ###   ########.fr       */
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
	pixel = transform(cam->transform, point_new(world_x, world_y,
				-1));
	ray->direction = tuple_normalize(tuple_substract(pixel, ray->origin));
	// tuple_print(ray->direction);
}

void	cache_ray(t_ray *ray, t_camera *cam)
{
	int		y;
	int		x;
	t_tuple	origin;

	y = 0;
	origin = transform(cam->transform, point_new(0, 0, 0));
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

void	fuzzy_ray_for_pixel(t_camera *cam, t_ray *ray, t_vec2 v, uint32_t seed)
{
	double	world_y;
	double	world_x;
	t_tuple	pixel;

	v.x += random_range(&seed, -0.5, 0.5);
	v.y += random_range(&seed, -0.5, 0.5);
	world_x = cam->half_width - ((v.x + 0.5) * cam->psize);
	world_y = cam->half_height - ((v.y + 0.5) * cam->psize);
	pixel = transform(cam->transform, point_new(world_x, world_y,
				-1));
	ray->direction = tuple_normalize(tuple_substract(pixel, ray->origin));
}

void	cache_fuzzy_ray(t_ray *ray, t_camera *cam, int frame)
{
	t_vec2	v;
	t_tuple	origin;

	v.y = 0;
	origin = transform(cam->transform, point_new(0, 0, 0));
	while (v.y < HEIGHT)
	{
		v.x = 0;
		while (v.x < WIDTH)
		{
			ray[v.x + v.y * WIDTH].origin = origin;
			fuzzy_ray_for_pixel(cam, &ray[v.x + v.y * WIDTH], v, (v.x + v.y * WIDTH) * frame);
			v.x++;
		}
		v.y++;
	}
}

