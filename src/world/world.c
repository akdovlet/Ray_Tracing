/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:43:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/04 18:49:39 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"
#include "tuple.h"
#include "objects.h"

t_world	default_world(void);
t_junction	intersect_world(t_world world, t_ray ray);

t_world	default_world(void)
{
	t_world		world;
	t_object	objects[2];

	world.light = point_light(point_new(-10, 10, -10), color_new(1, 1, 1));
	objects[0] = sphere(point_new(0.0, 0.0, 0.0), 1);
	objects[0].matter = material();
	objects[0].matter = (t_material) {
		.color = color_new(0.8, 1.0, 0.6),
		.diffuse = 0.7,
		.specular = 0.2
		};
	objects[1] = sphere(point_new(0.0, 0.0, 0.0), 1);
	objects[1].transform = (scale(0.5, 0.5 , 0.5));
	objects[1].matter = material();
	world.obj = objects;
	world.obj_count = 2;
	return (world);
}

t_world	new_world(t_light light, t_object *obj)
{
	return ((t_world){
		.light = light,
		.obj = obj,
	});
}

t_junction	sort_hits(t_junction hits)
{
	int	i;
	int	j;
	float	tmp;

	i = 0;
	while (i < hits.count)
	{
		j = i + 1;
		while (j < hits.count)
		{
			if (hits.t[i] > hits.t[j])
			{
				tmp = hits.t[i];
				hits.t[i] = hits.t[j];
				hits.t[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (hits);
}

t_junction	intersect_world(t_world world, t_ray ray)
{
	int				i;
	t_intersection	inter;
	t_junction		hits;

	i = 0;
	hits.count = 0;
	while (i < world.obj_count)
	{
		inter = hit(intersection(world.obj[i], intersect(ray, world.obj[i])));
		if (inter.count)
		{
			hits.t[i] = inter.t;
			hits.count++;
		}
		i++;
	}
	return (sort_hits(hits));
}
