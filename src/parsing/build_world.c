/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:19:55 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/28 21:45:53 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "parsing.h"
#include "libft.h"
#include "mlx.h"
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

int	load_bump_maps(t_world *world, t_mlx *mlx)
{
	int		i;
	t_shape	*obj;
	t_img	*img;

	i = -1;
	while (++i < world->obj_count)
	{
		obj = &world->obj[i];
		if (!obj->matter.pattern.bump_path[0])
			continue ;
		img = &obj->matter.pattern.height_map;
		img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
				obj->matter.pattern.bump_path,
				&img->img_width, &img->img_height);
		if (!img->img_ptr)
			return (ft_dprintf(2, "Error: failed to load bump map: `%s'\n",
					obj->matter.pattern.bump_path), 1);
		img->addr = mlx_get_data_addr(img->img_ptr,
				&img->bits_per_pixel, &img->line_length, &img->endian);
	}
	return (0);
}

int	build_world(char **strs, t_world *world)
{
	t_parse	parse;

	if (parse_scene(strs, world, &parse))
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
	return (0);
}
