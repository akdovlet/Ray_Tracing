/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:42:55 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/15 14:56:38 by akdovlet         ###   ########.fr       */
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
	return (tuple_add(ray.origin, (tuple_multiply(tuple_normalize(ray.direction), factor))));
}

t_vec2	intersect(t_ray ray, t_shape shape)
{
	t_ray	transformed_ray;

	transformed_ray = ray_transform(ray, shape.transform);
	return (shape.local_interesct(transformed_ray, shape));
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
	if (!vec.dis)
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

t_intersection	hit(t_intersection inter)
{
	// if (!inter.count)
	// 	return (inter);
	if (inter.xs.x < 0.0 && inter.xs.y < 0.0)
		return (inter);
	if (inter.xs.x < 0)
		inter.t = inter.xs.y;
	else if (inter.xs.y < 0)
		inter.t = inter.xs.x;
	else
		inter.t = fmin(inter.xs.x, inter.xs.y);
	inter.hit = true;
	return (inter);
}
