/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:25:43 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 19:48:20 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include "shapes.h"

int	get_cube_values(t_shape *cube, char *str, int *i, int line)
{
	t_tuple		cs;
	t_tuple		rot;
	t_matrix	m;

	if (get_position(&cube->coordinates, str, i, line))
	return (1);
	if (get_position(&cs, str, i, line))
		return (1);
	if (get_rotation(&rot, str, i, line))
		return (1);
	if (get_color(&cube->color, str, i, line))
		return (1);
	m = multiply_matrix(translate(rot.x, rot.y, rot.z), scale(cs.x, cs.y, cs.z));
	set_transform(cube, m);
	return (0);
}

int	cube(char *str, t_parse *parse, int line)
{
	int		i;
	t_shape	cube;

	i = 0;
	cube = cube_default();
	skip_whitespace(str, &i);
	if (is_valid(str[i]))
	{
		if (get_cube_values(&cube, str, &i, line))
			return (1);
	}
	else
		return (ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str),
			1);
	if (add_object(&parse->obj, &cube))
		return (1);
	parse->obj_count++;
	return (0);
}
