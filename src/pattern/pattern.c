/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:52:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 18:52:14 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

v4	pattern_at_shape(t_pattern pattern, t_shape shape, v4 world_point)
{
	v4	object_point;
	v4	pattern_point;

	object_point = matrix_multiply_tuple(shape.transform, world_point);
	pattern_point = matrix_multiply_tuple(pattern.transform, object_point);
	return (pattern.pattern_at(pattern, pattern_point));
}

void	set_transform_pattern(t_pattern *pattern, t_matrix m)
{
	pattern->transform = inverse(m);
}
