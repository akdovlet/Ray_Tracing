/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:53:38 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/20 15:30:50 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	transpose(float tmp[4][4], float **m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp[j][i] = m[i][j];
			j++;
		}
		i++;
	}
}

void	matrix_transpose(float	**m)
{
	float	tmp[4][4];
	int		i;
	int		j;

	i = 0;
	transpose(tmp, m);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m[i][j] = tmp[i][j];
			j++;
		}
		i++;
	}
}
