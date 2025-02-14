/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:52:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/14 13:13:59 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_comps	pre_compute(t_crossing cross, t_ray ray)
{
	t_comps	new;

	new.t = cross.t;
	new.obj = cross.obj;
	new.world_point = position(ray, cross.t);
	new.eyev = -ray.direction;
	new.normalv = normal_at(new.obj, new.world_point);
	if (tuple_dot(new.normalv, new.eyev) < 0.0f)
	{
		new.inside = true;
		new.normalv = -new.normalv;
	}
	else
		new.inside = false;
	new.overz = new.normalv * 0.002;
	new.overz = new.overz + new.world_point;
	return (new);
}
