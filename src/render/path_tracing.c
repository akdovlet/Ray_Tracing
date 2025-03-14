/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_tracing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:13:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/14 16:26:57 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	russian_roulette(t_tuple	*ray_color, uint32_t *seed)
{
	double	russian_roulette;

	russian_roulette = fmax(ray_color->x, fmax(ray_color->y, ray_color->z));
	if (random_range(seed, 0, 1.0) > russian_roulette)
		return (1);
	*ray_color = tuple_multiply(*ray_color, 1.0 / russian_roulette);
	return (0);
}

t_tuple	trace_rays(t_world *world, t_ray ray, uint32_t seed, int frame_index)
{
	int		bounces;
	int		i;
	bool	is_specualar;
	t_tuple	incoming_light;
	t_tuple	emitted_light;
	t_tuple	ray_color;
	t_tuple	diffusev;
	t_junction	hits;
	t_comps		comps;
	// t_tuple jitter;
	// t_tuple		target;

	(void)frame_index;
	incoming_light = black();
	ray_color = white();
	bounces = 8;
	i = 0;
	// if (frame_index != 1)
	// {
	// 	jitter = tuple_substract(tuple_new(random_range(&seed, -0.5, 0.5), random_range(&seed, -0.5, 0.5), 0, 0), vector_new(0.5, 0.5, 0));
	// 	ray.direction = tuple_normalize(tuple_add(ray.direction, jitter));
	// }
	while (i < bounces)
	{
		seed += i;
		intersect_world(world, ray, &hits);
		if (hits.hit)
		{
			pre_compute(&comps, hits.closest, ray, hits);
			ray.origin = comps.overz;
			diffusev = tuple_normalize(tuple_add(comps.normalv, random_unit_vec(&seed)));
			is_specualar = hits.closest.obj->matter.specular >= random_range(&seed, 0, 1.0);
			ray.direction = lerp(diffusev, comps.reflectv, hits.closest.obj->matter.roughness
										* is_specualar);
			if (tuple_dot(ray.direction, comps.normalv) < 0.0)
				tuple_negate(ray.direction);
			emitted_light = get_emission(hits.closest.obj);
			incoming_light = tuple_add(incoming_light, color_hadamard(emitted_light, ray_color));
			if (hits.closest.obj->matter.pattern.exists)
				ray_color = color_hadamard(ray_color, lerp(pattern_at_shape(&hits.closest.obj->matter.pattern, hits.closest.obj, comps.world_point),
							hits.closest.obj->matter.specular_color, is_specualar));
			else
				ray_color = color_hadamard(ray_color, lerp(hits.closest.obj->matter.color,
			hits.closest.obj->matter.specular_color, is_specualar));
			if (russian_roulette(&ray_color, &seed))
					break ;
		}
		else
		{
			incoming_light = tuple_add(incoming_light, color_hadamard(world->sky.color, ray_color));
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
	bounces = 8;
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
		light = tuple_add(light, get_emission(hits.closest.obj));
		
		contribution = color_hadamard(contribution, lerp(hits.closest.obj->matter.color,
										hits.closest.obj->matter.specular_color, is_specular));
		ray.origin = comps.overz;
		ray.direction = lerp(diffusev, comps.reflectv,
						hits.closest.obj->matter.roughness * is_specular);
		// if (tuple_dot(ray.direction, comps.normalv) < 0.0)
		// 	tuple_negate(ray.direction);
		i++;
	}
	return (light);
}
