/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:42:55 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/29 18:43:41 by akdovlet         ###   ########.fr       */
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

t_tuple	position(t_ray ray, float factor)
{
	return (tuple_add(ray.origin, tuple_multiply(ray.direction, factor)));
}

float	intersect(t_ray ray, t_object object, t_vec2 *vec)
{
	float	a;
	float	b;
	float	c;
	float	dis;
	t_tuple	sphere_to_ray;

	sphere_to_ray = tuple_substract(ray.origin, object.coordinates);
	a = tuple_dot(ray.direction, ray.direction);
	b = 2 * tuple_dot(ray.direction, sphere_to_ray);
	c = tuple_dot(sphere_to_ray, sphere_to_ray) - 1;
	dis = pow(b, 2) - 4 * a * c;
	if (dis < 0)
		return (dis);
	vec->x = (-b - sqrt(dis)) / (2 * a);
	vec->y = (-b + sqrt(dis)) / (2 * a);
	return (dis);
}

t_intersection	interesection(float t, t_object obj, t_vec2 vec, float dis)
{
	t_intersection	new;
	float			tmp;

	new = (t_intersection){
		.t = t,
		.object = obj,
		.vec = vec
	};
	if (!dis)
		new.count = 1;
	else
		new.count = 2;
	if (new.vec.x > new.vec.y)
	{
		tmp = new.vec.x;
		new.vec.x = new.vec.y;
		new.vec.y = tmp;
	}
	return (new);
}



