/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:45:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:42:08 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

v4	ring_at(t_pattern ring, v4 point)
{
	if (fmod(floor(sqrt(pow(point[0], 2.0) + pow(point[2], 2.0))), 2.0) < DBL_EPSILON)
		return (ring.color1);
	return (ring.color2);
}

t_pattern	ring_pattern(v4 c1, v4 c2)
{
	return ((t_pattern){
		.color1 = c1,
		.color2 = c2,
		.exists = 1,
		.pattern_at = &ring_at,
		.transform = identity()
	});
}
