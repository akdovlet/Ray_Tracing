/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:48:33 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 17:49:32 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include "colors.h"
#include <float.h>

int	get_light_color_first(double *f, char *str, int *i, int line)
{
	char		*error;

	skip_whitespace(str, i);
	if (is_valid(str[*i]))
	{
		*f = ak_atof(str, i);
		if (*f > 255.0 || *f < 0.0)
		{
			error = "Error: line %d: value %f exceeds [0-255] range\n";
			return (ft_dprintf(2, error, line, *f), 1);
		}
		if (*f > DBL_EPSILON)
			*f = *f / 255.0;
		return (0);
	}
	ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str);
	return (1);
}

int	get_light_color_value(double *f, char *str, int *i, int line)
{
	char		*error;

	skip_whitespace(str, i);
	if (str[(*i)++] == ',')
	{
		skip_whitespace(str, i);
		if (ft_isdigit(str[*i]) || str[*i] == '.')
		{
			*f = ak_atof(str, i);
			if (*f > 255.0 || *f < 0.0)
			{
				error = "Error: line %d: value %f exceeds [0-255] range\n";
				return (ft_dprintf(2, error, line, *f), 1);
			}
			if (*f > DBL_EPSILON)
				*f = *f / 255.0;
			return (0);
		}
	}
	ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str);
	return (1);
}

int	get_light_color(t_tuple *t, char *str, int *i, int line)
{
	skip_whitespace(str, i);
	if (!str[*i])
		return (*t = white(), 0);
	if (get_light_color_first(&t->x, str, i, line))
		return (1);
	if (get_light_color_value(&t->y, str, i, line))
		return (1);
	if (get_light_color_value(&t->z, str, i, line))
		return (1);
	t->w = 0;
	return (0);
}
