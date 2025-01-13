/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:19:49 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/12 18:49:54 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	gradient_at(t_pattern pattern, t_tuple point)
{
	t_tuple	distance;
	float	fraction;
	t_tuple	color;

	// fraction = 2.0f * point.x - floorf(2.0f * point.x);
	fraction = (point.x + 1.0f) * 0.5f;
	if(fabsf(point.x - floorf(point.x)) < 0.5f)
	{
		distance = tuple_substract(pattern.color2, pattern.color1);
		color = tuple_add(pattern.color1, tuple_multiply(distance, fraction));	
	}
	else
	{
		distance = tuple_substract(pattern.color1, pattern.color2);	
		color = tuple_add(pattern.color2, tuple_multiply(distance, fraction));
	}
	// fprintf(stderr, "point.x: %f, floor(x): %f\n", point.x, floorf(point.x));
	// return (tuple_multiply(tuple_add(pattern.color1, distance), fraction));
	// tuple_print(color);
	// if(fabsf(point.x - floorf(point.x)) < 0.5f)
	// 		return a + (b - a) * (2 * p.X - Math.Floor(2 * p.X));

	// 	else

	// 		return b + (a - b) * (2 * p.X - Math.Floor(2 * p.X));
	return (color);
}

t_pattern	gradient_pattern(t_tuple c1, t_tuple c2)
{
	return ((t_pattern){
		.exists = 1,
		.color1 = c1,
		.color2 = c2,
		.pattern_at = &gradient_at,
		.transform = identity(),
	});
}
