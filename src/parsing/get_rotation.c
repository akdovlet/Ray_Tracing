/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:43:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 19:46:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include <float.h>

int	get_angle(double *f, char *str, int *i, int line)
{
	char	*error;

	skip_whitespace(str, i);
	if (str[(*i)++] == ',')
	{
		skip_whitespace(str, i);
		if (is_valid(str[*i]))
		{
			*f = ak_atof(str, i);
			if (*f > 360 || *f < 0)
			{
				error = "Error: line %d: value %f exceeds [0-360] range\n";
				return (ft_dprintf(2, error, line, *f), 1);
			}
			return (0);
		}
	}
	ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str);
	return (1);
}

int	get_angle_first(double *f, char *str, int *i, int line)
{
	char		*error;

	skip_whitespace(str, i);
	if (is_valid(str[*i]))
	{
		*f = ak_atof(str, i);
		if (*f > 360 || *f < 0)
		{
			error = "Error: line %d: value %f exceeds [0-360] range\n";
			return (ft_dprintf(2, error, line, *f), 1);
		}
		return (0);
	}
	ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str);
	return (1);
}

int	get_rotation(t_tuple *t, char *str, int *i, int line)
{
	if (get_angle_first(&t->x, str, i, line))
		return (1);
	if (get_angle(&t->y, str, i, line))
		return (1);
	if (get_angle(&t->z, str, i, line))
		return (1);
	return (0);
}
