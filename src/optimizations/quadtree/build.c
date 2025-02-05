#include "quadtree_configuration.h"

inline bool build_node(t_conf* conf)
{
    t_quadtree_node *node;

    node = conf->current.node.ptr;

    // set node
    node->height = conf->height;
    node->depth = conf->depth - conf->height;
    // node->position = conf->local_index; ??

    // set root
    node->parent = conf->buffer;
    node->parent += (conf->index - 1) / 4;

    // quadtree_set_child(conf); instead split
    quadtree_set_window(conf);
    conf->local_index += 1;
    conf->index += 1;
    conf->global_index += 1;
    return(true);
}

inline bool build_layer(t_conf* conf)
{
    return (quadtree_travers(conf, NODE, build_node));
}

inline bool build_quadtree(t_conf* conf)
{
    return (quadtree_travers(conf, LAYER, build_layer));
}

bool        build(t_vec2s window_size, t_conf_callbacks callbacks, void* data)
{
    static t_conf  conf = {};

    conf.data = data;
    conf.callbacks = callbacks;
    conf.window_size = window_size;
    conf.max_depth = quadtree_comptute_depth_from_window_size(window_size);
    if (quadtree_new(&conf.quadtree, conf.max_depth))
        return(false);

    quadtree_prepare_neighbors_mask(conf);
    

    conf.travers[LAYER].reset = reset_travers_layer;
    conf.travers[LAYER].next = next_layer;

    conf.travers[NODE].reset = reset_travers_node;
    conf.travers[NODE].next = next_node;

    conf.travers[NEIGHBOR].reset = reset_travers_neighbor;
    conf.travers[NEIGHBOR].next = next_neighbor;
    return(build_quadtree(&conf));
}