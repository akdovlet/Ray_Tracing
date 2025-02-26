/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:00:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:25 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	cylinder_normalat(t_shape *shape, t_tuple point)
{
	(void)shape;
	return (point.y = 0, point.w = 0, point);
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
