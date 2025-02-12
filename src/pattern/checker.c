/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:56:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:41:02 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

v4	checkers_at(t_pattern checkers, v4 point)
{	
	if ((fmod(floor(point[0]) + floor(point[1]) + floor(point[2]), 2.0)))
		return (checkers.color1);
	return (checkers.color2);
}

t_pattern checkers_pattern(v4 c1, v4 c2)
{
	return ((t_pattern){
		.color1 = c1,
		.color2 = c2,
		.exists = 1,
		.pattern_at = &checkers_at,
		.transform = identity()
	});
}
