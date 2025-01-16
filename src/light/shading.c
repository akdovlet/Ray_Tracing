/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:32:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/16 14:29:15 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

bool	is_shadowed(t_world world, t_tuple point)
{
	t_tuple	v;
	double	distance;
	t_tuple	direction;
	t_ray	ray;
	t_junction	hits;

	v = tuple_substract(world.light.position, point);
	distance = tuple_magnitude(v);
	direction = tuple_normalize(v);
	ray = ray_new(point, direction);
	intersect_world(world, ray, &hits);
	if (hits.count && hits.cross[0].t < distance)
		return (true);
	return (false);
}

t_tuple	shade_hit(t_world world, t_comps comps, int depth)
{
	bool	shadowed;
	t_tuple	surface;
	t_tuple reflected;

	shadowed = is_shadowed(world, comps.overz);
	surface = blinn_phong(comps.obj.matter, world.light, 
			comps.overz, comps.eyev, comps.normalv,
			shadowed, comps.obj);
	reflected = reflected_color(world, comps, depth - 1);
	return (tuple_add(surface, reflected));
}
