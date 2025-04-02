/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:50:23 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 20:10:29 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include "shapes.h"

int	get_minmax_value(double *f, char *str, int *i, int line)
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

int	get_minmax_first(double *f, char *str, int *i, int line)
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

int	get_minmax(t_shape *shape, char *str, int *i, int line)
{
	if (get_minmax_first(&shape->min, str, i, line))
		return (1);
	if (get_minmax_value(&shape->max, str, i, line))
		return (1);
	return (0);
}

int	get_cone_values(t_shape *cone, char *str, int *i, int line)
{
	t_tuple		cs;
	t_tuple		rot;
	t_matrix	m;

	if (get_position(&cone->coordinates, str, i, line))
	return (1);
	if (get_position(&cs, str, i, line))
		return (1);
	if (get_rotation(&rot, str, i, line))
		return (1);
	if (get_minmax(cone, str, i, line))
		return (1);
	if (get_color(&cone->color, str, i, line))
		return (1);
	m = multiply_matrix(t_translate(cone->coordinates), rotate_x(rot.x));
	m = multiply_matrix(m, rotate_y(rot.y));
	m = multiply_matrix(m, rotate_z(rot.z));
	m = multiply_matrix(m, t_scale(cs));
	set_transform(cone, m);
	return (0);
}

int	cone(char *str, t_parse *parse, int line)
{
	int		i;
	t_shape	cone;

	i = 0;
	cone = cone_default();
	skip_whitespace(str, &i);
	if (is_valid(str[i]))
	{
		if (get_cone_values(&cone, str, &i, line))
			return (1);
	}
	else
		return (ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str),
			1);
	if (add_object(&parse->obj, &cone))
		return (1);
	parse->obj_count++;
	return (0);
}
