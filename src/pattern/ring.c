/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:45:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 18:07:23 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ring_at(t_pattern *ring, t_tuple point)
{
	if (fmod(floor(sqrt(pow(point.x, 2.0) + pow(point.z, 2.0))),
			2.0) < DBL_EPSILON)
		return (ring->color1);
	return (ring->color2);
}

t_pattern	ring_pattern(t_tuple c1, t_tuple c2)
{
	return ((t_pattern){.color1 = c1, .color2 = c2, .exists = 1,
		.pattern_at = &ring_at, .transform = identity()});
}
