/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:45:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/11 17:30:11 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_tuple	ring_at(t_pattern ring, t_tuple point)
{
	if (fmodf(floor(sqrt(powf(point.x, 2.0f) + pow(point.z, 2.0f))), 2.0f) < __FLT_EPSILON__)
		return (ring.color1);
	return (ring.color2);
}

t_pattern	ring_pattern(t_tuple c1, t_tuple c2)
{
	return ((t_pattern){
		.color1 = c1,
		.color2 = c2,
		.exists = 1,
		.pattern_at = &ring_at,
		.transform = identity()
	});
}
