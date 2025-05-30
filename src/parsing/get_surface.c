/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:44:48 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/28 21:36:34 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include "shapes.h"

int	get_specular(double *f, char *str, int *i, int line)
{
	skip_whitespace(str, i);
	if (!is_valid(str[*i]))
		return (bad_syntax(line, str, 1));
	*f = ak_atof(str, i);
	if (*f < 0 || *f > 1.0)
	{
		ft_dprintf(2, "Error: line %d: value %f exceeds [0-1] range\n", line,
			*f);
		return (1);
	}
	return (0);
}

int	get_emission(double *f, char *str, int *i, int line)
{
	skip_whitespace(str, i);
	if (!is_valid(str[*i]))
		return (bad_syntax(line, str, 1));
	*f = ak_atof(str, i);
	if (*f < 0)
	{
		ft_dprintf(2, "Error: line %d: value %f is negative\n", line,
			*f);
		return (1);
	}
	return (0);
}

int	get_surface_info(t_shape *obj, char *str, int *i, int line)
{
	if (get_color(&obj->color, str, i, line))
		return (1);
	if (get_specular(&obj->s_prob, str, i, line))
		return (1);
	if (get_emission(&obj->e_power, str, i, line))
		return (1);
	return (0);
}
