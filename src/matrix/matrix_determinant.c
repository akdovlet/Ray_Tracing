/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:27:07 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/22 18:10:40 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	matrix_determinant(float **m)
{
	return ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0]));
}

float	matrix_determinant_recursion(float **m, int size)
{
	int	i;
	float	determinant;

	determinant = 0;
	i = 0;
	if (size == 2)
		return (matrix_determinant(m));
	while (i < size)
	{
		fprintf(stderr, "m[0][%d]: %f\n", i, m[0][i]);
		fprintf(stderr, "matrix cofac of m[0][%d]: %f\n", i, matrix_cofactor(m, 0, i, size));
		determinant = (determinant + m[0][i]) * matrix_cofactor(m, 0, i, size);
		i++;
	}
	return (determinant);
}
