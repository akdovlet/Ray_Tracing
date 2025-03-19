/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:05:35 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/19 11:52:22 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include "shapes.h"

int	get_sphere_radius(double *f, char *str, int *i, int line)
{
	skip_whitespace(str, i);
	if (!is_valid(str[*i]))
		return (bad_syntax(line, str, 1));
	*f = ak_atof(str, i);
	*f /= 2;
	return (0);
}

void	set_sph_values(t_shape *obj, t_tuple coord, double radius)
{
	obj->coordinates = coord;
	set_transform(obj, multiply_matrix(translate(coord.x, coord.y, coord.z),
			scale(radius, radius, radius)));
}

int	sphere(char *str, t_parse *parse, int line)
{
	int		i;
	double	radius;
	t_tuple	coord;
	t_shape	sphere;

	i = 0;
	sphere = sphere_default();
	skip_whitespace(str, &i);
	if (is_valid(str[i]))
	{
		if (get_position(&coord, str, &i, line))
			return (1);
		if (get_sphere_radius(&radius, str, &i, line))
			return (1);
		if (get_color(&sphere.color, str, &i, line))
			return (1);
	}
	else
		return (ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str),
			1);
	set_sph_values(&sphere, coord, radius);
	if (add_object(&parse->obj, &sphere))
		return (1);
	parse->obj_count++;
	return (0);
}
