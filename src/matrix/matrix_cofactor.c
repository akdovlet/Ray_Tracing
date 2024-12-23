/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cofactor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:40:18 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/23 18:56:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	matrix_cofactor(float **m, int row, int col, int size)
{
	float	cofactor;
	float	**sub;
	int		i;

	i = 0;
	cofactor = 0;
	if (size < 4)
	{
		cofactor = matrix_minor(m, row, col, size);
		if (row + col % 2)
			cofactor = -cofactor;
		return (cofactor);
	}
	sub = sub_matrix(m, 4, row, col);
	while (i < 3)
	{
		cofactor = cofactor + sub[0][i] * matrix_cofactor(sub, 0, i, size - 1);
		i++;
	}
	matrix_free(sub, size - 1);
	if ((row + col) % 2)
		cofactor = -cofactor;
	return (cofactor);
}
