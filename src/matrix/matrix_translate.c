/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:26:09 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/23 17:58:46 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	**matrix_translation(t_tuple tuple)
{
	float	**m;

	m = matrix_identity();
	if (!m)
		return (NULL);
	m[0][3] = tuple.x;
	m[1][3] = tuple.y;
	m[2][3] = tuple.z;
	return (m);
}
