/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:38:02 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/30 18:07:40 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	identity(void)
{
	return ((t_matrix){{
			{1, 0, 0, 0}, \
			{0, 1, 0, 0}, \
			{0, 0, 1, 0}, \
			{0, 0, 0, 1} \
	}});
}

t_matrix	rotate_x(float angle)
{
	return ((t_matrix){{\
		{1, 0, 0, 0}, \
		{0, cos(angle), -sin(angle), 0}, \
		{0, sin(angle), cos(angle), 0}, \
		{0, 0, 0, 1} \
	}});
}

t_matrix	rotate_y(float angle)
{
	return ((t_matrix){{
			{cos(angle), 0, sin(angle), 0}, \
			{0, 1, 0, 0}, \
			{-sin(angle), 0, cos(angle), 0}, \
			{0, 0, 0, 1} \
	}});
}

t_matrix	rotate_z(float angle)
{
	return ((t_matrix){{
			{cos(angle), -sin(angle), 0, 0}, \
			{sin(angle), cos(angle), 0, 0}, \
			{0, 0, 1, 0}, \
			{0, 0, 0, 1} \
	}});
}

t_matrix	shear(t_tuple s1, t_tuple s2)
{
	return ((t_matrix){{
			{1, s1.x, s1.y, 0}, \
			{s1.z, 1, s2.x, 0}, \
			{s2.y, s2.z, 1, 0}, \
			{0, 0, 0, 1} \
	}});
}
