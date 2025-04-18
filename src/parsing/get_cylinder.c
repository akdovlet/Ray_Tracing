/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:09:40 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/18 14:42:55 by akdovlet         ###   ########.fr       */
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

t_matrix	rotate_axis(t_tuple normal)
{
	t_matrix mat;
	
	mat = rotate_x((normal.x * 360));
	mat = multiply_matrix(mat, rotate_y((normal.y * 360)));
	mat = multiply_matrix(mat, rotate_z((normal.z * 360)));
	return (mat);
}

t_matrix	apply_transform(t_tuple	position, t_tuple normal)
{
	return (multiply_matrix(t_translate(position), rotate_axis(normal)));
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
	set_transform(&cyl, apply_transform(cyl.coordinates, cyl.normal));
	tuple_print(cyl.normal);
	if (add_object(&parse->obj, &cyl))
		return (1);
	parse->obj_count++;
	return (0);
}
