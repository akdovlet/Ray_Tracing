/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:51:56 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/20 15:23:46 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	**sub_matrix(float **m, int size, int row, int col)
{
	int		i;
	int		j;
	int		k;
	int		l;
	float	**sub;

	i = -1;
	k = 0;
	sub = matrix_init(size - 1, size - 1);
	if (!sub)
		return (NULL);
	while (++i < size)
	{
		j = 0;
		l = 0;
		while (j < size)
		{
			if (j != col && i != row)
				sub[k][l++] = m[i][j];
			j++;
		}
		if (i != row)
			k++;
	}
	return (sub);
}
