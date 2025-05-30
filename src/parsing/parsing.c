/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:56:26 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/29 13:21:34 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

void	skip_whitespace(char *str, int *i)
{
	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
}

int	parse_line(char *str, t_world *world, t_parse *parse, int line)
{
	int	i;

	i = 0;
	skip_whitespace(str, &i);
	parse->path_or_ray = world->path_or_ray;
	if (!ft_strncmp(str + i, "A", 1))
		return (ambient_light(str + i + 1, world, line));
	else if (!ft_strncmp(str + i, "C", 1))
		return (camera(str + i + 1, &world->cam, line));
	else if (!ft_strncmp(str + i, "L", 1))
		return (light(str + i + 1, parse, line));
	else if (!ft_strncmp(str + i, "sp", 2))
		return (sphere(str + i + 2, parse, line));
	else if (!ft_strncmp(str, "pl", 2))
		return (plane(str + i + 2, parse, line));
	else if (!ft_strncmp(str, "cy", 2))
		return (cylinder(str + i + 2, parse, line));
	else if (!ft_strncmp(str, "cu", 2))
		return (cube(str + i + 2, parse, line));
	else if (!ft_strncmp(str, "co", 2))
		return (cone(str + i + 2, parse, line));
	else
		return (0);
}

int	parse_scene(char **strs, t_world *world, t_parse *parse)
{
	char	*buff;
	int		fd;
	int		line;
	int		error;

	*world = (t_world){};
	*parse = (t_parse){};
	fd = check_file(strs[1]);
	if (fd < 0)
		return (1);
	world->path_or_ray = check_flag(strs[2]);
	line = 0;
	error = 0;
	while (++line)
	{
		buff = gnl_no_nl(fd);
		if (!buff)
			break ;
		error = parse_line(buff, world, parse, line);
		free(buff);
		if (error)
			break ;
	}
	return (error);
}
