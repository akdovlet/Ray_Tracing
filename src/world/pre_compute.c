/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:52:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/06 20:09:11 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_comps	pre_compute(t_crossing cross, t_ray ray)
{
	t_comps	new;

	new.t = cross.t;
	new.obj = cross.obj;
	new.world_point = position(ray, cross.t);
	new.eyev = tuple_negate(ray.direction);
	new.normalv = normal_at(new.obj, new.world_point);
	if (tuple_dot(new.normalv, new.eyev) < 0.0f)
	{
		new.inside = true;
		new.normalv = tuple_negate(new.normalv);
	}
	else
		new.inside = false;
	new.overz = tuple_multiply(new.normalv, nextafterf(0.01, INFINITY));
	new.overz = tuple_add(new.overz, new.world_point);
	return (new);
}
