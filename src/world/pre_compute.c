/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:52:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/19 16:31:06 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_container	*container_last(t_container *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_container	*container_new(t_shape shape)
{
	t_container	*new;

	new = malloc(sizeof(t_container));
	new->shape = shape;
	new->next = NULL;
	return (new);
}

void	container_append(t_container **lst, t_container *new)
{
	if (!*lst)
	{
		*lst = new;
	}
	else
		container_last(*lst)->next = new;
}

void	container_remove(t_container **lst, t_shape shape)
{
	t_container	*curr;
	t_container	*tmp;
	t_container	*last;

	if (!*lst)
		return ;
	curr = *lst;
	last = curr;
	while (curr)
	{
		if (curr->shape.id == shape.id)
		{
			tmp = curr->next;
			free(tmp);
			last->next = tmp;
			return ;
		}
		last = curr;
		curr = curr->next;
	}
}

void	build_containers(t_comps *comps, t_container **lst, t_junction arr)
{
	int		i;

	i = 0;
	while (i < arr.count)
	{
		if (arr.cross[i].t == arr.cross[0].t)
		{
			if (!*lst)
				comps->n1 = 1.0;
			else
				comps->n1 = container_last(*lst)->shape.matter.refractive_index;
		}
		i++;
	}
}

// t_tuple	refracted_color(t_world world, t_comps comps, int remaining)
// {
// 	if (!remaining || !comps.obj.matter.transparency)
// 		return (color_new(0, 0, 0));
	
// }

t_comps	pre_compute(t_crossing cross, t_ray ray, t_junction arr)
{
	t_comps		new;
	t_container	*lst;

	lst = NULL;
	(void)arr;
	new.t = cross.t;
	new.obj = cross.obj;
	new.world_point = position(ray, cross.t);
	new.eyev = tuple_negate(ray.direction);
	new.normalv = normal_at(new.obj, new.world_point);
	if (tuple_dot(new.normalv, new.eyev) < 0.0)
	{
		new.inside = true;
		new.normalv = tuple_negate(new.normalv);
	}
	else
		new.inside = false;
	new.overz = tuple_multiply(new.normalv, 0.00001);
	new.overz = tuple_add(new.overz, new.world_point);
	new.reflectv = reflect(ray.direction, new.normalv);
	// build_containers(&new, &lst, arr);
	return (new);
}
