/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:00:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/31 16:57:23 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec2	cylinder_intersect(t_ray ray, t_shape shape)
{
	double	a;
	double	b;
	double	c;
	double	dis;

	(void)shape;
	a = pow(ray.direction.x, 2.0) + pow(ray.direction.z, 2.0);
	if (a < __DBL_EPSILON__)
		return ((t_vec2){.dis = -1});
	b = (2.0 * (ray.origin.x * ray.direction.x)) +
		(2.0 * (ray.origin.z * ray.direction.z));
	c = (pow(ray.origin.x, 2.0) + pow(ray.origin.z, 2.0)) - 1.0;
	dis = pow(b, 2.0) - 4.0 * a * c;
	if (dis < 0.0)
		return ((t_vec2){.dis = -1});
	return ((t_vec2){
		.dis = dis,
		.x = (-b - sqrt(dis)) / (2.0 * a),
		.y = (-b + sqrt(dis)) / (2.0 * a)
	});
}

t_tuple	cylinder_normalat(t_shape shape, t_tuple point)
{
	(void)shape;
	return (point.y = 0, point.w = 0, point);
}

t_shape	cylinder_default(void)
{
	return ((t_shape){
		.coordinates = point_new(0, 0, 0),
		.id = new_id(),
		.matter = material(),
		.transform = identity(),
		.local_interesct = &cylinder_intersect,
		.local_normalat = &cylinder_normalat,
	});
}
