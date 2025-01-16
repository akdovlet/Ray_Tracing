#include "quadtree_configuration.h"

void pre_compute_zbuffer_size(t_conf* conf)
{
    conf->z_buffer_size = conf->root->zbuffer.size / 4;
}

static void compute_zbuffer_offset(t_conf* conf)
{
    conf->z_buffer_offset = conf->z_buffer_size;
    conf->z_buffer_offset *= (conf->pos.x * 2) + conf->pos.y;
}

static void assign_child(t_conf* conf)
{
    conf->root->childs[conf->pos.x][conf->pos.y] = &conf->root->zbuffer.buffer[conf->z_buffer_offset];
}

static void assign_root(t_conf* conf)
{
    conf->root->childs[conf->pos.x][conf->pos.y]->root = conf->root;
    if (conf->root)
        conf->root->childs[conf->pos.x][conf->pos.y]->depth = conf->root->depth - 1;
}

static void set_zbuffer(t_conf* conf)
{
    t_quadtree* child;

    child = get_current_child(conf);
    child->zbuffer.size = conf->z_buffer_size - 1;
    child->zbuffer.buffer = &conf->root->zbuffer.buffer[1] + conf->z_buffer_offset;
}

void quadtree_assign_child(t_conf* conf)
{
    compute_zbuffer_offset(conf);
    assign_child(conf);
    assign_root(conf);
    set_zbuffer(conf);
}