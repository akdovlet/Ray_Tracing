/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normalv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:54:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 22:00:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include <float.h>

int	get_normalv_value(double *f, char *str, int *i, int line)
{
	char		*error;

	skip_whitespace(str, i);
	if (str[(*i)++] == ',')
	{
		skip_whitespace(str, i);
		if (is_valid(str[*i]))
		{
			*f = ak_atof(str, i);
			if (*f > 1.0 || *f < -1.0)
			{
				error = "Error: line %d: value %f exceeds [-1,1] range\n";
				return (ft_dprintf(2, error, line, *f), 1);
			}
			return (0);
		}
	}
	ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str);
	return (1);
}

int	get_normalv_first(double *f, char *str, int *i, int line)
{
	char		*error;

	skip_whitespace(str, i);
	if (is_valid(str[*i]))
	{
		*f = ak_atof(str, i);
		if (*f > 1.0 || *f < -1.0)
		{
			error = "Error: line %d: value %f exceeds [-1,1] range\n";
			return (ft_dprintf(2, error, line, *f), 1);
		}
		return (0);
	}
	ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str);
	return (1);
}

int	get_normalv(t_tuple *t, char *str, int *i, int line)
{
	if (get_normalv_first(&t->x, str, i, line))
		return (1);
	if (get_normalv_value(&t->y, str, i, line))
		return (1);
	if (get_normalv_value(&t->z, str, i, line))
		return (1);
	t->w = 0;
	return (0);
}
