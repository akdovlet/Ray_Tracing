/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:09:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/18 18:17:58 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_trunc(t_vec3f *vec, t_shape *shape, t_ray *ray)
{
	double	y0;
	double	y1;
	int		i;

	if (vec->x > vec->y)
		float_swap(&vec->x, &vec->y);
	i = 1;
	y0 = ray->origin.y + vec->x * ray->direction.y;
	y1 = ray->origin.y + vec->y * ray->direction.y;
	if (shape->min < y0 && y0 < shape->max)
		vec->vec3[i++] = vec->x;
	if (shape->min < y1 && y1 < shape->max)
		vec->vec3[i++] = vec->y;
	if (i == 1)
	{
		vec->dis = -1;
		vec->x = DBL_MAX;
		vec->y = DBL_MAX;
	}
	else if (i == 2)
		vec->dis = 0;
	else if (i == 3)
		vec->dis = 1;
}

int	check_cap(t_ray *ray, double t)
{
	double	x;
	double	z;
	double xz;
	
	x = ray->origin.x + t * ray->direction.x;
	z = ray->origin.z + t * ray->direction.z;
	xz = x * x + z * z;
	return (xz <= 1);
}

void	intersect_caps(t_shape *cyl, t_ray *ray, t_vec3f *xs)
{
	double	t1;
	double	t2;

	if (!cyl->closed || fabs(ray->direction.y) < FLT_EPSILON)
		return ;
	t1 = (cyl->min - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, t1))
	{
		if (t1 >= 0 && t1 < xs->x)
		{
			xs->x = t1;		
			xs->dis = 0;
		}
	}
	t2 = (cyl->max - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, t2))
	{
		if (t2 >= 0 && t2 < xs->y)
		{
			xs->y = t2;
			xs->dis = 1;
		}
	}
}

t_vec3f	cylinder_intersect(t_shape *shape, t_ray ray)
{
	double	dis;
	t_dvec3	vec;
	t_vec3f	new;

	new = (t_vec3f){.dis = -1, .x = DBL_MAX, .y = DBL_MAX};
	vec.a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (fabs(vec.a) < FLT_EPSILON)
		return (intersect_caps(shape, &ray, &new), new);
	vec.b = 2 * ray.origin.x * ray.direction.x +
			2 * ray.origin.z * ray.direction.z;
	vec.c = (ray.origin.x * ray.origin.x) + ((ray.origin.z * ray.origin.z) - 1.0);
	dis = vec.b * vec.b - 4.0 * vec.a * vec.c;
	if (dis < 0.0)
		return (intersect_caps(shape, &ray, &new), new);
	new = (t_vec3f){ .dis = dis,
					.x = (-vec.b - sqrt(dis)) / (2.0 * vec.a),
					.y = (-vec.b + sqrt(dis)) / (2.0 * vec.a)};
	check_trunc(&new, shape, &ray);
	intersect_caps(shape, &ray, &new);
	if (new.x > new.y)
		float_swap(&new.x, &new.y);
	return (new);
}
