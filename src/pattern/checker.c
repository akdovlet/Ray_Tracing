/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:56:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/11 17:21:16 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	checkers_at(t_pattern checkers, t_tuple point)
{
	if (fabsf(fmodf(floor(point.x) + floor(point.y) + floor(point.z), 2.0f)) < 1.0f)
		return (checkers.color1);
	return (checkers.color2);
}

t_pattern checkers_pattern(t_tuple c1, t_tuple c2)
{
	return ((t_pattern){
		.color1 = c1,
		.color2 = c2,
		.exists = 1,
		.pattern_at = &checkers_at,
		.transform = identity()
	});
}
