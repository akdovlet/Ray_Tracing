/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:46:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/16 16:50:26 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec2	local_intersect(t_ray ray, t_shape shape)
{
	double	dot;
	double	t;
	t_tuple	local_ray;

	if (fabs(ray.direction.y) < __DBL_EPSILON__)
		return ((t_vec2) {.dis = -1});
	local_ray = tuple_substract(ray.origin, shape.coordinates);
	dot = tuple_dot(vector_new(0, 1, 0), local_ray);
	if (!dot)
		return ((t_vec2) {.dis = -1});
	t = -ray.origin.y / ray.direction.y;
	if (t < 0)
		return ((t_vec2) {.dis = -1});
	return ((t_vec2) {
		.dis = 0,
		.x = t,
		.y = 0
	});
}

static t_tuple	local_normalat(t_shape shape, t_tuple point)
{
	(void)shape;
	(void)point;
	return (tuple_normalize(matrix_multiply_tuple(shape.transform, vector_new(0, 1, 0))));
}

// static t_tuple	local_normalat(t_shape shape, t_tuple point)
// {
// 	(void)shape;
// 	(void)point;
// 	return (vector_new(0, 1, 0));
// }

t_shape	plane_new(void)
{
	t_shape	new;

	new = (t_shape) {
		.type = PLANE,
		.coordinates = point_new(0, 0, 0),
		.id = (uintptr_t) &new,
		.matter = material(),
		.local_normalat = &local_normalat,
		.local_interesct = &local_intersect,
		.transform = identity()
	};
	return (new);
}
