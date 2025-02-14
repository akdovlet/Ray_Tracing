/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:27:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/14 13:41:34 by akdovlet         ###   ########.fr       */
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

double	cofactor(t_matrix m, size_t y, size_t x)
{
	double	result;
	t_vec3	col;
	t_vec3	row;
	
	col = sliding_window(x, 4);
	row = sliding_window(y, 4);
	result = 0.0
		+ (m.arr[row.x][col.x] * m.arr[row.y][col.y] * m.arr[row.z][col.z]) \
		+ (m.arr[row.x][col.y] * m.arr[row.y][col.z] * m.arr[row.z][col.x]) \
		+ (m.arr[row.x][col.z] * m.arr[row.y][col.x] * m.arr[row.z][col.y]) \
		- (m.arr[row.x][col.z] * m.arr[row.y][col.y] * m.arr[row.z][col.x]) \
		- (m.arr[row.x][col.y] * m.arr[row.y][col.x] * m.arr[row.z][col.z]) \
		- (m.arr[row.x][col.x] * m.arr[row.y][col.z] * m.arr[row.z][col.y]);
	if ((x +y) % 2)
		result *= -1;
	return (result);
}

double	determinant(t_matrix m)
{
	int		i;
	double	result;

	result = 0.0;
	i = -1;
	while (++i < 4)
	{
		result += m.arr[0][i] * cofactor(m, 0, i);
	}
	return (result);
}
