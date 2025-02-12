/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_equal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:48:59 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/01 15:13:37 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	float_equal(double a, double b)
{
	return (fabs(a - b) < DBL_EPSILON);
}

int	tuple_equal(v4 a, v4 b)
{
	v4	tmp;

	tmp = a - b;
	return (
		fabs(tmp[0]) < DBL_EPSILON &&
		fabs(tmp[1]) < DBL_EPSILON &&
		fabs(tmp[2]) < DBL_EPSILON &&
		fabs(tmp[3]) < DBL_EPSILON
	);
}
