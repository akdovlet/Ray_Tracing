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

static double	height_at(t_img *img, int x, int y)
{
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= img->img_width)
		x = img->img_width - 1;
	if (y >= img->img_height)
		y = img->img_height - 1;
	return ((double)((pixel_at(img, x, y) >> 16) & 0xFF));
}

t_tuple	height_normal(t_shape *obj, t_tuple local_point)
{
	t_img	*img;
	t_vec2f	uv;
	int		px;
	int		py;
	double	dh_du;
	double	dh_dv;
	t_tuple	tangent_n;
	t_tuple	T;
	t_tuple	B;
	t_tuple	N;

	img = &obj->matter.pattern.height_map;
	uv = obj->matter.pattern.uv_mapping(local_point);
	px = (int)round(uv.x * img->img_width);
	py = (int)round(img->img_height - uv.y * img->img_height);
	dh_du = height_at(img, px + 1, py) - height_at(img, px - 1, py);
	dh_dv = height_at(img, px, py + 1) - height_at(img, px, py - 1);
	tangent_n = tuple_normalize(vector_new(-dh_du, -dh_dv, 255.0));
	N = tuple_normalize(obj->local_normalat(obj, local_point));
	T = obj->local_tangent(obj, local_point);
	B = tuple_normalize(tuple_cross(N, T));
	return (tuple_normalize(
		tuple_add(tuple_add(
			tuple_multiply(T, tangent_n.x),
			tuple_multiply(B, tangent_n.y)),
			tuple_multiply(N, tangent_n.z))));
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

t_tuple	geom_normal_at(t_shape *obj, t_tuple world_point)
{
	t_tuple	normalv;
	t_tuple	local_point;

	if (!obj->local_normalat)
		return (obj->normal);
	local_point = transform(obj->transform, world_point);
	normalv = obj->local_normalat(obj, local_point);
	normalv = transform(matrix_transpose(obj->transform), normalv);
	normalv.w = 0;
	return (tuple_normalize(normalv));
}

t_tuple	normal_at(t_shape *obj, t_tuple world_point)
{
	t_tuple	normalv;
	t_tuple	local_point;

	if (!obj->local_normalat)
		return (obj->normal);
	local_point = transform(obj->transform, world_point);
	normalv = obj->local_normalat(obj, local_point);
	if (obj->matter.pattern.height_map.img_ptr && obj->local_tangent)
		normalv = height_normal(obj, local_point);
	normalv = transform(matrix_transpose(obj->transform), normalv);
	normalv.w = 0;
	return (tuple_normalize(normalv));
}
