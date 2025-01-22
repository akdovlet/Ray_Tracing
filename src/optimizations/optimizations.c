#include "optimizations.h"

void quadtree_resolve_border(t_env* env)
{
	// quadtree_find_object(env);
	quadtree_traverse(env->quadtree, resolve_ambiguity, env);
}
