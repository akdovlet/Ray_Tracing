/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:58:39 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:33:15 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

v4	normal_at(t_shape obj, v4 world_point)
{
	v4	normalv;
	v4	local_point;

	local_point = matrix_multiply_tuple(obj.transform, world_point);
	normalv = obj.local_normalat(obj, local_point);
	normalv = matrix_multiply_tuple(matrix_transpose(obj.transform), normalv);
	normalv[3] = 0;
	return (v4_normalize(normalv));
}
