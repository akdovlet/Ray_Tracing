/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:45:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/19 12:00:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"

int	get_position_value(double *f, char *str, int *i, int line)
{
	skip_whitespace(str, i);
	if (str[(*i)++] == ',')
	{
		skip_whitespace(str, i);
		if (is_valid(str[*i]))
		{
			*f = ak_atof(str, i);
			return (0);
		}
	}
	ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str);
	return (1);
}

int	get_position_first(double *f, char *str, int *i, int line)
{
	skip_whitespace(str, i);
	if (is_valid(str[*i]))
	{
		*f = ak_atof(str, i);
		return (0);
	}
	ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str);
	return (1);
}

int	get_position(t_tuple *t, char *str, int *i, int line)
{
	if (get_position_first(&t->x, str, i, line))
		return (1);
	if (get_position_value(&t->y, str, i, line))
		return (1);
	if (get_position_value(&t->z, str, i, line))
		return (1);
	t->w = 1;
	return (0);
}
