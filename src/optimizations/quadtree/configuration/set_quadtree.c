#include "quadtree_configuration.h"

t_quadtree* get_current_child(t_conf* conf)
{
    if (conf)
        return (conf->root->childs[conf->pos.x][conf->pos.y]);
    return (NULL);
}

static void foreach_child(t_conf* conf, t_fp_quadtree_builder builder)
{
    conf->pos.x = 0;
    while(conf->pos.x < 2)
    {
        conf->pos.y = 0;
        while(conf->pos.y < 2)
        {
            builder(conf);
            conf->pos.y += 1;
        }
        conf->pos.x += 1;
    }
}

static void set_children(t_conf* conf)
{
    quadtree_set_children(conf->root->childs[conf->pos.x][conf->pos.y]);
}


void quadtree_set_children(t_quadtree* root)
{
    t_conf conf;

    if (root->depth == 0)
        return;
    conf = (t_conf){.root = root};

    pre_compute_zbuffer_size(&conf);
    foreach_child(&conf, quadtree_assign_child);

    foreach_child(&conf, quadtree_link_node);

    pre_compute_window_split(&conf);
    foreach_child(&conf, quadtree_compute_window_child);

    foreach_child(&conf, set_children);
}