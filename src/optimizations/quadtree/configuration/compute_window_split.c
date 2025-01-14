#include "quadtree_configuration.h"

static void compute_window_axes_split(size_t original, size_t* a, size_t* b)
{
    unsigned char offset;

    offset = (original % 2);
    (*a) = (original - offset) / 2;
    (*b) = (*a) + offset;
}

void pre_compute_window_split(t_conf* conf)
{
    compute_window_axes_split(conf->root->window.width, &conf->widths[1], &conf->widths[2]);
    compute_window_axes_split(conf->root->window.height, &conf->heights[1], &conf->heights[2]);
}

void quadtree_compute_window_child(t_conf* conf)
{
    t_quadtree* root;
    t_quadtree* child;

    root = conf->root;
    child = get_current_child(conf);
    child->window = (t_window){
        .width = conf->widths[conf->pos.x + 1],
        .height = conf->heights[conf->pos.y + 1],
        .offset_x = root->window.offset_x + conf->widths[conf->pos.x],
        .offset_y = root->window.offset_y + conf->heights[conf->pos.y],
    };
    child->window.center_x = child->window.offset_x + floor(child->window.width / 2);
    child->window.center_y = child->window.offset_y + floor(child->window.height / 2);
}