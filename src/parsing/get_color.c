/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:50:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 18:04:43 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include <float.h>

int	get_color_value(double *f, char *str, int *i, int line)
{
	char		*error;
	static int	first;

	skip_whitespace(str, i);
	if (!first++ || str[(*i)++] == ',')
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

int	get_color(char *str, int *i, t_tuple *tuple, int line)
{
	if (get_color_value(&tuple->x, str, i, line))
		return (1);
	if (get_color_value(&tuple->y, str, i, line))
		return (1);
	if (get_color_value(&tuple->z, str, i, line))
		return (1);
	return (0);
}
