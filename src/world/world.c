/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:43:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/04 15:26:35 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"
#include "tuple.h"


t_world	default_world(void)
{
	t_world		world;
	t_object	objects[2];

	world.light = point_light(point_new(-10, 10, -10), color_new(1, 1, 1));
	objects[0] = sphere(point_new(0.0, 0.0, 0.0), 1);
	objects[0].matter = (t_material) {
		.color = color_new(0.8, 1.0, 0.6),
		.diffuse = 0.7,
		.specular = 0.2
		};
	objects[1] = sphere(point_new(0.0, 0.0, 0.0), 1.0);
	objects[1].transform = (scale(0.5, 0.5 , 0.5));
	return (world);
}

t_world	new_world(t_light light, t_object *obj)
{
	return ((t_world){
		.light = light,
		.obj = obj,
	});
}

void	intersect_world(t_world world, t_ray ray)
{
	
}
