/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:00:05 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/25 18:32:38 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	**matrix_inverse(float **m, int size)
{
/*
	int		i;
	int		j;
	float	determinant;
	float	**m2;


	i = 0;
	determinant = matrix_determinant_recursion(m, size);
	if (!determinant)
		return (fprintf(stderr, "not possible\n"), NULL);
	m2 = matrix_four_by_four(tuple_new(0, 0, 0, 0), tuple_new(0, 0, 0, 0), \
							tuple_new(0, 0, 0, 0), \
							tuple_new(0, 0, 0, 0));
	if (!m2)
		return (NULL);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			m2[j][i] = matrix_cofactor(m, i, j, size) / determinant;
			j++;
		}
		i++;
	}
	return (m2);
	*/
	(void)m;
	(void)size;
	return(NULL);
}
