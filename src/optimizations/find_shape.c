#include "graphics.h"
#include "objects.h"
#include <stdlib.h>

bool is_comps(t_comps* comps, t_env* env, t_quadtree* quadtree)
{
	t_ray		ray;
	t_junction	hits;

	ray = ray_for_pixel(env->camera, quadtree->window.center);
	if(intersect_world(env->world, ray, &hits) == false)
		return (false);
	(*comps) = pre_compute(hits.cross[0], ray);
	return (true);
}

static bool is_same_object(int* remain, int* found, uintptr_t object_id, t_shape* object, int max)
{
	int index;

	index = 0;
	while(index <= max)
	{
		if (object[index].id == object_id && found[index] == 0)
		{
			found[index] = 1;
			(*remain) -= 1;
			return true;
		}
		index += 1;
	}
	return false;
}

void debug_find_object(t_quadtree* quadtree)
{
	put_circle(quadtree->window.center,
		tuple_tocolor(color_new(0, 0, 1)));

	printf("\tpos[%d, %d] depth: %ld\n", 
		quadtree->window.center.x, quadtree->window.center.y,
		quadtree->depth);
}

typedef struct s_finder {
	int object[20];
	int object_seen;
	size_t current_depth;

	t_env* env;
} t_finder;

bool find_object(t_quadtree* quadtree, void* data)
{
	t_finder*	finder;
	t_comps		comps;

	finder = (t_finder*)data;

	if (is_comps(&comps, finder->env, quadtree))
	{
		if(is_same_object(&finder->object_seen, finder->object, comps.obj.id, finder->env->world.obj, finder->env->world.obj_count))
		{
			debug_find_object(quadtree);
			quadtree->shape_id = comps.obj.id;
		}
	}
	finder->current_depth = quadtree->depth;
	return(finder->object_seen != 0);
}

void quadtree_find_object(t_env* env)
{
	t_finder finder;

	finder = (t_finder){
		.env = env,
		.object_seen = env->world.obj_count,
	};

	quadtree_traverse(env->quadtree, find_object, &finder);
	printf("end at depth %ld, object seen: %d\n", finder.current_depth, finder.object_seen);
}
