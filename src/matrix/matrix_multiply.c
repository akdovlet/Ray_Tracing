/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:05:06 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/24 18:01:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	**matrix_identity(void)
{
	float	**id;

	id = matrix_init(4, 4);
	if (!id)
		return (NULL);
	id[0][0] = 1;
	id[0][1] = 0;
	id[0][2] = 0;
	id[0][3] = 0;
	id[1][0] = 0;
	id[1][1] = 1;
	id[1][2] = 0;
	id[1][3] = 0;
	id[2][0] = 0;
	id[2][1] = 0;
	id[2][2] = 1;
	id[2][3] = 0;
	id[3][0] = 0;
	id[3][1] = 0;
	id[3][2] = 0;
	id[3][3] = 1;
	return (id);
}

float	**matrix_multiply(float **a, float **b)
{
	int		i;
	int		j;
	float	**m;

	i = 0;
	m = matrix_init(4, 4);
	if (!m)
		return (NULL);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m[i][j] = (a[i][0] * b[0][j]) + (a[i][1] * b[1][j])
				+ (a[i][2] * b[2][j]) + (a[i][3] * b[3][j]);
			j++;
		}
		i++;
	}
	return (m);
}

t_tuple	multiply_tuple(float a[4][4], t_tuple t1)
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
			res[i] += (a[i][j] * arr[j]);
			j++;
		}
		i++;
	}
	return (tuple_new(res[0], res[1], res[2], res[3]));
}

t_tuple	matrix_multiply_tuple(float **a, t_tuple t1)
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
			res[i] += (a[i][j] * arr[j]);
			j++;
		}
		i++;
	}
	return (tuple_new(res[0], res[1], res[2], res[3]));
}
