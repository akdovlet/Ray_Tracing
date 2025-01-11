/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:22:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/09 16:45:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "graphics.h"
#include "tuple.h"
#include "objects.h"

t_ray	ray_for_pixel(t_camera cam, float x, float y)
{
	float	world_y;
	float	world_x;
	t_tuple	pixel;
	t_ray	ray;

	world_x = cam.half_width - ((x + 0.5) * cam.psize);
	world_y = cam.half_height - ((y + 0.5) * cam.psize);
	pixel = matrix_multiply_tuple(cam.transform, point_new(world_x, world_y, -1));
	ray.origin = matrix_multiply_tuple(cam.transform, point_new(0, 0, 0));
	ray.direction = tuple_normalize(tuple_substract(pixel, ray.origin));
	return (ray);
}

static float yy = 0;
void	render(t_camera* camera, t_world* world)
{
	int	y;
	int	x;
	t_ray	ray;
	t_color	color;
	y = 0;
	while (y < camera->vsize)
	{
		x = 0;
		while (x < camera->hsize)
		{
			ray = ray_for_pixel(*camera, x, y);
			color = tuple_tocolor(color_at(*world, ray));
			put_pixel(x, y, color);
			x++;
		}
		y++;
		float tmp = y/camera->vsize;
		if (tmp > yy + 0.1) {
			yy = tmp;
			printf("%f/100\n", (yy) * 100);
		}
	}
}
