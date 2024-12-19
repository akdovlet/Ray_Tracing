/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:05:06 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/19 15:15:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
