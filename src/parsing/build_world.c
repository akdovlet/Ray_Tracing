/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:19:55 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 21:26:05 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "parsing.h"
#include "libft.h"
#include <stdio.h>

void	eat_obj(t_objlst **node)
{
	t_objlst	*tmp;

	tmp = (*node)->next;
	free(*node);
	*node = tmp;
}

void	eat_light(t_lightlst **node)
{
	t_lightlst	*tmp;

	tmp = (*node)->next;
	free(*node);
	*node = tmp;
}

int	build_objects(t_world *world, t_parse *parse)
{
	int	i;

	i = 0;
	if (!parse->obj_count)
		return (0);
	world->obj = malloc(sizeof(t_shape) * parse->obj_count);
	if (!world->obj)
	{
		perror("Error: build_objects");
		return (1);
	}
	world->obj_count = parse->obj_count;
	while (parse->obj)
	{
		world->obj[i] = parse->obj->obj;
		eat_obj(&parse->obj);
		i++;
	}
	return (0);
}

int	build_lights(t_world *world, t_parse *parse)
{
	int	i;

	i = 0;
	if (!parse->light_count)
		return (0);
	world->light = malloc(sizeof(t_light) * parse->light_count);
	if (!world->light)
	{
		perror("Error: build_lights");
		return (1);
	}
	world->light_count = parse->light_count;
	while (parse->light)
	{
		world->light[i] = parse->light->light;
		eat_light(&parse->light);
		i++;
	}
	return (0);
}

int	build_world(char *str, t_world *world)
{
	t_parse	parse;

	if (parse_scene(str, world, &parse))
	{
		clear_lights(&parse.light);
		clear_objects(&parse.obj);
		return (1);
	}
	if (build_objects(world, &parse))
	{
		clear_lights(&parse.light);
		clear_objects(&parse.obj);
		return (1);
	}
	if (build_lights(world, &parse))
	{
		clear_lights(&parse.light);
		clear_objects(&parse.obj);
		return (free(world->obj), 1);
	}
	printf("light: %d, obj: %d\n", world->light_count, world->obj_count);
	return (0);
}
