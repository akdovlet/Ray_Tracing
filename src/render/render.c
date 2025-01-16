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

// #include "minirt.h"
#include "tuple.h"
#include "objects.h"

#include "optimizations.h"


static float yy = 0;
void	progression(int progression, int max)
{
	float percentage;
	
	percentage = progression/max;
	if (percentage > yy + 0.1) {
		yy = percentage;
		printf("%f/100\n", (yy) * 100);
	}
}

static int exec_one = 0;
void	render(t_env* env)
{
	t_vec2i	pixel_position;

	if (exec_one != 0)
		return;
	exec_one += 1;

	pixel_position.y = 0;
	while (pixel_position.y < env->camera.vsize)
	{
		pixel_position.x = 0;
		while (pixel_position.x < env->camera.hsize)
		{
			put_pixel(pixel_position, color_at(env->world, ray_for_pixel(env->camera, pixel_position)));
			pixel_position.x += 1;
		}
		progression(pixel_position.y, env->camera.vsize);
		pixel_position.y += 1;
	}
	quadtree_resolve_border(env);
}