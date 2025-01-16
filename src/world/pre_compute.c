/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:52:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/16 14:20:40 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_comps	pre_compute(t_crossing cross, t_ray ray, t_crossing arr[1024])
{
	t_comps	new;

	(void)arr;
	new.t = cross.t;
	new.obj = cross.obj;
	new.world_point = position(ray, cross.t);
	new.eyev = tuple_negate(ray.direction);
	new.normalv = normal_at(new.obj, new.world_point);
	if (tuple_dot(new.normalv, new.eyev) < 0.0)
	{
		new.inside = true;
		new.normalv = tuple_negate(new.normalv);
	}
	else
		new.inside = false;
	new.overz = tuple_multiply(new.normalv, 0.00001);
	new.overz = tuple_add(new.overz, new.world_point);
	new.reflectv = reflect(ray.direction, new.normalv);
	new.n1 = cross.obj.matter.refractive_index;
	new.n2 = arr[1].obj.matter.refractive_index;
	return (new);
}
