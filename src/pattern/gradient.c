/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:19:49 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:41:20 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

v4	gradient_at(t_pattern pattern, v4 point)
{
	v4	distance;
	double	fraction;
	v4	color;
	
	fraction = 2.0 * point[0] - floor(2.0 * point[0]);
	if(fabs(point[0] - floor(point[0])) < 0.5)
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

t_pattern	gradient_pattern(v4 c1, v4 c2)
{
	return ((t_pattern){
		.exists = 1,
		.color1 = c1,
		.color2 = c2,
		.pattern_at = &gradient_at,
		.transform = identity(),
	});
}
