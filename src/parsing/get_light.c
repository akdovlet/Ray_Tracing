/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:22:56 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 18:04:24 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include "tuple.h"
#include <stdio.h>

int	get_light_intensity(double *f, char *str, int *i, int line)
{
	char	*err;

	skip_whitespace(str, i);
	if (!is_valid(str[*i]))
		return (bad_syntax(line, str, 1));
	*f = ak_atof(str, i);
	if (*f > 1.0 || *f < 0.0)
	{
		err = "Error: line %d: value %f exceeds [0.0,1.0] range\n";
		return (ft_dprintf(2, err, line, *f), 1);		 
	}
	return (0);
}

int	add_light(t_lightlst **lst, t_light *light)
{
	t_lightlst	*new;
	t_lightlst	*tmp;

	new = malloc(sizeof(t_lightlst));
	if (!new)
		return (perror("Error: add_light"), 1);
	new->light = *light;
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

void	clear_light(t_lightlst **lst)
{
	t_lightlst	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	light(char *str, t_parse *parse, int line)
{
	int			i;
	double		divider;
	t_light		light;

	i = 0;
	skip_whitespace(str, &i);
	if (is_valid(str[i]))
	{
		if (get_light_position(&light.position, str, &i, line))
			return (1);
		if (get_light_intensity(&divider, str, &i, line))
			return (1);
		if (get_light_color(&light.intensity, str, &i, line))
			return (1);
	}
	else
		return (ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str),
			1);
	if (divider)
		light.intensity = tuple_divide(light.intensity, divider);
	if (add_light(&parse->light, &light))
		return (1);
	parse->light_count++;
	return (0);
}
