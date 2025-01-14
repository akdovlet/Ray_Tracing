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
	if (exec_one != 0)
		return;
	exec_one += 1;

	int	y;
	int	x;

	y = -1;
	while (y++ < env->camera.vsize)
	{
		x = -1;
		while (x++ < env->camera.hsize)
			put_pixel(x, y, color_at(env->world, ray_for_pixel(env->camera, x, y)));
		progression(y, env->camera.vsize);
	}
	quadtree_find_object(env);
}