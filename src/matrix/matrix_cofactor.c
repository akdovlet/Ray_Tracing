/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cofactor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:40:18 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/21 18:21:54 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	matrix_cofactor(float **m, int row, int col, int size)
{
	float	minor;

	minor =	matrix_minor(m, row, col, size);
	if (row + col % 2)
		minor = -minor;
	return (minor);
}
