/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:48:59 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/15 18:37:42 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	float_equal(double a, double b)
{
	if (fabs(a - b) < __DBL_MIN__)
		return (0);
	return (1);
}

int	tuple_cmp(t_tuple a, t_tuple b)
{
	if (float_equal(a.x, b.x))
		return (1);
	if (float_equal(a.y, b.y))
		return (1);
	if (float_equal(a.z, b.z))
		return (1);
	if (float_equal(a.w, b.w)	)
		return (1);
	return (0);
}
