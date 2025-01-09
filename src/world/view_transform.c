/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:48:27 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/09 18:46:59 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	m;

	forward = tuple_normalize(tuple_substract(to, from));
	forward[3] = 0;
	left = tuple_cross(forward, tuple_normalize(up));
	left[3] = 0;
	true_up = tuple_cross(left, forward);
	true_up[3] = 0;
	
	t_tuple remainder = {0};
	remainder[3] = 1;
	m = (t_matrix){{
		left, true_up, (forward * -1), remainder
		// {left.x, left.y, left.z, 0},
		// {true_up.x, true_up.y, true_up.z, 0},
		// {-forward.x, -forward.y, -forward.z, 0},
		// {0, 0, 0, 1}
	}};
	from *= -1;
	return (multiply_matrix(m, translate(from[0], from[1], from[2])));
}
