/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scaling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:57:53 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/23 18:06:21 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	**matrix_scaling(float x, float y, float z)
{
	float	**m;

	m = matrix_identity();
	if (!m)
		return (NULL);
	m[0][0] = x;
	m[1][1] = y;
	m[2][2] = z;
	return (m);
}
