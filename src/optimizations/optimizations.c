#include "optimizations.h"

void resolve_ambiguity(t_env* env, t_quadtree* quadtree)
{
	t_comps		comps;
	t_vec2i		pos;
	t_quadtree*	child;

	if(is_ambiguity(quadtree) == false)
		return;

	pos.y = 0;
	while (pos.y < 2)
	{
		pos.x = 0;
		while (pos.x < 2)
		{
			child = quadtree->childs[pos.x][pos.y];
			if (is_comps(&comps, env, child))
			{
				child->shape_id = comps.obj.id;
				put_pixel(child->window.center, tuple_tocolor(color_new(0, 1, 0)));
				// put_ixel(pixel_position, color_at(env->world, ray_for_pixel(env->camera, pixel_position)));
			}
			pos.x += 1;
		}
		pos.y += 1;
	}

	if(is_ambiguity(quadtree))
	{
		resolve_ambiguity(env, quadtree->childs[0][0]);
		resolve_ambiguity(env, quadtree->childs[0][1]);
		resolve_ambiguity(env, quadtree->childs[1][0]);
		resolve_ambiguity(env, quadtree->childs[1][1]);
		return;
	}
}

void quadtree_resolve_border(t_env* env)
{
	quadtree_find_object(env);
	resolve_ambiguity(env, env->quadtree);
}
