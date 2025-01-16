#include "quadtree_configuration.h"

static void quadtree_link_siblings_node(t_conf* conf)
{
    conf->current = get_current_child(conf);
    conf->current->siblings[PREV] = conf->prev;
    if (conf->current->siblings[PREV])
        conf->current->siblings[PREV]->siblings[NEXT] = conf->current;
    conf->prev = conf->current;
}

void quadtree_link_node(t_conf* conf)
{
    quadtree_link_siblings_node(conf);
}