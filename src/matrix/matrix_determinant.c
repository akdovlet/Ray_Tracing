/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:27:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/14 17:54:15 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	sliding_window(size_t index, size_t window_size)
{
	return ((t_vec3){
		.x = (index + 1) % window_size,
		.y = (index + 2) % window_size,
		.z = (index + 3) % window_size,
	});
}

float	cofactor(t_matrix m, size_t y, size_t x)
{
	float	result;
	t_vec3	col;
	t_vec3	row;
	
	col = sliding_window(x, 4);
	row = sliding_window(y, 4);
	result = 0.0
		+ (m.raw[row.x][col.x] * m.raw[row.y][col.y] * m.raw[row.z][col.z]) \
		+ (m.raw[row.x][col.y] * m.raw[row.y][col.z] * m.raw[row.z][col.x]) \
		+ (m.raw[row.x][col.z] * m.raw[row.y][col.x] * m.raw[row.z][col.y]) \
		- (m.raw[row.x][col.z] * m.raw[row.y][col.y] * m.raw[row.z][col.x]) \
		- (m.raw[row.x][col.y] * m.raw[row.y][col.x] * m.raw[row.z][col.z]) \
		- (m.raw[row.x][col.x] * m.raw[row.y][col.z] * m.raw[row.z][col.y]);
	if ((x +y) % 2)
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
	{
		result += m.raw[0][i] * cofactor(m, 0, i);
	}
	return (result);
}
