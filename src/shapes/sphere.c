/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:09:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 21:48:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

t_vec3f	sphere_intersect(t_shape *shape, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	dis;
	t_tuple	ray_sph_vector;

	ray_sph_vector = tuple_substract(ray.origin, shape->coordinates);
	a = tuple_dot(ray.direction, ray.direction);
	b = 2 * tuple_dot(ray.direction, ray_sph_vector);
	c = tuple_dot(ray_sph_vector, ray_sph_vector) - shape->radius * shape->radius;
	dis = b * b - 4.0 * a * c;
	if (dis < 0.0)
		return ((t_vec3f){.dis = -1});
	return ((t_vec3f){
		.dis = dis,
		.x = (-b - sqrt(dis)) / (2.0 * a),
		.y = (-b + sqrt(dis)) / (2.0 * a)
	});
}

t_tuple	sphere_normal_at(t_shape *shape, t_tuple point)
{
	return (tuple_substract(point, shape->coordinates));
}

t_shape	sphere_default(void)
{
	t_shape	new;

	new = (t_shape){
		.coordinates = point_new(0, 0, 0),
		.id = new_id(),
		.transform = identity(),
		.matter = material(),
		.local_intersect = &sphere_intersect,
		.local_normalat = &sphere_normal_at
	};
	return (new);
}

void	set_transform(t_shape *obj, t_matrix m)
{
	obj->transform = inverse(m);
}
