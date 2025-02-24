/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:58:39 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/24 18:39:24 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_tuple	normal_at(t_shape *obj, t_tuple world_point)
{
	t_tuple	normalv;
	t_tuple	local_point;

	local_point = matrix_multiply_tuple(obj->transform, world_point);
	normalv = obj->local_normalat(obj, local_point);
	normalv = matrix_multiply_tuple(matrix_transpose(obj->transform), normalv);
	normalv.w = 0;
	return (tuple_normalize(normalv));
}
