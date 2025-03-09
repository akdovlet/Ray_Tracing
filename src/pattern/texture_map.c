/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:23:43 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/08 11:31:34 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	texture_map(t_pattern *pattern, t_vec2f (*mapping)(t_tuple))
{
	return ((t_pattern){
		.color1 = pattern->color1,
		.color2 = pattern->color2,
		.exists	= 1,
		.height = pattern->height,
		.width = pattern->width,
		.pattern_at = pattern->pattern_at,
		.transform = identity(),
		.uv_mapping = mapping,
		.uv_pattern = pattern,
	});
}
