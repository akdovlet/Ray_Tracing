/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:17:20 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 17:52:54 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// a * (1.0 - f) + (b * f)
t_tuple	lerp(t_tuple a, t_tuple b, double f)
{
	return (tuple_add(tuple_multiply(a, (1.0 - f)), tuple_multiply(b, f)));
}

double	clamp(double x, double lower_limit, double upper_limit)
{
	if (x < lower_limit)
		return (lower_limit);
	if (x > upper_limit)
		return (upper_limit);
	return (x);
}

double	smoothstep(double edge0, double edge1, double x)
{
	x = clamp((x - edge0) / (edge1 - edge0), edge0, edge1);
	return (x * x * (3.0f - 2.0f * x));
}
