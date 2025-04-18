/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:32:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/03 15:42:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "minirt.h"

bool	is_shadowed(t_world *world, t_light *light, t_tuple point)
{
	t_tuple		v;
	double		distance;
	t_ray		ray;
	t_junction	hits;

	v = tuple_substract(light->position, point);
	distance = tuple_magnitude(v);
	ray.origin = point;
	ray.direction = tuple_normalize(v);
	intersect_world(world, ray, &hits);
	if (hits.hit && hits.closest.t < distance
		&& !hits.closest.obj->matter.transparency)
		return (true);
	return (false);
}

t_tuple	shade_hit(t_world *world, t_comps *comps, int depth)
{
	int		i;
	bool	shadowed;
	double	reflectance;
	t_tuple	surface;
	t_tuple	reflected;
	t_tuple	refracted;

	i = 0;
	surface = (t_tuple){0, 0, 0, 0};
	while (i < world->light_count)
	{
		shadowed = is_shadowed(world, &world->light[i], comps->overz);
		surface = tuple_add(surface, blinn_phong(world->light[i], comps->obj, comps, shadowed));
		i++;
	}
	reflected = reflected_color(world, comps, depth - 1);
	refracted = refracted_color(world, comps, depth - 1);
	if (comps->obj->matter.reflective && comps->obj->matter.transparency)
	{
		reflectance = schlick(comps);
		return (tuple_add(surface, tuple_add(tuple_multiply(reflected,
						reflectance), tuple_multiply(refracted, 1.0
						- reflectance))));
	}
	return (tuple_add(tuple_add(surface, reflected), refracted));
}
