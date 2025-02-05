/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:32:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/05 17:37:24 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

t_ray	per_pixel(t_camera cam, double x, double y)
{
	double	world_y;
	double	world_x;
	t_tuple	pixel;
	t_ray	ray;

	world_x = cam.half_width - ((x + 0.5) * cam.psize);
	world_y = cam.half_height - ((y + 0.5) * cam.psize);
	pixel = matrix_multiply_tuple(cam.transform, point_new(world_x, world_y, -1));
	ray.origin = matrix_multiply_tuple(cam.transform, point_new(0, 0, 0));
	ray.direction = tuple_normalize(tuple_substract(pixel, ray.origin));
	return (ray);
}

t_tuple	get_emission(t_shape *obj)
{
	return (tuple_multiply(obj->matter.emission_color,
							obj->matter.emission_power));
}

// t_tuple	random_unit_vec(void)
// {
// 	t_tuple	new;

	
// 	srand(time(NULL));
// 	new.x = (double)rand() / (double)(RAND_MAX) * 2.0 - 1.0;
// 	srand(time(NULL));
// 	new.y = (double)rand() / (double)(RAND_MAX) * 2.0 - 1.0;
// 	srand(time(NULL));
// 	new.z = (double)rand() / (double)(RAND_MAX) * 2.0 - 1.0;
// 	new.w = 0;
// 	return (new);
// }

t_tuple	random_unit_vec(void)
{
	t_tuple	new;

	
	new.x = (double)rand() / (double)(RAND_MAX) * 2.0 - 1.0;
	new.y = (double)rand() / (double)(RAND_MAX) * 2.0 - 1.0;
	new.z = (double)rand() / (double)(RAND_MAX) * 2.0 - 1.0;
	new.w = 0;
	return (new);
}

t_tuple		bounce_rays(t_world *world, t_ray ray)
{
	int			bounces;
	int			i;
	t_tuple		light;
	t_tuple		sky;
	t_tuple		contribution;
	t_junction	hits;
	t_comps		comps;

	i = 0;
	bounces = 5;
	contribution = white();
	light = black();
	sky = color_new(0.6, 0.7, 0.9);
	sky = black();
	while (i < bounces)
	{
		intersect_world(world, ray, &hits);
		if (!hits.hit)
		{
			light = tuple_add(light, color_hadamard(sky, contribution));
			break ;
		}
		contribution = color_hadamard(contribution, hits.closest.obj->matter.color);
		pre_compute(&comps, hits.closest, ray, hits);
		// light = tuple_add(light, shade_hit(world, &comps, 5));
		light = tuple_add(light, get_emission(hits.closest.obj));
		ray.origin = comps.overz;
		ray.direction = tuple_normalize(tuple_add(comps.normalv, tuple_normalize(random_unit_vec())));
		if (tuple_dot(ray.direction, comps.normalv) < 0.0)
			tuple_negate(ray.direction);
		i++;
	}
	return (light);
}
