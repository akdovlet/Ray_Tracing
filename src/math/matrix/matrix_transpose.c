/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:53:38 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/25 14:02:01 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_matrix	matrix_transpose(t_matrix m)
// {
// 	t_matrix	m2;
// 	int			i;
// 	int			j;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		j = 0;
// 		while (j < 4)
// 		{
// 			m2.raw[i][j] = m.raw[j][i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (m2);
// }

t_matrix	matrix_transpose(t_matrix m)
{
	return ((t_matrix){{
		{m.raw[0][0], m.raw[1][0], m.raw[2][0], m.raw[3][0]},
		{m.raw[0][1], m.raw[1][1], m.raw[2][1], m.raw[3][1]},
		{m.raw[0][2], m.raw[1][2], m.raw[2][2], m.raw[3][2]},
		{m.raw[0][3], m.raw[1][3], m.raw[2][3], m.raw[3][3]},
	}});
}
