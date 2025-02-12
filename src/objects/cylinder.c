/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:00:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:33:05 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	float_swap(double *a, double *b)
{
	double tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// To do: filthy, make it prettier
void	check_trunc(t_vec2 *vec, t_shape *shape, t_ray *ray)
{
	double	y0;
	double	y1;
	int		i;

	if (vec->x > vec->y)
		float_swap(&vec->x, &vec->y);
	i = 1;
	y0 = ray->origin[1] + vec->x * ray->direction[1];
	y1 = ray->origin[1] + vec->y * ray->direction[1];
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

t_vec2	cylinder_intersect(t_ray ray, t_shape shape)
{
	double	dis;
	t_dvec3	vec;
	t_vec2	new;

	vec.a = pow(ray.direction[0], 2.0) + pow(ray.direction[2], 2.0);
	if (vec.a < DBL_EPSILON)
		return ((t_vec2){.dis = -1});
	vec.b = (2.0 * (ray.origin[0] * ray.direction[0])) +
			(2.0 * (ray.origin[2] * ray.direction[2]));
	vec.c = (pow(ray.origin[0], 2.0) + pow(ray.origin[2], 2.0)) - 1.0;
	dis = pow(vec.b, 2.0) - 4.0 * vec.a * vec.c;
	if (dis < 0.0)
		return ((t_vec2){.dis = -1});
	new = (t_vec2){ .dis = dis,
					.x = (-vec.b - sqrt(dis)) / (2.0 * vec.a),
					.y = (-vec.b + sqrt(dis)) / (2.0 * vec.a)
					};
	check_trunc(&new, &shape, &ray);
	return (new);
}

v4	cylinder_normalat(t_shape shape, v4 point)
{
	(void)shape;
	return (point[1] = 0, point[3] = 0, point);
}

t_shape	cylinder_default(void)
{
	return ((t_shape){
		.min = -INFINITY,
		.max = INFINITY,
		.coordinates = point_new(0, 0, 0),
		.id = new_id(),
		.matter = material(),
		.transform = identity(),
		.local_interesct = &cylinder_intersect,
		.local_normalat = &cylinder_normalat,
	});
}
