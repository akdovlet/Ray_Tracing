/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:38:02 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/25 18:22:31 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrice	identity(void)
{
	return (t_matrice) {{
		{1,	0, 0, 0},	
		{0,	1, 0, 0},	
		{0,	0, 1, 0},	
		{0,	0, 0, 1}	
	}};
}
t_matrice	rotate_x(float angle)
{
	return (t_matrice) {{
		{1, 	0, 			0,				0},	
		{0, 	cos(angle), -sin(angle),	0},	
		{0, 	sin(angle), cos(angle),		0},	
		{0, 	0,			0,				1}	
	}};		
}
t_matrice	rotate_y(float angle)
{
	return (t_matrice) {{
		{cos(angle),	0,				sin(angle),	0},	
		{0,				1,				0,			0},	
		{-sin(angle),	0,				cos(angle),	0},	
		{0,				0,				0,	1}	
	}};		
}

t_matrice	rotate_z(float angle)
{
	return (t_matrice) {{
		{cos(angle),	-sin(angle),	0,	0},	
		{sin(angle),	cos(angle),		0,	0},	
		{0,				0,				1,	0},	
		{0,				0,				0,	1}	
	}};		
}

t_matrice	shear(t_shear s1, t_shear s2)
{
	return (t_matrice) {{
		{1,		s1.x,	s1.y,	0},	
		{s1.z,	1,		s2.x,	0},	
		{s2.y,	s2.z,	1,		0},	
		{0,		0,		0,		1}	
	}};
}
t_matrice	scale(t_tuple t1)
{
	return (t_matrice) {{
		{t1.x,	0,		0,		0},	
		{0,		t1.y,	0,		0},	
		{0,		0,		t1.z,	0},	
		{0,		0,		0,		1}	
	}};
}
t_matrice	translate(t_tuple t1)
{
	return (t_matrice) {{
		{1,	0, 0, t1.x},	
		{0,	1, 0, t1.y},	
		{0,	0, 1, t1.z},	
		{0,	0, 0, 1}	
	}};
}
