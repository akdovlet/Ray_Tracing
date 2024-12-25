/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:05:06 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/25 18:34:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrice multiply(t_matrice a, t_matrice b)
{
	int		i;
	int		j;
	t_matrice result;
	
	result = (t_matrice){};
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

t_tuple	matrix_multiply_tuple(t_matrice m, t_tuple t1)
{
	float	arr[4];
	float	res[4];
	int		i;
	int		j;

	i = 0;
	ft_memset(res, 0, sizeof(res));
	arr[0] = t1.x;
	arr[1] = t1.y;
	arr[2] = t1.z;
	arr[3] = t1.w;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res[i] += (m.raw[i][j] * arr[j]);
			j++;
		}
		i++;
	}
	return (tuple_new(res[0], res[1], res[2], res[3]));
}
