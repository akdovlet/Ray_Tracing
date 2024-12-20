/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_minor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:33:11 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/20 15:36:39 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	matrix_minor(float **m, int size)
{
	float	**sub;
	float	determinant;

	sub = sub_matrix(m, size, 1, 0);
	determinant = matrix_determinant2x2(sub);
	matrix_free(sub, size - 1);
	return (determinant);	
}
