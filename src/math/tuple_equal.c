/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_equal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:48:59 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 17:58:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	float_equal(double a, double b)
{
	return (fabs(a - b) < DBL_EPSILON);
}

int	tuple_equal(t_tuple a, t_tuple b)
{
	if (!float_equal(a.x, b.x))
		return (0);
	if (!float_equal(a.y, b.y))
		return (0);
	if (!float_equal(a.z, b.z))
		return (0);
	if (!float_equal(a.w, b.w))
		return (0);
	return (1);
}
