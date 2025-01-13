/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radial.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:37:49 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/12 18:42:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	radial_at(t_pattern radial, t_tuple point)
{
	t_tuple	distance;
	t_tuple	color;
	float	fraction;
	float	magnitude;

	point.w = 0;
	magnitude = tuple_magnitude(point);
	fraction = magnitude - floorf(magnitude); 
	distance = tuple_substract(radial.color2, radial.color1);
	// fprintf(stderr, "point.x: %f, floor(x): %f\n", point.x, floorf(point.x));
	// return (tuple_multiply(tuple_add(radial.color1, distance), fraction));
	color = tuple_add(radial.color1, tuple_multiply(distance, fraction));
	// tuple_print(color);
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
