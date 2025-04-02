/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:49:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 19:00:17 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include "shapes.h"

int	plane(char *str, t_parse *parse, int line)
{
	int		i;
	t_shape	plane;

	i = 0;
	plane = plane_default();
	skip_whitespace(str, &i);
	if (is_valid(str[i]))
	{
		if (get_position(&plane.coordinates, str, &i, line))
			return (1);
		if (get_normalv(&plane.normal, str, &i, line))
			return (1);
		if (get_color(&plane.color, str, &i, line))
			return (1);
	}
	else
		return (ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str),
			1);
	if (add_object(&parse->obj, &plane))
		return (1);
	parse->obj_count++;
	return (0);
}
