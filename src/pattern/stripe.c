/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:43:57 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/15 14:35:24 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_tuple	stripe_at(t_pattern pattern, t_tuple point)
{
	if (fabs(fmod(point.x, 2.0)))
		return (pattern.color1);
	return (pattern.color2);
}

t_pattern	stripe_pattern(t_tuple c1, t_tuple c2)
{
	return ((t_pattern){
		.exists = 1,
		.color1 = c1,
		.color2 = c2,
		.transform = identity(),
		.pattern_at = &stripe_at
	});
}

