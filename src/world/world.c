/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:43:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 22:03:36 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"
#include "tuple.h"
#include "shapes.h"

void	sort_hits(t_junction *hits)
{
	int			i;
	int			j;
	t_crossing	tmp;


	i = 0;
	while (i < hits->count)
	{
		j = i + 1;
		while (j < hits->count)
		{
			if (hits->cross[i].t > hits->cross[j].t)
			{
				tmp = hits->cross[i];
				hits->cross[i] = hits->cross[j];
				hits->cross[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	find_hit(t_junction *hits)
{
	int	i;

	i = 0;
	hits->hit = false;
	while (i < hits->count)
	{
		if (hits->cross[i].t >= 0.0)
		{
			hits->closest = hits->cross[i];
			hits->hit = true;
			break ;
		}
		i++;
	}
}

void	intersect_world(t_world *world, t_ray ray, t_junction *hits)
{
	int				i;
	int				j;
	double			closest_t;
	t_intersection	inter;

	i = 0;
	j = 0;
	closest_t = FLT_MAX;
	hits->count = 0;
	hits->hit = false;
	while (i < world->obj_count)
	{
		hit(&inter, intersect(&world->obj[i], ray));
		if (inter.count)
		{
			hits->count += inter.count;
			hits->cross[j].t = inter.xs.x;
			hits->cross[j].obj = &world->obj[i];
			if (hits->cross[j].t >= 0.0 && hits->cross[j].t < closest_t)
			{
				hits->closest = hits->cross[j];
				hits->hit = true;
				closest_t = hits->cross[j].t;
			}
			j++;
			if (inter.count == 2)
			{
				hits->cross[j].t = inter.xs.y;
				hits->cross[j].obj = &world->obj[i];
				if (hits->cross[j].t >= 0.0 && hits->cross[j].t < closest_t)
				{
					hits->closest = hits->cross[j];
					hits->hit = true;
					closest_t = hits->cross[j].t;
				}
				j++;
			}
		}
		i++;
	}
	sort_hits(hits);
}

t_tuple	color_at(t_world *world, t_ray ray, int depth)
{
	t_tuple		color;
	t_comps		comps;
	t_junction	hits;

	color = tuple_multiply(world->sky.color, world->sky.intensity);
	if (!depth)
		return (color);
	intersect_world(world, ray, &hits);
	if (hits.hit)
	{
		pre_compute(&comps, hits.closest, ray, hits);
		color = shade_hit(world, &comps, depth);
	}
	return (color);
}
