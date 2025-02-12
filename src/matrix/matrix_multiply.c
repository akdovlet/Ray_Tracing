/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:05:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/12 21:03:19 by akdovlet         ###   ########.fr       */
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

// v4	matrix_multiply_tuple(t_matrix m, v4 t1)
// {
// 	return ((v4) {
// 		+ (m.raw[0][0] * t1[0])
// 		+ (m.raw[0][1] * t1[1])
// 		+ (m.raw[0][2] * t1[2])
// 		+ (m.raw[0][3] * t1[3]),
// 		+ (m.raw[1][0] * t1[0])
// 		+ (m.raw[1][1] * t1[1])
// 		+ (m.raw[1][2] * t1[2])
// 		+ (m.raw[1][3] * t1[3]),
// 		+ (m.raw[2][0] * t1[0])
// 		+ (m.raw[2][1] * t1[1])
// 		+ (m.raw[2][2] * t1[2])
// 		+ (m.raw[2][3] * t1[3]),
// 		+ (m.raw[3][0] * t1[0])
// 		+ (m.raw[3][1] * t1[1])
// 		+ (m.raw[3][2] * t1[2])
// 		+ (m.raw[3][3] * t1[3])
// 	});
// 	(void)t1;
// 	(void)m;
// 	return ((v4){0});\

// }

v4	matrix_multiply_tuple(t_matrix m, v4 t)
{

	t_matrix tmp = {{
		t * m.arr[0],
		t * m.arr[1],
		t * m.arr[2],
		t * m.arr[3],
	}};

	t_matrix tmp2 = {{
		{tmp.arr[0][0], tmp.arr[1][0], tmp.arr[2][0], tmp.arr[3][0]},
		{tmp.arr[0][1], tmp.arr[1][1], tmp.arr[2][1], tmp.arr[3][1]},
		{tmp.arr[0][2], tmp.arr[1][2], tmp.arr[2][2], tmp.arr[3][2]},
		{tmp.arr[0][3], tmp.arr[1][3], tmp.arr[2][3], tmp.arr[3][3]},
	}};
	
	v4 r = tmp2.arr[0] + tmp2.arr[1] + tmp2.arr[2] + tmp2.arr[3];
	return((v4){r[0], r[1], r[2], r[3]});
}

