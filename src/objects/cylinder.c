/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:52:29 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/29 18:27:41 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec2	cylinder_intersect(t_ray ray, t_shape shape)
{
	double	a;
	double	b;
	double	c;
	double discriminant;

	(void)shape;
	a = pow(ray.direction.x, 2.0) + pow(ray.direction.z, 2.0);
	b = 2.0 * ray.origin.x * ray.direction.x + 2.0 * ray.origin.z * ray.direction.z;
	c = pow(ray.origin.x, 2.0) + pow(ray.origin.z, 2.0) - 1.0;
	discriminant = pow(b, 2.0) - 4.0 * a * c;
	if (discriminant < 0.0)
		return ((t_vec2){.dis = -1});
	return ((t_vec2){
		.dis = 0,
		.x = 1.0,
		.y = 1.0
	});
}

t_tuple	cylinder_normal_at(t_shape shape, t_tuple point)
{
	(void)point;
	(void)shape;
	return (vector_new(0, 1, 0));	
}

t_shape	cylinder_default(void)
{
	return ((t_shape){
		.coordinates = point_new(0, 0, 0),
		.id = new_id(),
		.transform = identity(),
		.matter = material(),
		.local_interesct = &cylinder_intersect,
		.local_normalat = &cylinder_normal_at,
	});
}
