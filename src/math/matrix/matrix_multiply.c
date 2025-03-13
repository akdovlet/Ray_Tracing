/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:05:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 18:01:31 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_matrix	multiply_matrix(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	t_matrix	result;

	result = (t_matrix){};
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.raw[i][j] = (a.raw[i][0] * b.raw[0][j])
				+ (a.raw[i][1] * b.raw[1][j])
				+ (a.raw[i][2] * b.raw[2][j])
				+ (a.raw[i][3] * b.raw[3][j]);
			j++;
		}
		i++;
	}
	return (result);
}

t_tuple	matrix_multiply_tuple(t_matrix m, t_tuple t1)
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
