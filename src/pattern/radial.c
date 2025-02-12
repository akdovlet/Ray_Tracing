/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radial.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:37:49 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:41:32 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

v4	radial_at(t_pattern radial, v4 point)
{
	v4	distance;
	v4	color;
	double	fraction;
	double	magnitude;

	point[3] = 0;
	magnitude = tuple_magnitude(point);
	fraction = magnitude - floor(magnitude); 
	distance = tuple_substract(radial.color2, radial.color1);
	color = tuple_add(radial.color1, tuple_multiply(distance, fraction));
	return (color);
}

t_pattern	radial_pattern(v4 c1, v4 c2)
{
	return ((t_pattern){
		.exists = 1,
		.color1 = c1,
		.color2 = c2,
		.pattern_at = &radial_at,
		.transform = identity()
	});
}
