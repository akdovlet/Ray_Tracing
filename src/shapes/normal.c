/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:58:39 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/18 16:24:26 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_tuple	height_normal(t_shape *obj, t_tuple world_point)
{
	t_img		*img;
	t_vec2f		uv;
	uint32_t	x;
	uint32_t	y;
	double	center_l;
	double	center_r;
	double	center_u;
	double	center_d;
	t_tuple		normal;

	img = &obj->matter.pattern.height_map;
	uv = obj->matter.pattern.uv_mapping(world_point);
	x = round(uv.x * obj->matter.pattern.height_map.img_width);
	y = round(obj->matter.pattern.height_map.img_height - (uv.y * obj->matter.pattern.height_map.img_height));
	center_l = (double)pixel_at(img, x - 1, y);
	center_r = (double)pixel_at(img, x + 1, y);
	center_u = (double)pixel_at(img, x, y - 1);
	center_d = (double)pixel_at(img, x, y + 1);
	normal = tuple_normalize(vector_new(2 * (center_r - center_l), 2 *  (center_d - center_u), -4));
	return (normal);
}

t_tuple	color_to_normal(uint32_t color)
{
	t_tuple	col;

	col.x = (double)((color >> 16) & 0xFF) / 127.5 - 1.0;
	col.y = (double)((color >> 8) & 0xFF) / 127.5 - 1.0;
	col.z = 1.0 - (double)((color & 0xFF)) / 127.5;
	col.w = 0;
	return (col);
}

t_tuple	normal_map(t_shape *obj, t_tuple p)
{
	t_img		*img;
	t_vec2f		uv;
	uint32_t	x;
	uint32_t	y;
	t_tuple		normal;
	t_tuple		T;
	t_tuple		B;
	t_matrix	TBN;
	// t_tuple		center;
	// t_tuple		A;
	// double		theta;
	// double		phi;
	// double		delta_phi;

	img = &obj->matter.pattern.height_map;
	uv = obj->matter.pattern.uv_mapping(p);
	x = round(uv.x * obj->matter.pattern.height_map.img_width);
	y = round(obj->matter.pattern.height_map.img_height - (uv.y * obj->matter.pattern.height_map.img_height));
	// x = x % obj->matter.pattern.height_map.img_width;
	// y = y % obj->matter.pattern.height_map.img_height;
	normal = color_to_normal(pixel_at(img, x, y));
	T = tuple_normalize(tuple_cross(vector_new(0, 1, 0), p));
	B = tuple_cross(normal, T);
	TBN = (t_matrix){
		.r1 = T,
		.r2 = B,
		.r3 = normal,
		{0, 0, 0, 1},
	};
	normal = transform(matrix_transpose(TBN), normal);
	normal.w = 0;
	return (normal);
}

t_tuple	normal_at(t_shape *obj, t_tuple world_point)
{
	t_tuple	normalv;
	t_tuple	local_point;
	t_tuple	heightv;

	if (!obj->local_normalat)
		return (obj->normal);
	local_point = transform(obj->transform, world_point);
	normalv = obj->local_normalat(obj, local_point);\
	if (obj->matter.pattern.height_map.img_ptr)
	{
		heightv = height_normal(obj, world_point);
		if (tuple_equal(heightv, (t_tuple){0, 0, -1, 0}))
			return (tuple_normalize(normalv));
		normalv = tuple_add(normalv, heightv);
		normalv.w = 0;
		// normalv = tuple_normalize(normal_map(obj, local_point));
	}
	normalv = transform(matrix_transpose(obj->transform), normalv);
	normalv.w = 0;
	return (tuple_normalize(normalv));
}
