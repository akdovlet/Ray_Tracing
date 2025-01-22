/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:13:25 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/22 15:30:39 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_vec2	check_axis(double origin, double direction)
// {
// 	double	t_min;
// 	double	t_max;
	
	
// }

t_vec2	cube_intersect(t_ray ray, t_shape shape)
{
	t_vec2	vec;
	
	
}

t_tuple	cube_normal_at(t_shape obj, t_tuple world_point)
{

}

t_shape	cube_default()
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
