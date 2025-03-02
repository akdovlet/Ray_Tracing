/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:28:04 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/02 16:55:33 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_in(double x, double y)
{
	if (x < 0 || x > WIDTH)
		return (0);
	if (y < 0 || y > HEIGHT)
		return (0);
	return (1);
}

int	mouse_manager(int button, int x, int y, t_data *data)
{
	v2	mouse_pos;
	// v2	delta;
	t_junction	hits;
	t_comps		comps;
	t_vec2		xs;
	mouse_pos[0] = x;
	mouse_pos[1] = y;
	if (button == 1)
	{
		intersect_world(&data->world, data->rays[x + y * WIDTH], &hits);
		if (hits.hit)
		{
			xs = hits.closest.obj->local_interesct(hits.closest.obj, data->rays[x + y * WIDTH]);
			pre_compute(&comps, hits.closest, data->rays[x + y * WIDTH], hits);
			printf("\ndis is: %f, x is: %f, y is: %f\n", xs.dis, xs.x, xs.y);
			printf("object id: %lu\n", hits.closest.obj->id);
			printf("hit point: %f\n", comps.t);
			printf("normal vector: ");
			tuple_print(comps.normalv);
			printf("world point: ");
			tuple_print(comps.world_point);
			// int winx = (int)round(((comps.world_point.x + 1) / 2.0) * WIDTH);
			// int winy = (int)round(((1 - comps.world_point.y) / 2.0) * HEIGHT);
			t_tuple local_point = matrix_multiply_tuple((data->cam.transform), comps.world_point);
			printf("local point: ");
			tuple_print(local_point);
			double winx = local_point.x / -local_point.z;
			double winy = local_point.y / -local_point.z;
			double nx = (winx + 2 / 2.0) / 2;
			double ny = (winy + 2 / 2.0) / 2;
			int rx = (int)floor(nx * 540.0);
			int ry = (int)floor((1.0 - ny) * 540.0);
			fprintf(stderr, "winx is: %f, winy is: %f\n", winx, winy);
			fprintf(stderr, "nx is: %f, ny is: %f\n", nx, ny);
			fprintf(stderr, "rx is: %d, ry is: %d\n", rx, ry);
			// while (is_in(point.x, point.y))
			// {
			// 	ak_mlx_pixel_put(&data->img, point.x, point.y, 0x0000FFFF);
			// 	point = tuple_add(point, comps.normalv);
			// }
		}
		else
		{
			printf("No hit\n");
		}
		
		return (0);
	}
	return (0);
}
