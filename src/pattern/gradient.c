/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:19:49 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/11 16:40:45 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_tuple	gradient_at(t_pattern pattern, t_tuple point)
{
	t_tuple	distance;
	float	fraction;
	t_tuple	color;

	distance = tuple_substract(pattern.color2, pattern.color1);
	fraction =  1.0f - (point.x - floorf(point.x));
	// fprintf(stderr, "point.x: %f, floor(x): %f\n", point.x, floorf(point.x));
	// return (tuple_multiply(tuple_add(pattern.color1, distance), fraction));
	color = tuple_add(pattern.color1, tuple_multiply(distance, fraction));
	tuple_print(color);
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
