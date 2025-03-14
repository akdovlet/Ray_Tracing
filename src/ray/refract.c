/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:41:33 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 18:10:25 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "minirt.h"
#include "tuple.h"

t_tuple	refracted_color(t_world *world, t_comps *comps, int depth)
{
	double	n_ratio;
	double	cos_i;
	double	sin2_t;
	double	cos_t;
	t_tuple	direction;

	if (!depth || !comps->obj->matter.transparency)
		return (black());
	n_ratio = comps->n1 / comps->n2;
	cos_i = tuple_dot(comps->eyev, comps->normalv);
	sin2_t = pow(n_ratio, 2.0) * (1.0 - pow(cos_i, 2.0));
	if (sin2_t > 1.0)
		return (black());
	cos_t = sqrt(1.0 - sin2_t);
	direction = tuple_substract(tuple_multiply(comps->normalv, (n_ratio * cos_i
					- cos_t)), tuple_multiply(comps->eyev, n_ratio));
	return (tuple_multiply(color_at(world, ray_new(comps->under_point,
					direction), depth - 1), comps->obj->matter.transparency));
}

t_tuple	refracted_ray(t_comps *comps)
{
	double	n_ratio;
	double	cos_i;
	double	sin2_t;
	double	cos_t;
	t_tuple	direction;

	n_ratio = comps->n1 / comps->n2;
	cos_i = tuple_dot(comps->eyev, comps->normalv);
	sin2_t = pow(n_ratio, 2.0) * (1 - pow(cos_i, 2.0));
	cos_t = sqrt(1.0 - sin2_t);
	direction = tuple_substract(tuple_multiply(comps->normalv, (n_ratio * cos_i
					- cos_t)), tuple_multiply(comps->eyev, n_ratio));
	return (direction);
}
