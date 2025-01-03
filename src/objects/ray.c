/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:42:55 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/03 19:12:07 by akdovlet         ###   ########.fr       */
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
	return (tuple_add(ray.origin, (tuple_multiply(tuple_normalize(ray.direction), factor))));
}

t_vec2	intersect(t_ray ray, t_object object)
{
	float	a;
	float	b;
	float	c;
	float	dis;
	t_tuple	sphere_to_ray;

	ray = ray_transform(ray, inverse(object.transform));
	sphere_to_ray = tuple_substract(ray.origin, object.coordinates);
	a = tuple_dot(ray.direction, ray.direction);
	b = 2 * tuple_dot(ray.direction, sphere_to_ray);
	c = tuple_dot(sphere_to_ray, sphere_to_ray) - 1;
	dis = pow(b, 2) - 4 * a * c;
	return ((t_vec2){
		.dis = dis,
		.x = (-b - sqrt(dis)) / (2 * a),
		.y = (-b + sqrt(dis)) / (2 * a)
	});
}

t_intersection	intersection(t_object obj, t_vec2 vec)
{
	t_intersection	new;
	float			tmp;

	new = (t_intersection){
		.object = obj,
		.xs = vec,
		.t = 0
	};
	if (vec.dis < 0)
	{
		new.count = 0;
		return (new);
	}
	if (!vec.dis)
		new.count = 1;
	else
		new.count = 2;
	if (new.xs.x > new.xs.y)
	{
		tmp = new.xs.x;
		new.xs.x = new.xs.y;
		new.xs.y = tmp;
	}
	new.t = new.xs.x;
	return (new);
}

t_intersection	hit(t_intersection inter)
{
	if (inter.xs.x < 0 && inter.xs.y < 0)
	{
		inter.count = 0;
		inter.t = 0;
		return (inter);
	}
	if (inter.xs.x < 0)
		inter.t = inter.xs.y;
	else if (inter.xs.y < 0)
		inter.t = inter.xs.x;
	else
		inter.t = fmin(inter.xs.x, inter.xs.y);
	return (inter);
}



