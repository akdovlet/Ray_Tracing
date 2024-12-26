/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:27:07 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/26 11:40:39 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	cofactor(t_matrix m, int index)
{
	float	result;
	int		a;
	int		b;
	int		c;

	a = (index + 1) % 4;
	b = (index + 2) % 4;
	c = (index + 3) % 4;
	result = 0.0
		+ (m.raw[1][a] * m.raw[2][b] * m.raw[3][c]) \
		+ (m.raw[1][b] * m.raw[2][c] * m.raw[3][a]) \
		+ (m.raw[1][c] * m.raw[2][a] * m.raw[3][b]) \
		- (m.raw[1][c] * m.raw[2][b] * m.raw[3][a]) \
		- (m.raw[1][b] * m.raw[2][a] * m.raw[3][c]) \
		- (m.raw[1][a] * m.raw[2][c] * m.raw[3][b]);
	if (index % 2)
		result *= -1;
	return (result);
}

float	determinant(t_matrix m)
{
	int		i;
	float	result;

	result = 0.0;
	i = -1;
	while (++i < 4)
		result += m.raw[0][i] * cofactor(m, i);
	return (result);
}
