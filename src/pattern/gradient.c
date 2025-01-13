/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:19:49 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/13 09:56:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	gradient_at(t_pattern pattern, t_tuple point)
{
	t_tuple	distance;
	float	fraction;
	t_tuple	color;
	
	point.x *= 2.0f;
	fraction = point.x - floorf(point.x);
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
