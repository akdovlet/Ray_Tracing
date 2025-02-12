/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:48:27 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/12 17:47:20 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	view_transform(v4 from, v4 to, v4 up)
{
	v4		forward;
	v4		left;
	v4		true_up;
	t_matrix	m;

	forward = v4_normalize(to - from);
	left = tuple_cross(forward, v4_normalize(up));
	true_up = tuple_cross(left, forward);
	m = (t_matrix){{
		{left[0], left[1], left[2], 0},
		{true_up[0], true_up[1], true_up[2], 0},
		{-forward[0], -forward[1], -forward[2], 0},
		{0, 0, 0, 1}
	}};
	return (multiply_matrix(m, translate(-from[0], -from[1], -from[2])));
}
