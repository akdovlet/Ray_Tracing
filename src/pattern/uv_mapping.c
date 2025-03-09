/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:10:53 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/09 13:07:03 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	color_to_tuple(uint32_t color)
{
	t_tuple	col;

	col.x = (double)((color >> 16) & 0xFF) / 255.0;
	col.y = (double)((color >> 8) & 0xFF) / 255.0;
	col.z = (double)((color & 0xFF)) / 255.0;
	col.w = 0;
	return (col);
}

t_tuple	color_at_texture(t_pattern *patter, t_tuple p)
{
	int				x;
	int				y;
	t_vec2f			uv;
	unsigned int	color;

	uv = patter->uv_mapping(p);
	x = round(uv.x * patter->map.img_width);
	y = round(patter->map.img_height - (uv.y * patter->map.img_height));
	color = pixel_at(&patter->map, x, y);
	return (color_to_tuple(color));
}

t_vec2f	spherical_map(t_tuple point)
{
	double	theta;
	double	radius;
	double	phi;
	double	raw_u;

	theta = atan2(point.x, point.z);
	point.w = 0;
	radius = tuple_magnitude(point);
	phi = acos(point.y / radius);
	raw_u = theta / (2 * M_PI);
	return ((t_vec2f){1 - (raw_u + 0.5), 1 - phi / M_PI});
}

t_pattern	spherical_pattern(t_img *img)
{
	return ((t_pattern){
		.exists = 1,
		.map = *img,
		.pattern_at = &color_at_texture,
		.transform = identity(),
		.uv_mapping = spherical_map
	});
}
