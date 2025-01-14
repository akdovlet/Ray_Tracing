#include "quadtree_configuration.h"

void quadtree_link_siblings_node(t_conf* conf)
{
    conf->current = get_current_child(conf);
    conf->current->siblings[PREV] = conf->prev;
    if (conf->current->siblings[PREV])
        conf->current->siblings[PREV]->siblings[NEXT] = conf->current;
    conf->prev = conf->current;
}

void quadtree_link_neighbors_node(t_conf* conf)
{
    (void)conf;
    // size_t x;
    // size_t y;
    // t_quadtree* child;

    // x = conf->x;
    // y = conf->y;
    // child = conf->root->child[x][y];
    // if (!child->root)
    //     return;
    

}