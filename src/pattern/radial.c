/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radial.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:37:49 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/15 18:33:39 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	radial_at(t_pattern radial, t_tuple point)
{
	t_tuple	distance;
	t_tuple	color;
	double	fraction;
	double	magnitude;

	point.w = 0;
	magnitude = tuple_magnitude(point);
	fraction = magnitude - floor(magnitude); 
	distance = tuple_substract(radial.color2, radial.color1);
	color = tuple_add(radial.color1, tuple_multiply(distance, fraction));
	return (color);
}

t_pattern	radial_pattern(t_tuple c1, t_tuple c2)
{
	return ((t_pattern){
		.exists = 1,
		.color1 = c1,
		.color2 = c2,
		.pattern_at = &radial_at,
		.transform = identity()
	});
}
