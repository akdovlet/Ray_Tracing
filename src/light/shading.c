/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:32:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/06 16:24:34 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

t_tuple	shade_hit(t_world world, t_comps comps)
{
	return (blinn_phong(comps.obj.matter, world.light, comps.eyev, comps.normalv,
			comps.world_point));
}
