#include "graphics.h"
#include "objects.h"
#include <stdlib.h>

/*
void precompute_ray(t_env* env)
{
	int	y;
	int	x;
	int	i;
    int size;
    t_ray   ray;
    t_ray*   tmp;

    size = (env->camera.vsize * env->camera.hsize);
    size *= env->world.obj_count;
    env->precomputed_ray = malloc(size * sizeof(t_ray));
    i = 0;
	y = 0;
    tmp = env->precomputed_ray;
	while (y < env->camera.vsize)
	{
		x = 0;
		while (x < env->camera.hsize)
		{
            ray = ray_for_pixel(env->camera, x, y);
            i = 0;
            while(i < env->world.obj_count)
            {
                (*tmp) = ray_transform(ray, env->world.obj[i].transform);
                tmp += 1;
                i++;
            }
			x++;
		}
		y++;
	}
}
*/


bool is_same_object(int* remain, int* found, uintptr_t object_id, t_shape* object, int max)
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

bool is_comps(t_comps* comps, t_env* env, t_ray ray)
{
	t_junction	hits;

	if(intersect_world(env->world, ray, &hits) == false)
		return (false);
	(*comps) = pre_compute(hits.cross[0], ray);
	return (true);
}

void quadtree_find_object(t_env* env)
{
	t_ray		ray;
	t_comps		comps;
	t_quadtree* current;
	t_siblings	next_sibling;
	int object[20] = {0};
	int object_seen;

	current = env->root;
	object_seen = env->world.obj_count;
	next_sibling = NEXT;
	while(42)
	{
		ray = ray_for_pixel(env->camera, current->window.center_x, current->window.center_y);
		// put_circle(current->window.center_x, current->window.center_y, tuple_tocolor(color_new(0,1,0)));

		if (is_comps(&comps, env, ray))
		{
			if(is_same_object(&object_seen, object, comps.obj.id, env->world.obj, env->world.obj_count))
			{
				put_circle(
					current->window.center_x,
					current->window.center_y,
					tuple_tocolor(color_new(0, 0, 1)));
				printf("\tpos[%ld, %ld] depth: %ld\n", 
				current->window.center_x, current->window.center_y,
				current->depth);
			}
		} 

		if (object_seen == 0 || (!current->siblings[next_sibling] && !current->depth))
			break;

		if (current->siblings[next_sibling])
			current = current->siblings[next_sibling];
		else
		{
			if (next_sibling == NEXT)
			{
				current = current->child[1][1];
				next_sibling = PREV;
			}
			else
			{
				current = current->child[0][0];
				next_sibling = NEXT;
			}
		}
	}
	printf("end at depth %ld, object seen: %d\n", current->depth, object_seen);
}

