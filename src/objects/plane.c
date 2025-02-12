/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:46:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 20:06:24 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec2	local_intersect(t_ray ray, t_shape shape)
{
	double	dot;
	double	t;
	v4	local_ray;

	if (fabs(ray.direction[1]) < DBL_EPSILON)
		return ((t_vec2) {.dis = -1});
	local_ray = ray.origin - shape.coordinates;
	dot = tuple_dot(vector_new(0, 1, 0), local_ray);
	if (!dot)
		return ((t_vec2) {.dis = -1});
	t = -ray.origin[1] / ray.direction[1];
	if (t < 0)
		return ((t_vec2) {.dis = -1});
	return ((t_vec2) {
		.dis = 0,
		.x = t,
		.y = 0
	});
}

static v4	local_normalat(t_shape shape, v4 point)
{
	(void)point;
	(void)shape;
	return (vector_new(0, 1, 0));
}

t_shape	plane_new(void)
{
	t_shape	new;

	new = (t_shape) {
		.coordinates = point_new(0, 0, 0),
		.id = new_id(),
		.matter = material(),
		.local_normalat = &local_normalat,
		.local_interesct = &local_intersect,
		.transform = identity()
	};
	return (new);
}
