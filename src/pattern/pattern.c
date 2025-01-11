/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:52:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/11 15:07:51 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	pattern_at_shape(t_pattern pattern, t_shape shape, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	pattern_point;

	object_point = matrix_multiply_tuple(shape.transform, world_point);
	pattern_point = matrix_multiply_tuple(pattern.transform, object_point);
	return (pattern.pattern_at(pattern, pattern_point));
}

void	set_transform_pattern(t_pattern *pattern, t_matrix m)
{
	pattern->transform = inverse(m);
}
