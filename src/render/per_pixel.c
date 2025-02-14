/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:32:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/14 23:09:09 by akdovlet         ###   ########.fr       */
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

t_tuple	random_unit_vec(uint32_t *seed)
{
	return ((t_tuple){
		(double)random_float(seed) * 2.0 - 1.0,
		(double)random_float(seed) * 2.0 - 1.0,
		(double)random_float(seed) * 2.0 - 1.0,
		0
	});
}


t_tuple	tuple_interpolate(t_tuple a, t_tuple b, double f)
{
	//a * (1.0 - f) + (b * f)
	return (tuple_add(tuple_multiply(a, (1.0 - f)), tuple_multiply(b, f)));
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
		
		contribution = color_hadamard(contribution, tuple_interpolate(hits.closest.obj->matter.color,
										hits.closest.obj->matter.specular_color, is_specular));
		ray.origin = comps.overz;
		ray.direction = tuple_interpolate(diffusev, comps.reflectv,
						hits.closest.obj->matter.roughness * is_specular);
		if (tuple_dot(ray.direction, comps.normalv) < 0.0)
			tuple_negate(ray.direction);
		i++;
	}
	return (light);
}

double clamp(double x, double lower_limit, double upper_limit)
{
	if (x < lower_limit)
		return (lower_limit);
	if (x > upper_limit)
		return (upper_limit);
	return (x);
}

double smoothstep(double edge0, double edge1, double x)
{
	// Scale, and clamp x to 0..1 range
	x = clamp((x - edge0) / (edge1 - edge0), edge0, edge1); 
	return (x * x * (3.0f - 2.0f * x));
}

t_tuple	get_skylight(t_ray ray)
{
	double	sky_gradient_t;
	double	ground_to_sky_t;
	double	sun;
	double	sun_mask;
	t_tuple	sky_gradient;
	
	sky_gradient_t = pow(smoothstep(0.0, 0.4, ray.direction.y), 0.35);
	sky_gradient = tuple_interpolate(white(), color_new(0.06, 0.07, 0.09), sky_gradient_t);
	sun = pow(fmax(0.0, tuple_dot(ray.direction, vector_new(1.0, 1.0, 1.0))), 2.0) * 10.0;
	ground_to_sky_t = smoothstep(-0.01, 0, ray.direction.y);
	sun_mask = ground_to_sky_t >= 1;
	return (tuple_multiply(
		tuple_interpolate(color_new(1, 0.1, 0.1), sky_gradient, ground_to_sky_t),
		sun * sun_mask));
}

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
	sky = color_new(0.6, 0.7, 0.9);
	sky = color_new(0.06, 0.07, 0.09);
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
			ray.direction = tuple_interpolate(diffusev, comps.reflectv, hits.closest.obj->matter.roughness
												* is_specualar);
			emitted_light = get_emission(hits.closest.obj);
			incoming_light = tuple_add(incoming_light, color_hadamard(emitted_light, ray_color));
			ray_color = color_hadamard(ray_color, tuple_interpolate(hits.closest.obj->matter.color,
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

// t_tuple	reflect_refract(t_world *world, t_comps *comps, int depth)
// {
// 	double	reflectance;
// 	t_tuple	surface;
// 	t_tuple reflected;
// 	t_tuple refracted;
	
// 	reflected = reflected_color(world, comps, depth - 1);
// 	refracted = refracted_color(world, comps, depth - 1);
// 	if (comps->obj->matter.reflective && comps->obj->matter.transparency)
// 	{
// 		reflectance = schlick(*comps);
// 		return (tuple_add(surface, tuple_add(tuple_multiply(reflected, reflectance),
// 							tuple_multiply(refracted, 1 - reflectance))));
// 	}
// }
