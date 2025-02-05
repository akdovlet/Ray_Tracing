#include "graphics.h"
#include "objects.h"
#include <stdlib.h>

bool is_comps(t_comps* comps, t_env* env, t_vec2i pixel_position)
{
	t_ray		ray;
	t_junction	hits;

	ray = ray_for_pixel(env->camera, pixel_position);
	if(intersect_world(env->world, ray, &hits) == false)
		return (false);
	(*comps) = pre_compute(hits.cross[0], ray);
	return (true);
}

typedef struct s_finder {
	int object[20];
	int object_seen;
	size_t current_depth;

	t_env* env;
} t_finder;

static bool is_same_object(t_finder* finder, uintptr_t object_id)
{
	int			index;
	int			max;
	t_shape*	object;

	max = finder->env->world.obj_count;
	object = finder->env->world.obj;
	index = 0;
	while(index <= max)
	{
		if (object[index].id == object_id && finder->object[index] == 0)
		{
			finder->object[index] = 1;
			finder->object_seen -= 1;
			return true;
		}
		index += 1;
	}
	return false;
}

void debug_find_object(t_quadtree_node* quadtree, t_color color)
{
	put_circle(quadtree->window.center, 3, color);

    // t_vec2i b = local_position_to_absolute_vec2i(quadtree->position, quadtree->height);
	// printf("absolute position: [%d %d]\n",
	// 	b.x, b.y);

	// printf("position: %ld center[%d, %d] height: %ld\n",
	// 	quadtree->position,
	// 	quadtree->window.center.x, quadtree->window.center.y,
	// 	quadtree->height);
}

bool find_object(t_quadtree_node* quadtree, void* data)
{
	t_finder*	finder;
	t_comps		comps;

	finder = (t_finder*)data;

	if (is_comps(&comps, finder->env, quadtree->window.center))
	{
		if(is_same_object(finder, comps.obj.id))
		{
			debug_find_object(quadtree, tuple_tocolor(color_new(0, 1, 0)));
			quadtree->shape_id = comps.obj.id;
		} else{

			debug_find_object(quadtree, tuple_tocolor(color_new(0, 0, 1)));
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
