#include "optimizations.h"
#include "light.h"

void debug_ambiguity(t_env* env, t_quadtree* quadtree)
{
	t_comps		comps;
	t_color		color;

	if (is_comps(&comps, env, quadtree) == false)
		return ;

	quadtree->shape_id = comps.obj.id;
	color = tuple_tocolor(shade_hit(env->world, comps));
	// put_pixel(quadtree->window.center, color);
	put_rectangle(quadtree->window.offset, quadtree->window.size, color);
	
	// color = tuple_tocolor(color_new(0, 1, 0));
	// put_pixel(child->window.center, color);
	// put_rectangle_line(child->window.offset, child->window.size, color);
}

bool t(t_quadtree* quadtree, void* data)
{
	t_env* env;

	env = (t_env*)data;
	(void)env;

	// if(is_ambiguity(quadtree))
		// debug_ambiguity(env, quadtree);
	printf("(%ld)[%d %d]\n", quadtree->depth, quadtree->pos.x, quadtree->pos.y);
	return (true);
}

void resolve_ambiguity(t_env* env, t_quadtree* quadtree)
{
	quadtree_traverse(quadtree, t, env);
	// if(is_ambiguity(quadtree))
	// {
	// 	debug_ambiguity(env, quadtree);
	// 	resolve_ambiguity(env, quadtree->childs[0][0]);
	// 	resolve_ambiguity(env, quadtree->childs[0][1]);
	// 	resolve_ambiguity(env, quadtree->childs[1][0]);
	// 	resolve_ambiguity(env, quadtree->childs[1][1]);
	// }
}

void quadtree_resolve_border(t_env* env)
{
	quadtree_find_object(env);
	// resolve_ambiguity(env, env->quadtree);
}
