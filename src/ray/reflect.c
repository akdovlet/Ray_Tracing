/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:13:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/12 19:23:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"
#include "colors.h"

v4	reflect(v4 in, v4 normal)
{
	double	dot_product;
	v4		reflection;

	dot_product = tuple_dot(in, normal);
	reflection = normal * 2.0;
	reflection = reflection * dot_product;
	reflection = in - reflection;
	return (reflection);
}

v4	reflected_color(t_world *world, t_comps *comps, int depth)
{
	t_ray	reflect_ray;
	v4	color;

	if (depth <= 0 || !comps->obj->matter.reflective)
		return (color_new(0, 0, 0));
	reflect_ray = ray_new(comps->overz, comps->reflectv);
	color = color_at(world, reflect_ray, depth);
	return (color * comps->obj->matter.reflective);
}
