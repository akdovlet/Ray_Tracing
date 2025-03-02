/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:00:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/02 11:53:39 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	cylinder_normalat(t_shape *shape, t_tuple point)
{
	double distance;

	distance = point.x * point.x + point.z * point.z;
	if (distance < 1 && point.y >= shape->max - DBL_EPSILON)
		return (vector_new(0, 1, 0));
	else if (distance < 1 && point.y <= shape->min + DBL_EPSILON)
		return (vector_new(0, -1, 0));
	return (vector_new(point.x, 0, point.z));
}

t_shape	cylinder_default(void)
{
	return ((t_shape){
		.closed = true,
		.min = -1,
		.max = 1,
		.coordinates = point_new(0, 0, 0),
		.id = new_id(),
		.matter = material(),
		.transform = identity(),
		.local_interesct = &cylinder_intersect,
		.local_normalat = &cylinder_normalat,
	});
}
