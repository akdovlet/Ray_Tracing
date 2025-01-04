/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:36:31 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/04 15:44:18 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersection	*inter_new(t_intersection inter)
{
	t_intersection	*new;
	
	new = malloc(sizeof(t_intersection));
	if (!new)
		return (NULL);
	*new = inter;
	return (new);
}

void	inter_addback(t_intersection **lst, t_intersection *new)
{
	t_intersection	*tmp;

	if (*lst)
	{
		*lst = new;
	}
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
