/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:55:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/03 14:46:19 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include "tuple.h"

int	get_sky_intensity(double *f, char *str, int *i, int line)
{
	char	*err;

	err = "Error: line %d: value %f exceeds [0-1] range\n";
	*f = ak_atof(str, i);
	if (*f > 1.0 || *f < 0.0)
		return (ft_dprintf(2, err, line, *f), 1);
	return (0);
}

int	ambient_light(char *str, t_world *world, int line)
{
	int			i;
	static int	data;

	if (data)
		return (ft_dprintf(2, "Error: line %d: excess ambient light\n", line),
			1);
	i = 0;
	skip_whitespace(str, &i);
	if (is_valid(str[i]))
	{
		if (get_sky_intensity(&world->sky.intensity, str, &i, line))
			return (1);
		if (get_color(&world->sky.color, str, &i, line))
			return (1);
	}
	else
		return (ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str),
			1);
	world->sky.color = tuple_multiply(world->sky.color, world->sky.intensity);
	data++;
	return (0);
}
