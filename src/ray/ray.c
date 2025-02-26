/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:42:55 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/26 16:19:27 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
	
t_ray	ray_new(t_tuple origin, t_tuple direction)
{
	return ((t_ray){
	.origin = origin,
	.direction = direction	
	});
}

t_tuple	position(t_ray ray, double factor)
{
	return (tuple_add(ray.origin, (tuple_multiply(ray.direction, factor))));
}

t_vec2	intersect(t_shape *shape, t_ray ray)
{
	t_ray	transformed_ray;

	transformed_ray = ray_transform(ray, shape->transform);
	return (shape->local_interesct(shape, transformed_ray));
}

t_intersection	intersection(t_shape shape, t_vec2 vec)
{
	double			tmp;
	t_intersection	new;

	new.xs = vec;
	new.t = 0;
	new.hit = false;
	new.count = 0;
	(void)shape;
	if (vec.dis < 0.0)
		return (new);
	if (vec.dis == 0.0)
		new.count = 1;
	else
		new.count = 2;
	if (new.count > 1 && new.xs.x > new.xs.y)
	{
		tmp = new.xs.x;
		new.xs.x = new.xs.y;
		new.xs.y = tmp;
	}
	return (new);
} 

void hit(t_intersection *hit, t_vec2 vec)
{
	hit->hit = false;
	hit->count = 0;
	if (vec.dis < 0.0 || (vec.x < 0.0 && vec.y < 0.0))
		return ;
	hit->xs = vec;
	if (!vec.dis)
	{
		hit->t = vec.x;
		if (hit->t >= 0.0)
		{
			hit->hit = true;
			hit->count = 1;
		}
		return;
	}
	hit->t = fmin(hit->xs.x, hit->xs.y);
	hit->count = vec.x >= 0.0 + vec.y >= 0.0;
	if (hit->t >= 0.0)
		hit->hit = true;
}
