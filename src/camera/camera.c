/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:17:18 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/05 18:24:31 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	camera_new(float hsize, float vsize, float fov)
{
	t_camera	cam;
	float		aspect_ratio;
	float		half_view;

	half_view = tanf(fov / 2.0f);
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
	return (cam);
}
