/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:09:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/24 18:38:47 by akdovlet         ###   ########.fr       */
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
	else
		vec->dis = 0.0;
	if (shape->min < y1 && y1 < shape->max)
	{
		vec->vec3[i] = vec->y;
		if (i == 1)
			vec->dis = 0.0;
	}
	else
		if (i == 1)
			vec->dis = -1.0;
}

t_vec2	cylinder_intersect(t_shape *shape, t_ray ray)
{
	double	dis;
	t_dvec3	vec;
	t_vec2	new;

	vec.a = pow(ray.direction.x, 2.0) + pow(ray.direction.z, 2.0);
	if (vec.a < DBL_EPSILON)
		return ((t_vec2){.dis = -1});
	vec.b = (2.0 * (ray.origin.x * ray.direction.x)) +
			(2.0 * (ray.origin.z * ray.direction.z));
	vec.c = (pow(ray.origin.x, 2.0) + pow(ray.origin.z, 2.0)) - 1.0;
	dis = pow(vec.b, 2.0) - 4.0 * vec.a * vec.c;
	if (dis < 0.0)
		return ((t_vec2){.dis = -1});
	new = (t_vec2){ .dis = dis,
					.x = (-vec.b - sqrt(dis)) / (2.0 * vec.a),
					.y = (-vec.b + sqrt(dis)) / (2.0 * vec.a)};
	check_trunc(&new, shape, &ray);
	return (new);
}
