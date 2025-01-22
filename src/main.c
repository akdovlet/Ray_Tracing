/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/10 20:13:59 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "optimizations.h"

int main()
{
	t_env		env;
	t_vec2i		window_size;

	window_size = (t_vec2i){
		.x = WIDTH,
		.y = HEIGHT,
	};

	env = (t_env){
		.width = WIDTH,
		.height = HEIGHT,
		.title = "minirt",
	};
	scene(&env.camera, &env.world);
	env.quadtree = quadtree_new(window_size);
	if (env.quadtree == NULL)
	{
		fprintf(stderr, "ERROR: The quadtree fail to be instanciated\n");
		exit(1);
	}
	// quadtree_resolve_border(&env);

	// size_t depth = env.quadtree->depth;
	// int y = 0;
	// for(int i = 0; i < 81000 ; i++)
	// {
	// 	if (depth != env.quadtree[i].depth)
	// 	{
	// 		printf("%d (%ld) [%d %d]\n", y, depth, env.quadtree[i].window.size.x, env.quadtree[i].window.size.y);
	// 		depth = env.quadtree[i].depth;
	// 		y = 0;
	// 	}
	// 	y += 1;
	// }
	env.quadtree->parent = NULL;
	loop(&env);
	free(env.quadtree);
	return (0);
}