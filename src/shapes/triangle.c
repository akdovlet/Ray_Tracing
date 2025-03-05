/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:54:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/05 13:13:38 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3f	triangle_intersect(t_shape *shape, t_ray ray)
{
	double	det;
	double	f;
	double	u;
	double	v;
	t_tuple	dir_cross_e2;
	t_tuple	p1_to_origin;
	t_tuple	origin_cross_e1;
	t_vec3f	xs;

	xs = (t_vec3f){{-1, DBL_MAX, DBL_MAX}};
	dir_cross_e2 = tuple_cross(ray.direction, shape->e2);
	det = tuple_dot(shape->e1, dir_cross_e2);
	if (fabs(det) < DBL_EPSILON)
		return (xs);
	f = 1.0 / det;
	p1_to_origin = tuple_substract(ray.origin, shape->p1);
	u = f * tuple_dot(p1_to_origin, dir_cross_e2);
	if (u < 0.0 || u > 1.0)
		return (xs);
	origin_cross_e1 = tuple_cross(p1_to_origin, shape->e1);
	v = f * tuple_dot(ray.direction, origin_cross_e1);
	if (v < 0.0 || v + u > 1.0)
		return (xs);
	return ((t_vec3f){{0, f * tuple_dot(shape->e2, origin_cross_e1), DBL_MAX}});
}

t_tuple	triangle_normal(t_tuple e1, t_tuple e2)
{
	t_tuple	normalv;

	normalv = tuple_cross(e2, e1);
	normalv.w = 0;
	return (tuple_normalize(normalv));	
}

t_shape	triangle(t_tuple p1, t_tuple p2, t_tuple p3)
{
	t_shape	t;

	t.id = new_id();
	t.transform = identity(),
	t.matter = material();
	t.p1 = p1;
	t.p2 = p2;
	t.p3 = p3;
	t.e1 = tuple_substract(p2, p1);
	t.e2 = tuple_substract(p3, p1);
	t.normal = triangle_normal(t.e1, t.e2);
	t.local_intersect = triangle_intersect;
	t.local_normalat = NULL;
	return (t);
}
