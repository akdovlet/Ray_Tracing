/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:32:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/04 22:24:16 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

bool	is_shadowed(t_world *world, t_tuple point)
{
	t_tuple	v;
	double	distance;
	t_tuple	direction;
	t_ray	ray;
	t_junction	hits;

	v = tuple_substract(world->light.position, point);
	distance = tuple_magnitude(v);
	direction = tuple_normalize(v);
	ray = ray_new(point, direction);
	intersect_world(world, ray, &hits);
	if (hits.hit && hits.closest.t < distance && !hits.closest.obj->matter.transparency)
		return (true);
	return (false);
}

t_tuple	shade_hit(t_world *world, t_comps *comps, int depth)
{
	bool	shadowed;
	double	reflectance;
	t_tuple	surface;
	t_tuple reflected;
	t_tuple refracted;

	shadowed = false;
	surface = blinn_phong(world->light, comps->obj, comps, shadowed);
	reflected = reflected_color(world, comps, depth - 1);
	refracted = refracted_color(world, comps, depth - 1);
	if (comps->obj->matter.reflective && comps->obj->matter.transparency)
	{
		reflectance = schlick(*comps);
		return (tuple_add(surface, tuple_add(tuple_multiply(reflected, reflectance),
							tuple_multiply(refracted, 1 - reflectance))));
	}
	return (tuple_add(tuple_add(surface, reflected), refracted));
}
