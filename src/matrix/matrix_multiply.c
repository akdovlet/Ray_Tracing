/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:05:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/09 16:32:28 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_matrix multiply_matrix(t_matrix a, t_matrix b)
{
	int		i;
	int		j;
	t_matrix result;
	
	result = (t_matrix){};
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.raw[i][j]	= (a.raw[i][0] * b.raw[0][j])
								+ (a.raw[i][1] * b.raw[1][j])
								+ (a.raw[i][2] * b.raw[2][j])
								+ (a.raw[i][3] * b.raw[3][j]);
			j++;
		}
		i++;
	}
	return (result);
}

// t_tuple	matrix_multiply_tuple(t_matrix m, t_tuple t1)
// {
// 	float	arr[4];
// 	float	res[4];
// 	int		i;
// 	int		j;

// 	i = 0;
// 	// ft_memset(res, 0, sizeof(res));
// 	arr[0] = t1.x;
// 	arr[1] = t1.y;
// 	arr[2] = t1.z;
// 	arr[3] = t1.w;
// 	while (i < 4)
// 	{
// 		j = 0;
// 		res[i] = 0;
// 		while (j < 4)
// 		{
// 			res[i] = res[i] + m.raw[i][j] * arr[j];
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (tuple_new(res[0], res[1], res[2], res[3]));
// }
t_tuple	matrix_multiply_tuple(t_matrix m, t_tuple t1)
{
	return ((t_tuple) {
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
