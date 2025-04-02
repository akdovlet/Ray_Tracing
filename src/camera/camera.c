/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:17:18 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 22:09:58 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	camera_new(double hsize, double vsize, double fov)
{
	t_camera	cam;
	double		aspect_ratio;
	double		half_view;

	half_view = tan(fov / 2.0);
	aspect_ratio = hsize / vsize;
	if (aspect_ratio >= 1)
	{
		cam.half_width = half_view;
		cam.half_height = half_view / aspect_ratio;
	}
	else
	{
		cam.half_width = half_view * aspect_ratio;
		cam.half_height = half_view;
	}
	cam.hsize = hsize;
	cam.fov = fov;
	cam.half_view = half_view;
	cam.vsize = vsize;
	cam.psize = (cam.half_width * 2) / cam.hsize;
	cam.transform = identity();
	cam.cam_distance = 1.0 / tan(fov * 0.5 * M_PI / 180.0);
	return (cam);
}

void	cam_update(t_camera *cam, t_tuple from, t_tuple to, t_tuple up)
{
	cam->from = from;
	cam->to = to;
	cam->up = up;
	cam->view = view_transform(from, to, up, cam);
	cam->transform = inverse(cam->view);
}
