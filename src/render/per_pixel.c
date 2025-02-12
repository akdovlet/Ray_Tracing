/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:32:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/12 19:03:01 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

t_ray	per_pixel(t_camera cam, double x, double y)
{
	double	world_y;
	double	world_x;
	v4	pixel;
	t_ray	ray;

	world_x = cam.half_width - ((x + 0.5) * cam.psize);
	world_y = cam.half_height - ((y + 0.5) * cam.psize);
	pixel = matrix_multiply_tuple(cam.transform, point_new(world_x, world_y, -1));
	ray.origin = matrix_multiply_tuple(cam.transform, point_new(0, 0, 0));
	ray.direction = v4_normalize(tuple_substract(pixel, ray.origin));
	return (ray);
}

v4	get_emission(t_shape *obj)
{
	return (tuple_multiply(obj->matter.emission_color,
							obj->matter.emission_power));
}

// v4	random_unit_vec(void)
// {
// 	v4	new;

	
// 	srand(time(NULL));
// 	new.x = (double)rand() / (double)(RAND_MAX) * 2.0 - 1.0;
// 	srand(time(NULL));
// 	new.y = (double)rand() / (double)(RAND_MAX) * 2.0 - 1.0;
// 	srand(time(NULL));
// 	new.z = (double)rand() / (double)(RAND_MAX) * 2.0 - 1.0;
// 	new.w = 0;
// 	return (new);
// }

uint32_t	pcg_hash(uint32_t seed)
{
	uint32_t	state;
	uint32_t	word;

	state = seed * 747796485u + 2891336453u;
	word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
	return (word >> 22u) ^ word;
}

static double random_float(uint32_t *seed)
{
	*seed = pcg_hash(*seed);
	return ((double)*seed / (double)UINT32_MAX);
}

v4	random_unit_vec(uint32_t seed)
{
	return ((v4){
		(double)random_float(&seed) * 2.0 - 1.0,
		(double)random_float(&seed) * 2.0 - 1.0,
		(double)random_float(&seed) * 2.0 - 1.0,
		0
	});
}

v4	tuple_interpolate(v4 a, v4 b, double f)
{
	//a * (1.0 - f) * (b * f)
	return (a * (1.0 - f) * (b * f));
}

v4		bounce_rays(t_world *world, t_ray ray, uint32_t seed)
{
	int			bounces;
	int			i;
	v4		light;
	v4		sky;
	v4		contribution;
	t_junction	hits;
	t_comps		comps;

	i = 0;
	bounces = 5;
	contribution = white();
	light = black();
	sky = color_new(0.6, 0.7, 0.9);
	sky = (v4){0.002, 0.002, 0.002, 0};
	while (i < bounces)
	{
		seed += i;
		intersect_world(world, ray, &hits);
		if (!hits.hit)
		{
			light += sky * contribution;
			break ;
		}
		pre_compute(&comps, hits.closest, ray, hits);
		contribution *= hits.closest.obj->matter.color;
		// light = tuple_add(light, shade_hit(world, &comps, 5));
		light += get_emission(hits.closest.obj);
		ray.origin = comps.overz;
		// ray.direction = v4_normalize(tuple_add(comps.reflectv, tuple_multiply(random_unit_vec(seed), hits.closest.obj->matter.roughness)));
		ray.direction = tuple_interpolate(comps.reflectv, random_unit_vec(seed), hits.closest.obj->matter.roughness);
		if (tuple_dot(ray.direction, comps.normalv) < 0.0)
			ray.direction = -ray.direction;
		i++;
	}
	return (light);
}

// v4	reflect_refract(t_world *world, t_comps *comps, int depth)
// {
// 	double	reflectance;
// 	v4	surface;
// 	v4 reflected;
// 	v4 refracted;
	
// 	reflected = reflected_color(world, comps, depth - 1);
// 	refracted = refracted_color(world, comps, depth - 1);
// 	if (comps->obj->matter.reflective && comps->obj->matter.transparency)
// 	{
// 		reflectance = schlick(*comps);
// 		return (tuple_add(surface, tuple_add(tuple_multiply(reflected, reflectance),
// 							tuple_multiply(refracted, 1 - reflectance))));
// 	}
// }
