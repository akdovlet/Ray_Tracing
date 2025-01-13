/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:32:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/13 17:20:09 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

t_tuple	shade_hit(t_world world, t_comps comps, int depth)
{
	bool	shadowed;
	t_tuple	surface;
	t_tuple reflected;

	shadowed = is_shadowed(world, comps.overz);
	surface = blinn_phong(comps.obj.matter, world.light, 
			comps.overz, comps.eyev, comps.normalv,
			shadowed, comps.obj);
	reflected = reflected_color(world, comps, depth - 1);
	return (tuple_add(surface, reflected));
}
