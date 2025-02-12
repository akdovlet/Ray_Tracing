/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:13:25 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:31:29 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec2	check_axis(double origin, double direction)
{
	double	t_min_numerator;
	double	t_max_numerator;
	double	t_min;
	double	t_max;

	t_min_numerator = (-1 - origin);
	t_max_numerator = (1 - origin);
	if (fabs(direction) >= DBL_EPSILON)
	{
		t_min = t_min_numerator / direction;
		t_max = t_max_numerator / direction;
	}
	else
	{
		t_min = t_min_numerator * INFINITY;
		t_max = t_max_numerator * INFINITY;
	}
	if (t_min > t_max)
		return ((t_vec2){.x = t_max, .y = t_min});
	return ((t_vec2){.x = t_min, .y = t_max});
}

t_vec2	cube_intersect(t_ray ray, t_shape shape)
{
	double	tmin;
	double	tmax;
	t_vec2	xt;
	t_vec2	yt;
	t_vec2	zt;
	v4	local_ray;

	local_ray = tuple_substract(ray.origin, shape.coordinates);
	xt = check_axis(local_ray[0], ray.direction[0]);
	yt = check_axis(local_ray[1], ray.direction[1]);	
	zt = check_axis(local_ray[2], ray.direction[2]);	
	tmin = fmax(xt.x, fmax(yt.x, zt.x));
	tmax = fmin(xt.y, fmin(yt.y, zt.y));
	if (tmin > tmax)
		return ((t_vec2){.dis = -1, tmin, tmax});
	return ((t_vec2){
		.dis = 2,
		.x = tmin,
		.y = tmax
	});
}

v4	cube_normal_at(t_shape obj, v4 point)
{
	double	maxp;
	double	absx;
	double	absy;
	double	absz;
	v4	normalv;

	(void)obj;
	absx = fabs(point[0]);
	absy = fabs(point[1]);
	absz = fabs(point[2]);
	maxp = fmax(fmax(absx, absy), absz);
	if (float_equal(maxp, absx))
		normalv = vector_new(point[0], 0, 0);
	else if (float_equal(maxp, absy))
		normalv = vector_new(0, point[1], 0);
	else
		normalv = vector_new(0, 0, point[2]);
	return (normalv);
}

t_shape	cube_default(void)
{
	return ((t_shape){
		.coordinates = point_new(0, 0, 0),
		.id = new_id(),
		.transform = identity(),
		.matter = material(),
		.local_interesct = &cube_intersect,
		.local_normalat = &cube_normal_at,
	});
}
