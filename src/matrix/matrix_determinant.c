/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:27:07 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/23 12:46:54 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	matrix_determinant(float **m)
{
	return ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0]));
}

float	matrix_determinant_recursion(float **m, int size)
{
	int		i;
	float	**sub;
	float	determinant;
	float	tmp;

	determinant = 0;
	i = 0;
	if (size == 2)
		return (matrix_determinant(m));
	while (i < size)
	{
		sub = sub_matrix(m, size, 0, i);
		tmp = matrix_determinant_recursion(sub, size - 1);
		if (i % 2)
			tmp = -tmp;
		determinant = determinant + (m[0][i] * tmp);
		i++;
		matrix_free(sub, size - 1);
	}
	return (determinant);
}
