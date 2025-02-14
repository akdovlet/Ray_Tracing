/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:33:23 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/14 13:41:19 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	matrix_cmp(t_matrix m1, t_matrix m2, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (m1.arr[i][j] != m2.arr[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
