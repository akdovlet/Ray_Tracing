/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:56:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/06 12:23:31 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	uv_checkers_at(t_pattern *pattern, t_vec2f uv)
{
	double	u2;
	double	v2;

	u2 = floor(uv.x * pattern->height);
	v2 = floor(uv.y * pattern->width);
	if (!fmod(u2 + v2, 2))
		return (pattern->color1);
	return (pattern->color2);
}

t_tuple	uv_pattern_at(t_pattern *t_map, t_tuple point)
{
	t_vec2f	uv;

	uv = t_map->uv_mapping(point);
	return (uv_checkers_at(t_map, uv));
}

t_tuple	checkers_at(t_pattern *checkers, t_tuple point)
{	
	if ((fmod(floor(point.x) + floor(point.y) + floor(point.z), 2.0)))
		return (checkers->color1);
	return (checkers->color2);
}

t_pattern	uv_checkers(int width, int height, t_tuple c1, t_tuple c2)
{
	return ((t_pattern){
		.color1 = c1,
		.color2 = c2,
		.exists = 1,
		.height = height,
		.width = width,
		.pattern_at = &uv_pattern_at,
	});
}

t_pattern checkers_pattern(t_tuple c1, t_tuple c2)
{
	return ((t_pattern){
		.color1 = c1,
		.color2 = c2,
		.exists = 1,
		.pattern_at = &checkers_at,
		.transform = identity()
	});
}
