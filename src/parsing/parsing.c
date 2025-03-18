/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:56:26 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 18:54:28 by akdovlet         ###   ########.fr       */
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

int	add_object(char *str, t_world *world, t_parse *parse, int line)
{
	int	i;

	i = 0;
	skip_whitespace(str, &i);
	if (!ft_strncmp(str + i, "A", 1))
		return (ambient_light(str + i + 1, world, line));
	else if (!ft_strncmp(str + i, "C", 1))
		return (camera(str + i + 1, &world->cam, line));
	else if (!ft_strncmp(str + i, "L", 1))
		return (light(str + i + 1, parse, line));
	else if (!ft_strncmp(str, "sp", 2))
		return (sphere());
	// else if (!ft_strncmp(str, "pl", 2))
	// 	return (plane());
	// else if (!ft_strncmp(str, "cy", 2))
	// 	return (cylinder());
	// else if (!ft_strncmp(str, "cu", 2))
	// 	return (cube());
	// else if (!ft_strncmp(str, "co", 2))
	// 	return (cone());
	else
		return (0);
}

int	check_extension(char *str, int len)
{
	if (str[len--] == 't' && str[len--] == 'r' && str[len] == '.')
		return (0);
	return (1);
}

int	check_file(char *str)
{
	int	len;
	int	fd;

	len = ft_strlen(str);
	if (len < 4 || check_extension(str, len - 1))
	{
		ft_dprintf(2, "Error: wrong file format: `%s'\n", str);
		return (-1);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_dprintf(2, "Error: %s: `%s'\n", strerror(errno), str);
	return (fd);
}

int	parse_scene(char *str, t_world *world, t_parse *parse)
{
	char	*buff;
	int		fd;
	int		line;
	int		error;

	*world = (t_world){};
	*parse = (t_parse){};
	fd = check_file(str);
	line = 0;
	error = 0;
	if (fd < 0)
		return (1);
	while (++line)
	{
		buff = gnl_no_nl(fd);
		if (!buff)
			break ;
		error = add_object(buff, world, parse, line);
		free(buff);
		if (error)
			break ;
	}
	return (error);
}
