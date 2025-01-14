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
	t_zbuffer	zbuffer;

	env = (t_env){
		.width = WIDTH,
		.height = HEIGHT,
		.title = "minirt",
	};
	scene(&env.camera, &env.world);
	if (quadtree_new(&zbuffer, WIDTH, HEIGHT) == false)
	{
		fprintf(stderr, "ERROR: The quadtree fail to be instanciated\n");
		exit(1);
	}
	env.root = &zbuffer.buffer[0];
	// quadtree_find_object(&env);
	loop(&env);

	// precompute_ray(&env);
	free(zbuffer.buffer);
	return (0);
}
