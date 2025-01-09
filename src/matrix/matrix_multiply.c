/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:05:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/09 18:59:38 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_matrix multiply_matrix(t_matrix a, t_matrix b)
{
	int		i;
	int		j;
	t_matrix result;
	
	result = (t_matrix){};
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.raw[i][j]	= (a.raw[i][0] * b.raw[0][j])
								+ (a.raw[i][1] * b.raw[1][j])
								+ (a.raw[i][2] * b.raw[2][j])
								+ (a.raw[i][3] * b.raw[3][j]);
			j++;
		}
		i++;
	}
	return (result);
}

t_tuple	matrix_multiply_tuple(t_matrix m, t_tuple t)
{

	t_matrix tmp = {
		t * m.raw[0],
		t * m.raw[1],
		t * m.raw[2],
		t * m.raw[3],
	};

	t_matrix tmp2 = {{
		{tmp.raw[0][0], tmp.raw[1][0], tmp.raw[2][0], tmp.raw[3][0]},
		{tmp.raw[0][1], tmp.raw[1][1], tmp.raw[2][1], tmp.raw[3][1]},
		{tmp.raw[0][2], tmp.raw[1][2], tmp.raw[2][2], tmp.raw[3][2]},
		{tmp.raw[0][3], tmp.raw[1][3], tmp.raw[2][3], tmp.raw[3][3]},
	}};
	
	t_tuple r = tmp2.raw[0] + tmp2.raw[1] + tmp2.raw[2] + tmp2.raw[3];
	return((t_tuple){r[0], r[1], r[2], r[3]});

}
