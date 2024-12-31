/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:58:39 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/31 16:38:14 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	normal_at(t_object obj, t_tuple world_point)
{
	t_tuple object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	object_point = matrix_multiply_tuple(inverse(obj.transform), world_point);
	object_normal = tuple_substract(object_point, point_new(0, 0, 0));
	world_normal = matrix_multiply_tuple(matrix_transpose(inverse(obj.transform)), object_normal);
	world_normal.w = 0;
	return (tuple_normalize(world_normal));
}
