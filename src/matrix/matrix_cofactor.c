/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cofactor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:40:18 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/23 12:33:18 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	matrix_cofactor_3x3(float **m, int row, int col)
{
	float	cofactor;
	int		i;

	cofactor = 0;
	i = 0;
	while (i < 3)
	{
		cofactor = cofactor + (m[0][i] * matrix_minor(m, 0, i, 3));
		i++;
	}
	if (row + col % 2)
		cofactor = -cofactor;
	return (cofactor);
}

float	matrix_cofactor(float **m, int row, int col, int size)
{
	float	minor;

	minor =	matrix_minor(m, row, col, size);
	if (row + col % 2)
		minor = -minor;
	return (minor);
}
