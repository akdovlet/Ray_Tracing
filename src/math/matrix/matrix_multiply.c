/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:05:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/19 09:20:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_matrix	multiply_matrix(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	t_matrix	result;

	result = (t_matrix){};
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.raw[i][j] = (a.raw[i][0] * b.raw[0][j])
				+ (a.raw[i][1] * b.raw[1][j])
				+ (a.raw[i][2] * b.raw[2][j])
				+ (a.raw[i][3] * b.raw[3][j]);
			j++;
		}
		i++;
	}
	return (result);
}
