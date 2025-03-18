/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:21:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 18:03:30 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"

int	get_camera_direction_value(double *f, char *str, int *i, int line)
{
	char		*error;
	static int	first;

	skip_whitespace(str, i);
	if (!first++ || str[(*i)++] == ',')
	{
		skip_whitespace(str, i);
		if (is_valid(str[*i]))
		{
			*f = ak_atof(str, i);
			if (*f > 1.0 || *f < -1.0)
			{
				error = "Error: line %d: value %f exceeds [-1,1] range\n";
				return (ft_dprintf(2, error, line, *f), 1);
			}
			return (0);
		}
	}
	ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str);
	return (1);
}

int	get_camera_direction(t_tuple *t, char *str, int *i, int line)
{
	if (get_camera_direction_value(&t->x, str, i, line))
		return (1);
	if (get_camera_direction_value(&t->y, str, i, line))
		return (1);
	if (get_camera_direction_value(&t->z, str, i, line))
		return (1);
	return (0);
}

int	camera(char *str, t_camera *cam, int line)
{
	int			i;
	static int	data;

	if (data)
		return (ft_dprintf(2, "Error: line %d: excess camera\n", line),
			1);
	i = 0;
	skip_whitespace(str, &i);
	if (is_valid(str[i]))
	{
		if (get_position(&cam->from, str, &i, line))
			return (1);
		if (get_camera_direction(&cam->to, str, &i, line))
			return (1);
		if (get_camera_fov(&cam->fov, str, &i, line))
			return (1);
	}
	else
		return (ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str),
			1);
	data++;
	return (0);
}
