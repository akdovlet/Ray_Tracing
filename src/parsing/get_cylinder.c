/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:09:40 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 19:31:13 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include "shapes.h"

int	get_height(t_shape *shape, char *str, int *i, int line)
{
	double	height;

	skip_whitespace(str, i);
	if (!is_valid(str[*i]))
		return (bad_syntax(line, str, 1));
	height = ak_atof(str, i);
	shape->min = -height / 2.0;
	shape->max = height / 2.0;
	return (0);
}

int	get_cylinder_values(t_shape *cyl, char *str, int *i, int line)
{
	if (get_position(&cyl->coordinates, str, i, line))
	return (1);
	if (get_normalv(&cyl->normal, str, i, line))
		return (1);
	if (get_radius(&cyl->radius, str, i, line))
		return (1);
	if (get_height(cyl, str, i, line))
		return (1);
	if (get_color(&cyl->color, str, i, line))
		return (1);
	return (0);
}

int	cylinder(char *str, t_parse *parse, int line)
{
	int		i;
	t_shape	cyl;

	i = 0;
	cyl = cylinder_default();
	skip_whitespace(str, &i);
	if (is_valid(str[i]))
	{
		if (get_cylinder_values(&cyl, str, &i, line))
			return (1);		
	}
	else
		return (ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str),
			1);
	if (add_object(&parse->obj, &cyl))
		return (1);
	parse->obj_count++;
	return (0);
}
