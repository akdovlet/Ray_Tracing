/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:19:49 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 18:06:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	gradient_at(t_pattern *pattern, t_tuple point)
{
	t_tuple	distance;
	double	fraction;
	t_tuple	color;

	fraction = 2.0 * point.x - floor(2.0 * point.x);
	if (fabs(point.x - floor(point.x)) < 0.5)
	{
		distance = tuple_substract(pattern->color2, pattern->color1);
		color = tuple_add(pattern->color1, tuple_multiply(distance, fraction));
	}
	else
	{
		distance = tuple_substract(pattern->color1, pattern->color2);
		color = tuple_add(pattern->color2, tuple_multiply(distance, fraction));
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
