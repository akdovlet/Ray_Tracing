/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:42:55 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/02 19:53:07 by akdovlet         ###   ########.fr       */
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

t_intersection intersect(t_ray ray, t_object object, t_vec2 *vec)
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
	vec->x = (-b - sqrt(dis)) / (2 * a);
	vec->y = (-b + sqrt(dis)) / (2 * a);
	return (intersection(object, *vec, dis));
}

t_intersection	intersection(t_object obj, t_vec2 vec, float dis)
{
	t_intersection	new;
	float			tmp;

	new = (t_intersection){
		.object = obj,
		.vec = vec,
		.count = 0,
		.t = 0
	};
	if (dis < 0)
		return (new);
	else if (!dis)
		new.count = 1;
	else
		new.count = 2;
	if (new.vec.x > new.vec.y)
	{
		tmp = new.vec.x;
		new.vec.x = new.vec.y;
		new.vec.y = tmp;
	}
	new.t = new.vec.x;
	return (new);
}

t_intersection	hit(t_intersection inter)
{
	if (inter.vec.x < 0 && inter.vec.y < 0)
		return (inter);
	if (inter.vec.x < 0)
		inter.t = inter.vec.y;
	else if (inter.vec.y < 0)
		inter.t = inter.vec.x;
	inter.t = fmin(inter.vec.x, inter.vec.y);
	return (inter);
}



