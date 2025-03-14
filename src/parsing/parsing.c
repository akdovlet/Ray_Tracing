/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:56:26 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/14 16:36:31 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_tuple(char *str, int *i, t_tuple *tuple)
{
	tuple->x = ak_atof(str, i);
	if (str[*i] == ',')
		(*i)++;
	else
	{
		ft_dprintf(STDERR_FILENO, "Error: bad syntax: `%s'\n", str);
		return (1);
	}
	tuple->y = ak_atof(str, i);
	if (str[*i] == ',')
		(*i)++;
	else
	{
		ft_dprintf(STDERR_FILENO, "Error: bad syntax: `%s'\n", str);
		return (1);
	}
	tuple->z = ak_atof(str, i);
	return (0);
}

int	ambient_light(char *str, t_world *world)
{
	int	i;
	int	data;
	
	data = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else if (ft_isdigit(str[i]))
		{
			if (!data)
			{
				world->sky.intensity = ak_atof(str, &i);
				data++;
			}
			if (data == 1)
			{
				if (parse_tuple(str, &i, &world->sky.color))
					return (1);
				data++;
			}
		}
		else
			return (ft_dprintf(2, "Error: bad syntax: `%s'\n", str),1);
	}
	return (0);
}

int	add_object(char *str, t_world *world)
{
	if (!ft_strncmp(str, "A", 1))
	{
		return (ambient_light(str + 1, world));
	}
	// else if (ft_strncmp(str, "L", 1))
	// 	return (light());
	// else if (ft_strncmp(str, "C", 1))
	// 	return (camera());
	// else if (ft_strncmp(str, "sp", 2))
	// 	return (sphere());
	// else if (ft_strncmp(str, "pl", 2))
	// 	return (plane());
	// else if (ft_strncmp(str, "cy", 2))
	// 	return (cylinder());
	// else if (ft_strncmp(str, "cu", 2))
	// 	return (cube());
	// else if (ft_strncmp(str, "co", 2))
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
		ft_dprintf(2, "Error: `%s': Wrong file format\n", str);
		return (-1);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_dprintf(2, "Error: `%s': %s\n", str, strerror(errno));
	return (fd);
}

int	parse_scene(char *str, t_world *world)
{
	char	*buff;
	int		fd;
	// int		error;

	*world = (t_world){};
	fd = check_file(str);
	if (fd < 0)
		return (1);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (add_object(buff, world))
		{
			free(buff);
			continue;
		}
	}
	return (0);
}
