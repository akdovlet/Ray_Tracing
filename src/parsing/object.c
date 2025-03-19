/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:51:56 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/19 11:56:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int	add_object(t_objlst **lst, t_shape *obj)
{
	t_objlst	*new;
	t_objlst	*tmp;

	new = malloc(sizeof(t_objlst));
	if (!new)
		return (perror("Error: add_object"), 1);
	new->obj = *obj;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

void	clear_objects(t_objlst **lst)
{
	t_objlst	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
