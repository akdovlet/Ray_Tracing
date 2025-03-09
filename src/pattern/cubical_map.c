/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubical_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:29:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/08 13:55:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_tuple	uv_cube_pattern_at(t_faces *face, t_vec2f uv)
{
	if (uv.y > 0.8)
	{
		if (uv.x < 0.2)
			return (face->ul);
		else if (uv.x > 0.8)
			return (face->ur);
	}
	else if (uv.y < 0.2)
	{
		if (uv.x < 0.2)
			return (face->bl);
		else if (uv.x > 0.8)
			return (face->br);
	}
	return (face->main);
}

t_vec2f	front_face(t_tuple *p)
{
	return ((t_vec2f){
		fmod(p->x + 1.0, 2.0) / 2.0,
		fmod(p->y + 1.0, 2.0) / 2.0
	});
}

t_vec2f	back_face(t_tuple *p)
{
	return ((t_vec2f){
		fmod(1.0 - p->x, 2.0) / 2.0,
		fmod(p->y + 1.0, 2.0) / 2.0
	});
}

t_vec2f	left_face(t_tuple *p)
{
	return ((t_vec2f){
		fmod(p->z + 1.0, 2.0) / 2.0,
		fmod(p->y + 1.0, 2.0) / 2.0
	});
}

t_vec2f	right_face(t_tuple *p)
{
	return ((t_vec2f){
		fmod(1.0 - p->z, 2.0) / 2.0,
		fmod(p->y + 1.0, 2.0) / 2.0
	});
}

t_vec2f	up_face(t_tuple *p)
{
	return ((t_vec2f){
		fmod(1.0 - p->x, 2.0) / 2.0,
		fmod(1.0 - p->z, 2.0) / 2.0
	});
}

t_vec2f	down_face(t_tuple *p) 
{
	return ((t_vec2f){
		fmod(1.0 - p->x, 2.0) / 2.0,
		fmod(p->z + 1.0, 2.0) / 2.0
	});
}

size_t	which_face(t_tuple *p)
{
	double	value;

	value = fmax(fmax(fabs(p->x), fabs(p->y)), fabs(p->z));
	if (float_equal(value, p->x))
		return (0);
	else if (float_equal(value, -p->x))
		return (1);
	else if (float_equal(value, p->y))
		return (2);
	else if (float_equal(value, -p->y))
		return (3);
	else if (float_equal(value, p->z))
		return (4);
	return (5);
}

static t_tuple	pattern_at(t_pattern *cube_map, t_tuple p)
{
	size_t	face;
	t_vec2f	uv;

	face = which_face(&p);
	if (!face)
		uv = right_face(&p);
	else if (face == 1)
		uv = left_face(&p);
	else if (face == 2)
		uv = up_face(&p);
	else if (face == 3)
		uv = down_face(&p);
	else if (face == 4)
		uv = front_face(&p);
	else
		uv = back_face(&p);
	return (uv_cube_pattern_at(&cube_map->faces[face], uv));
}

t_faces	uv_align_check(t_tuple main, t_tuple ul, t_tuple ur, t_tuple bl, t_tuple br)
{
	return ((t_faces){main, ul, ur, bl, br});
}

t_pattern	cube_map(t_faces right, t_faces left, t_faces up, t_faces down, t_faces front, t_faces back)
{
	return ((t_pattern){
		.transform = identity(),
		.exists = 1,
		.pattern_at = pattern_at,
		.faces[0] = right,
		.faces[1] = left,
		.faces[2] = up,
		.faces[3] = down,
		.faces[4] = front,
		.faces[5] = back,
	});
}
