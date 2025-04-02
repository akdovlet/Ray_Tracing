/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:22:22 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 20:04:59 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	scale(double x, double y, double z)
{
	return ((t_matrix){{
			{x, 0, 0, 0}, \
			{0, y, 0, 0}, \
			{0, 0, z, 0}, \
			{0, 0, 0, 1} \
	}});
}

t_matrix	t_scale(t_tuple t)
{
	return ((t_matrix){{
			{t.x, 0, 0, 0}, \
			{0, t.y, 0, 0}, \
			{0, 0, t.z, 0}, \
			{0, 0, 0, 1} \
	}});
}

t_matrix	translate(double x, double y, double z)
{
	return ((t_matrix){{
			{1, 0, 0, x}, \
			{0, 1, 0, y}, \
			{0, 0, 1, z}, \
			{0, 0, 0, 1} \
	}});
}

t_matrix	t_translate(t_tuple t)
{
	return ((t_matrix){{
			{1, 0, 0, t.x}, \
			{0, 1, 0, t.y}, \
			{0, 0, 1, t.z}, \
			{0, 0, 0, 1} \
	}});
}

t_tuple	transform(t_matrix m, t_tuple t1)
{
	return ((t_tuple){
		.x = 0
		+ (m.raw[0][0] * t1.x)
		+ (m.raw[0][1] * t1.y)
		+ (m.raw[0][2] * t1.z)
		+ (m.raw[0][3] * t1.w),
		. y = 0
		+ (m.raw[1][0] * t1.x)
		+ (m.raw[1][1] * t1.y)
		+ (m.raw[1][2] * t1.z)
		+ (m.raw[1][3] * t1.w),
		.z = 0
		+ (m.raw[2][0] * t1.x)
		+ (m.raw[2][1] * t1.y)
		+ (m.raw[2][2] * t1.z)
		+ (m.raw[2][3] * t1.w),
		.w = 0
		+ (m.raw[3][0] * t1.x)
		+ (m.raw[3][1] * t1.y)
		+ (m.raw[3][2] * t1.z)
		+ (m.raw[3][3] * t1.w)
	});
}
