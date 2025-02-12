/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:32:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/12 18:55:08 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

bool	is_shadowed(t_world *world, v4 point)
{
	v4	v;
	double	distance;
	v4	direction;
	t_ray	ray;
	t_junction	hits;

	v = tuple_substract(world->light.position, point);
	distance = tuple_magnitude(v);
	direction = v4_normalize(v);
	ray = ray_new(point, direction);
	intersect_world(world, ray, &hits);
	if (hits.hit && hits.closest.t < distance && !hits.closest.obj->matter.transparency)
		return (true);
	return (false);
}

v4	shade_hit(t_world *world, t_comps *comps, int depth)
{
	// bool	shadowed;
	double	reflectance;
	v4	surface;
	v4 reflected;
	v4 refracted;

	// shadowed = is_shadowed(world, comps->overz);
	surface = blinn_phong(world->light, comps->obj, comps, false);
	reflected = reflected_color(world, comps, depth - 1);
	refracted = refracted_color(world, comps, depth - 1);
	if (comps->obj->matter.reflective && comps->obj->matter.transparency)
	{
		reflectance = schlick(*comps);
		return (surface + reflected * reflectance + refracted *  (1 - reflectance));
	}
	return (surface + reflected + refracted);
}
