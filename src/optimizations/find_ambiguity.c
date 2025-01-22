#include "graphics.h"
#include "objects.h"
#include "light.h"

#include <stdlib.h>

void debug_window(t_window window, t_color color)
{
	put_circle(window.center, 1, color);
	// put_pixel(window.center, color);
	// put_rectangle(window.offset, window.size, color);
	put_rectangle_line(window.offset, window.size, color);
}

void	assign_shape_id(t_quadtree* quadtree, t_env* env)
{
	t_comps	comps;

	if (quadtree->shape_id != 0)
		return;
	if (is_comps(&comps, env, quadtree->window.center))
		quadtree->shape_id = comps.obj.id;
}

typedef struct s_ambiguity {
	t_env*		env;
	uintptr_t	shape_id;
} t_ambiguity;

/*
bool is_ambiguity(t_quadtree* quadtree, void* data)
{
	t_ambiguity*	ambiguity;
	t_comps			comps;
	t_color			color;

	ambiguity = (t_ambiguity*)data;
	if (ambiguity->shape_id == 0)
	{
		if (is_comps(&comps, ambiguity->env, quadtree->window.center))
			quadtree->shape_id = comps.obj.id;
	}
	if (quadtree->shape_id == ambiguity->shape_id)
	{
		color = tuple_tocolor(shade_hit(ambiguity->env->world, comps));
		debug_window(quadtree->window, color);
		return (true);
	}
	quadtree_split(quadtree);
	return (false);
}
*/

bool is_ambiguity(t_quadtree* quadtree, void* data)
{
	t_ambiguity*	ambiguity;
	t_comps			comps;

	ambiguity = (t_ambiguity*)data;
	if (!quadtree->shape_id && is_comps(&comps, ambiguity->env, quadtree->window.center))
		quadtree->shape_id = comps.obj.id;
	// assign_shape_id(quadtree, ambiguity->env);
	return (quadtree->shape_id == ambiguity->shape_id);
}

bool resolve_ambiguity(t_quadtree* quadtree, void* data)
{
	t_ambiguity	ambiguity;
	t_color		color;
	t_comps		comps;

	if (quadtree->height > 8)
		return (false);


	ambiguity.env = (t_env*)data;
	if (!quadtree->shape_id && is_comps(&comps, ambiguity.env, quadtree->window.center))
		quadtree->shape_id = comps.obj.id;
	// assign_shape_id(quadtree, ambiguity.env);
	ambiguity.shape_id = quadtree->shape_id;

	if(quadtree_check_neighbors(quadtree, is_ambiguity, &ambiguity))
	{
		// color = tuple_tocolor(color_new(0, 1 / quadtree->depth, 0));
		// color = tuple_tocolor(shade_hit(ambiguity.env->world, comps));
		// debug_window(quadtree->window, color);
	}
	else
	{
		quadtree->shape_id = 0;
		quadtree_split(quadtree);
	}
	// int a = quadtree->shape_id % 5;
	// t_color colors[5] = {
	// 	tuple_tocolor(color_new(0, 0, 0)),
	// 	tuple_tocolor(color_new(0, 1, 0)),
	// 	tuple_tocolor(color_new(1, 0, 1)),
	// 	tuple_tocolor(color_new(0, 1, 1)),
	// 	tuple_tocolor(color_new(1, 0, 0)),
	// };
	// color = colors[a];
	color = tuple_tocolor(shade_hit(ambiguity.env->world, comps));
	debug_window(quadtree->window, color);
	return (true);
}