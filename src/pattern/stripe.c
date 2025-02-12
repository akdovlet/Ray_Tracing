/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:43:57 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:42:23 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static v4	stripe_at(t_pattern pattern, v4 point)
{
	if (fabs(fmod(point[0], 2.0)) < 1.0)
		return (pattern.color1);
	return (pattern.color2);
}

t_pattern	stripe_pattern(v4 c1, v4 c2)
{
	return ((t_pattern){
		.exists = 1,
		.color1 = c1,
		.color2 = c2,
		.transform = identity(),
		.pattern_at = &stripe_at
	});
}

