/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:52:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/12 19:27:59 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	container_last(t_container *lst)
{
	if (!lst)
		return (1.0);
	while (lst->next)
		lst = lst->next;
	return (lst->shape->matter.refractive_index);
}

t_container	*container_new(t_shape *shape)
{
	t_container	*new;

	new = malloc(sizeof(t_container));
	if (!new)
		return (NULL);
	new->shape = shape;
	new->next = NULL;
	return (new);
}


void	container_remove(t_container **lst, t_shape *shape)
{
	t_container	*current;
	t_container	*last;

	current = *lst;
	last = *lst;
	if (current && current->shape->id == shape->id)
	{
		current = (*lst)->next;
		free(*lst);
		*lst = current;
		return ;
	}
	while (current && current->shape->id != shape->id)
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

void	find_n1n2(t_comps *comps, t_junction arr)
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

void	pre_compute(t_comps *new, t_crossing cross, t_ray ray, t_junction arr)
{
	new->t = cross.t;
	new->obj = cross.obj;
	new->world_point = position(ray, cross.t);
	new->eyev = -ray.direction;
	new->normalv = normal_at(*new->obj, new->world_point);
	if (tuple_dot(new->normalv, new->eyev) < 0.0)
	{
		new->inside = true;
		new->normalv = -new->normalv;
	}
	else
		new->inside = false;
	new->overz = new->normalv * 0.0001;
	new->overz = new->overz + new->world_point;
	new->reflectv = reflect(ray.direction, new->normalv);
	if (cross.obj->matter.transparency)
	{
		find_n1n2(new, arr);
		new->under_point = new->world_point - new->normalv * 0.0001;
	}
}
