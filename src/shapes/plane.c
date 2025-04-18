/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:46:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/18 14:21:57 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3f	local_intersect(t_shape *shape, t_ray ray)
{
	double	dot;
	double	p_dot;
	double	t;

	dot = tuple_dot(shape->normal, ray.direction);
	if (!dot)
		return ((t_vec3f) {.dis = -1});
	p_dot = tuple_dot(shape->normal, shape->coordinates);
	t = (p_dot - tuple_dot(shape->normal, ray.origin)) / dot;
	if (t < 0)
		return ((t_vec3f) {.dis = -1});
	return ((t_vec3f) {
		.dis = 0,
		.x = t,
		.y = 0
	});
}

t_shape	plane_default(void)
{
	t_shape	new;

	new = (t_shape) {
		.coordinates = point_new(0, 0, 0),
		.normal	= vector_new(0, 1, 0),
		.id = new_id(),
		.matter = material(),
		.local_normalat = NULL,
		.local_intersect = &local_intersect,
		.transform = identity()
	};
	return (new);
}
