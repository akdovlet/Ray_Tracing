#include "quadtree_configuration.h"

t_quadtree* get_current_child(t_conf* conf)
{
    if (conf)
        return (conf->root->child[conf->pos.x][conf->pos.y]);
    return (NULL);
}

void foreach_child(t_quadtree* root, t_fp_quadtree_builder builder)
{
    t_conf conf;

    conf = (t_conf){.root = root};
    conf.pos.x = 0;
    while(conf.pos.x < 2)
    {
        conf.pos.y = 0;
        while(conf.pos.y < 2)
        {
            builder(&conf);
            conf.pos.y += 1;
        }
        conf.pos.x += 1;
    }
}

void quadtree_set_children(t_quadtree* root)
{

    t_conf conf;

    if (root->depth == 0)
        return;
    // foreach_child(root, quadtree_assign_child);


    conf = (t_conf){.root = root};
    pre_compute_window_split(&conf);
    conf.z_buffer_size = root->zbuffer.size / 4;
    while (conf.pos.x < 2)
    {
        conf.pos.y = 0;
        while(conf.pos.y < 2)
        {
            quadtree_assign_child(&conf);
            quadtree_link_siblings_node(&conf);
            quadtree_link_neighbors_node(&conf);
            quadtree_compute_window_child(&conf);
            quadtree_set_children(root->child[conf.pos.x][conf.pos.y]);
            conf.pos.y += 1;
        }
        conf.pos.x += 1;
    }
}