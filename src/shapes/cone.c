/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:36:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 19:54:05 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_cap_cone(t_ray *ray, double t, double radius)
{
	double	x;
	double	z;
	double xz;
	
	x = ray->origin.x + t * ray->direction.x;
	z = ray->origin.z + t * ray->direction.z;
	xz = x * x + z * z;
	return (xz <= radius);
}

void	intersect_caps_cone(t_shape *shape, t_ray *ray, t_vec3f *xs)
{
	double	t1;
	double	t2;
	int		i;
	t_vec3f	caps;

	i = 1;
	caps = (t_vec3f){.x = DBL_MAX, .y = DBL_MAX};
	if (!shape->closed || fabs(ray->direction.y) < DBL_EPSILON)
		return ;
	t1 = (shape->min - ray->origin.y) / ray->direction.y;
	if (check_cap_cone(ray, t1, fabs(shape->min)))
		caps.vec3[i++] = t1;
	t2 = (shape->max - ray->origin.y) / ray->direction.y;
	if (check_cap_cone(ray, t2, fabs(shape->max)))
		caps.vec3[i++] = t2;
	if (caps.x > caps.y)
		float_swap(&caps.x, &caps.y);
	if (caps.x < xs->x)
		xs->x = caps.x;
	else if (caps.x < xs->y)
		xs->y = caps.y;
	if (i > 2 && caps.y < xs->y)
		xs->y = caps.y;
	if (i == 2)
		xs->dis += 1;
	else if (i == 3)
		xs->dis += 2;
}

t_vec3f	cone_intersect(t_shape *shape, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	t_vec3f	new;

	new = (t_vec3f){{-1, DBL_MAX, DBL_MAX}};
	a = (ray.direction.x * ray.direction.x) - (ray.direction.y * ray.direction.y)\
		+ (ray.direction.z * ray.direction.z);
	b = 2 * ray.origin.x * ray.direction.x - ((2 * ray.origin.y) * ray.direction.y)\
		+ ((2 * ray.origin.z) * ray.direction.z);
	if (!a && !b)
		return (new);
	c = ray.origin.x * ray.origin.x - ray.origin.y * ray.origin.y + ray.origin.z * ray.origin.z;
	if (!a && b)
		return (new.dis = 0, new.x = -c / (2 * b), new);
	new.dis = b * b - 4.0 * a * c;
	if (new.dis < 0.0)
		return (intersect_caps_cone(shape, &ray, &new), new);
	new = (t_vec3f){
		.x = (-b - sqrt(new.dis)) / (2.0 * a),
		.y = (-b + sqrt(new.dis)) / (2.0 * a)};
	check_trunc(&new, shape, &ray);
	if (shape->min != -INFINITY && shape->max != INFINITY)
		intersect_caps_cone(shape, &ray, &new);
	return (new);
}

t_tuple	cone_normal(t_shape *shape, t_tuple point)
{
	double	distance;
	double	y;

	distance = point.x * point.x + point.z * point.z;
	if (distance < 1 && point.y >= shape->max - DBL_EPSILON)
		return (vector_new(0, 1, 0));
	else if (distance < 1 && point.y <= shape->min + DBL_EPSILON)
		return (vector_new(0, -1, 0));
	y = sqrt(point.x * point.x + point.z * point.z);
	if (y > 0)
		y = -y;
	return (vector_new(point.x, y, point.z));
}

t_shape	cone_default()
{
	return ((t_shape){
		.id = new_id(),
		.coordinates = point_new(0, 0, 0),
		.matter = material(),
		.transform = identity(),
		.closed = true,
		.min = -INFINITY,
		.max = INFINITY,
		.local_intersect = &cone_intersect,
		.local_normalat = &cone_normal
	});
}
