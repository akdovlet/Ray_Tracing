/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tracing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:13:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/28 18:13:09 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	trace_rays(t_world *world, t_ray ray, uint32_t seed)
{
	int		bounces;
	int		i;
	bool	is_specualar;
	t_tuple	incoming_light;
	t_tuple	emitted_light;
	t_tuple	ray_color;
	t_tuple	sky;
	t_tuple	diffusev;
	t_junction	hits;
	t_comps		comps;

	incoming_light = black();
	ray_color = white();
	// sky = color_new(0.6, 0.7, 0.9);
	// sky = color_new(0.06, 0.07, 0.09);
	sky = color_new(0, 0, 0);
	bounces = 5;
	i = 0;
	while (i < bounces)
	{
		seed += i;
		intersect_world(world, ray, &hits);
		if (hits.hit)
		{
			pre_compute(&comps, hits.closest, ray, hits);
			ray.origin = comps.overz;
			diffusev = tuple_normalize(tuple_add(comps.normalv, random_unit_vec(&seed)));
			is_specualar = hits.closest.obj->matter.specular >= random_float(&seed);
				ray.direction = lerp(diffusev, comps.reflectv, hits.closest.obj->matter.roughness
										* is_specualar);
			// if (tuple_dot(ray.direction, comps.normalv) < 0.0)
			// 	tuple_negate(ray.direction);
			emitted_light = get_emission(hits.closest.obj);
			incoming_light = tuple_add(incoming_light, color_hadamard(emitted_light, ray_color));
			ray_color = color_hadamard(ray_color, lerp(hits.closest.obj->matter.color,
			hits.closest.obj->matter.specular_color, is_specualar));
		}
		else
		{
			incoming_light = tuple_add(incoming_light, color_hadamard(sky, ray_color));
			break ;
		}
	}
	return (incoming_light);
}

t_tuple		bounce_rays(t_world *world, t_ray ray, uint32_t seed)
{
	int			bounces;
	int			i;
	t_tuple		light;
	t_tuple		sky;
	t_tuple		contribution;
	t_tuple		diffusev;
	t_junction	hits;
	t_comps		comps;
	bool		is_specular;
	
	i = 0;
	bounces = 5;
	contribution = white();
	light = black();
	sky = color_new(0.6, 0.7, 0.9);
	sky = color_new(0.002, 0.002, 0.002);
	while (i < bounces)
	{
		seed += i;
		intersect_world(world, ray, &hits);
		if (!hits.hit)
		{
			light = tuple_add(light, color_hadamard(sky, contribution));
			break ;
		}
		pre_compute(&comps, hits.closest, ray, hits);
		is_specular = hits.closest.obj->matter.specular >= random_float(&seed);
		diffusev = tuple_normalize(tuple_add(comps.normalv, random_unit_vec(&seed)));
		// light = tuple_add(light, shade_hit(world, &comps, 5));
		light = tuple_add(light, get_emission(hits.closest.obj));
		
		contribution = color_hadamard(contribution, lerp(hits.closest.obj->matter.color,
										hits.closest.obj->matter.specular_color, is_specular));
		ray.origin = comps.overz;
		ray.direction = lerp(diffusev, comps.reflectv,
						hits.closest.obj->matter.roughness * is_specular);
		if (tuple_dot(ray.direction, comps.normalv) < 0.0)
			tuple_negate(ray.direction);
		i++;
	}
	return (light);
}
