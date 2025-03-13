/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:48:27 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 17:14:33 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up, t_camera *cam)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	m;

	forward = tuple_normalize(tuple_substract(to, from));
	left = tuple_cross(forward, tuple_normalize(up));
	true_up = tuple_cross(left, forward);
	m = (t_matrix){{
	{left.x, left.y, left.z, 0},
	{true_up.x, true_up.y, true_up.z, 0},
	{-forward.x, -forward.y, -forward.z, 0},
	{0, 0, 0, 1}
	}};
	cam->forward = forward;
	cam->left = left;
	cam->true_up = true_up;
	return (multiply_matrix(m, translate(-from.x, -from.y, -from.z)));
}
