/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:00:05 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/28 19:01:37 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	inverse(t_matrix m)
{
	int			i;
	int			j;
	double		deter;
	t_matrix	m2;

	deter = determinant(m);
	if (deter == 0.0)
		return (m);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m2.raw[j][i] = cofactor(m, i, j) / deter;
			j++;
		}
		i++;
	}
	return (m2);
}
