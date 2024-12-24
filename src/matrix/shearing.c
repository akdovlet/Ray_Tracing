/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:29:07 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/24 17:18:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shear	shear_new(float x, float y, float z)
{
	t_shear new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

static void	init_shear(float m[4][4], t_shear s1, t_shear s2)
{
	m[0][0] = 1;
	m[0][1] = s1.x;
	m[0][2] = s1.y;
	m[0][3] = 0;

	m[1][0] =  s1.z;
	m[1][1] = 1;
	m[1][2] =  s2.x;
	m[1][3] = 0;

	m[2][0] = s2.y;
	m[2][1] = s2.z;
	m[2][2] = 1;
	m[2][3] = 0;

	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

t_tuple	shearing(t_shear s1, t_shear s2, t_tuple t1)
{
	float	m[4][4];

	init_shear(m, s1, s2);
	return (multiply_tuple(m, t1));
}
