/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:09:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/26 18:31:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_trunc(t_vec2 *vec, t_shape *shape, t_ray *ray)
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
		vec->dis = -1;
	else if (i == 2)
		vec->dis = 0;
	else if (i == 3)
		vec->dis = 1;
}

int	check_cap(t_ray *ray, double t)
{
	double	x;
	double	z;

	x = ray->origin.x + t + ray->direction.x;
	z = ray->origin.z + t * ray->direction.z;
	return ((pow(x, 2) + pow(z, 2)) <= 1.0);
}

void	intersect_caps(t_shape *cyl, t_ray *ray, t_vec2 *xs)
{
	double	t;
	int		i;

	i = 1;
	xs->dis = -1;
	if (!cyl->closed || fabs(ray->direction.y) < DBL_EPSILON)
	{
		xs->dis = -1;
		return ;
	}
	t = (cyl->min - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, t))
		xs->vec3[i++] = t;
	t = (cyl->max - ray->origin.y) / ray->direction.y;
	if (check_cap(ray, t))
		xs->vec3[i++] = t;
	else if (i == 2)
		xs->dis = 0;
	else if (i == 3)
		xs->dis = 1;
}

t_vec2	cylinder_intersect(t_shape *shape, t_ray ray)
{
	double	dis;
	t_dvec3	vec;
	t_vec2	new;

	vec.a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	if (fabs(vec.a) < DBL_EPSILON)
		return (intersect_caps(shape, &ray, &new), new);
	vec.b = 2.0 * ray.origin.x * ray.direction.x +
			2.0 * ray.origin.z * ray.direction.z;
	vec.c = (pow(ray.origin.x, 2.0) + pow(ray.origin.z, 2.0)) - 1.0;
	dis = pow(vec.b, 2) - 4.0 * vec.a * vec.c;
	if (dis < 0.0)
		return (intersect_caps(shape, &ray, &new), new);
	new = (t_vec2){ .dis = dis,
					.x = (-vec.b - sqrt(dis)) / (2.0 * vec.a),
					.y = (-vec.b + sqrt(dis)) / (2.0 * vec.a)};
	check_trunc(&new, shape, &ray);
	return (new);
}
