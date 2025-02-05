#include "optimizations.h"
#include "quadtree_configuration.h"
#include "graphics.h"
#include "light.h"

typedef struct s_ambiguity {
	t_env*		env;
	uintptr_t	shape_id;
} t_ambiguity;

bool is_ambiguity(t_conf *conf)
{
	t_ambiguity	*ambiguity;
	t_comps		comps;

	ambiguity = (t_ambiguity*)conf->data;
    if(conf->current.node.ptr->shape_id == 0)
        return(false);
	if (is_comps(&comps, ambiguity->env, conf->current.node.ptr->window.center))
		conf->current.node.ptr->shape_id = comps.obj.id;
	return (conf->current.node.ptr->shape_id == ambiguity->shape_id);
}

bool    build_node(t_conf *conf, t_callback next)
{
    conf->window.center = vec2i_scale(conf->window.size, 0.5);
    if(next(conf) == false)
        return(false);
    conf->window.size = conf->window.center;
    conf->height += 1;
}
bool    build_layer(t_conf* conf, t_callback next)
{
    if(next(conf) == false)
        return(false);
/*
    for each node in layer, if any neighbors different from current node
    request split

    if(quadtree_node_travers_neighbors(conf, is_ambiguity))
        //assign shape id
    else
        quadtree_request_node_split(conf);
*/
}

void quadtree()
{
    static t_conf_callbacks callbacks = {};

    while(next_layer(conf))
    {
        while(next_node(conf))
        {
            //build it?
        }
        while(next_node(conf))
        {
            while(next_neighbor(conf))
            {
                if(current->node.id != current->neighbor.id)
                {
                    request_split(current->node);
                    break;
                }
            }
        }
    }
    build_quadtree((t_vec2s){600,600}, callbacks, NULL);
}

/*
#include "optimizations.h"

void quadtree_resolve_border(t_env* env)
{
	// quadtree_find_object(env);
	quadtree_traverse(env->quadtree, resolve_ambiguity, env);
}
*/