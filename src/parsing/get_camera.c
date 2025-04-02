/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:21:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 22:01:17 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "shapes.h"
#include "parsing.h"

int	camera(char *str, t_camera *cam, int line)
{
	int			i;
	t_tuple		from;
	t_tuple		to;
	static int	data;

	if (data)
		return (ft_dprintf(2, "Error: line %d: excess camera\n", line),
			1);
	i = 0;
	skip_whitespace(str, &i);
	if (is_valid(str[i]))
	{
		if (get_position(&from, str, &i, line))
			return (1);
		if (get_normalv(&to, str, &i, line))
			return (1);
		if (get_camera_fov(&cam->fov, str, &i, line))
			return (1);
	}
	else
		return (ft_dprintf(2, "Error: line %d: bad syntax: `%s'\n", line, str),
			1);
	*cam = camera_new(WIDTH, HEIGHT, radians(cam->fov));
	cam_update(cam, from, to, vector_new(0, 1, 1));
	data++;
	return (0);
}
