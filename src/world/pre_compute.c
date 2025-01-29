/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:52:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/29 17:13:58 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// double	container_last(t_container *lst)
// {
// 	if (!lst)
// 		return (1.0);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst->shape.matter.refractive_index);
// }

t_container	*container_new(t_shape shape)
{
	t_container	*new;

	new = malloc(sizeof(t_container));
	new->shape = shape;
	new->next = NULL;
	return (new);
}


void	container_remove(t_container **lst, t_shape shape)
{
	t_container	*current;
	t_container	*last;

	current = *lst;
	last = *lst;
	if (current && current->shape.id == shape.id)
	{
		current = (*lst)->next;
		free(*lst);
		*lst = current;
		return ;
	}
	while (current && current->shape.id != shape.id)
	{
		last = current;
		current = current->next;
	}
	if (!current)
	{
		if (!last)
			*lst = container_new(shape);
		else
			last->next = container_new(shape);
		return ;	
	}
	last->next = current->next;
	free(current);
}

void	container_clear(t_container **lst)
{
	t_container	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
/*
void	find_n1n2(t_comps *comps, t_junction arr, t_world *world)
{
	int			i;
	t_container	*lst;

	i = 0;
	lst = NULL;
	while (i < arr.count)
	{
		if (arr.cross[i].t == comps->t)
				comps->n1 = container_last(lst);
		container_remove(&lst, arr.cross[i].obj);
		if (arr.cross[i].t == comps->t)
		{
			comps->n2 = container_last(lst);
			break ;
		}
		i++;
	}
	container_clear(&lst);
}
*/

void	find_n1n2(t_comps *comps, t_junction arr, t_world *world)
{
	int			i;
	t_shape		obj;

	world->intersect_lst.count = 0;
	i = 0;
	while (i < arr.count)
	{
		if (arr.cross[i].t == comps->t)
		{
			if(world->intersect_lst.count == 0)
				comps->n1 = 1.0;
			else
				comps->n1 = world->intersect_lst.buffer[world->intersect_lst.count-1].matter.refractive_index;	
		}
		size_t y = 0;
		while(y < world->intersect_lst.count)
		{
			obj = world->obj[arr.cross[i].shape_index];
			if (obj.id == world->intersect_lst.buffer[y].id)
			{
				ft_memmove(
					&world->intersect_lst.buffer[y + 1],
					&world->intersect_lst.buffer[y], 
					world->intersect_lst.count - y);
				world->intersect_lst.count -= 1;
			}
			else
			{
				world->intersect_lst.buffer[world->intersect_lst.count-1] = obj;
				world->intersect_lst.count += 1;
			}
			y += 1;
		}
		if (arr.cross[i].t == comps->t)
		{
			if(world->intersect_lst.count == 0)
				comps->n2 = 1.0;
			else
				comps->n2 = world->intersect_lst.buffer[world->intersect_lst.count-1].matter.refractive_index;
			break;	
		}
		i++;
	}
}

void	pre_compute(t_comps *new, t_crossing cross, t_ray ray, t_junction arr, t_world *world)
{
	new->t = cross.t;
	new->shape_index = cross.shape_index;
	new->world_point = position(ray, cross.t);
	new->eyev = tuple_negate(ray.direction);
	new->normalv = normal_at(world->obj[cross.shape_index], new->world_point);
	if (tuple_dot(new->normalv, new->eyev) < 0.0)
	{
		new->inside = true;
		new->normalv = tuple_negate(new->normalv);
	}
	else
		new->inside = false;
	new->overz = tuple_multiply(new->normalv, 0.0001);
	new->overz = tuple_add(new->overz, new->world_point);
	new->reflectv = reflect(ray.direction, new->normalv);
	if (world->obj[cross.shape_index].matter.transparency)
	{
		find_n1n2(new, arr, world);
		new->under_point = tuple_substract(new->world_point, tuple_multiply(new->normalv, 0.00001));
	}
}
