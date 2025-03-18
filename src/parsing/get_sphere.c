/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:05:35 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 18:54:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"

int	sphere(char *str, t_parse *parse, int line)
{
	int			i;
	double		divider;
	t_shape		sphere;

	i = 0;
	skip_whitespace(str, &i);
	if (is_valid(str[i]))
	{
		if (get_sphere_position(&sphere.coordinates, str, &i, line))
			return (1);
		if (get_sphere_radius(&divider, str, &i, line))
			return (1);
		if (get_sphere_color(&sphere.intensity, str, &i, line))
			return (1);
	}
	else
		return (ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str),
			1);
	if (divider)
		sphere.intensity = tuple_divide(sphere.intensity, divider);
	if (add_light(&parse->sphere, &sphere))
		return (1);
	parse->light_count++;
	return (0);
}
