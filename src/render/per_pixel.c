/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:32:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/15 20:32:16 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"

t_ray	per_pixel(t_camera cam, double x, double y)
{
	double	world_y;
	double	world_x;
	t_tuple	pixel;
	t_ray	ray;

	world_x = cam.half_width - ((x + 0.5) * cam.psize);
	world_y = cam.half_height - ((y + 0.5) * cam.psize);
	pixel = matrix_multiply_tuple(cam.transform, point_new(world_x, world_y, -1));
	ray.origin = matrix_multiply_tuple(cam.transform, point_new(0, 0, 0));
	ray.direction = tuple_normalize(tuple_substract(pixel, ray.origin));
	return (ray);
}

