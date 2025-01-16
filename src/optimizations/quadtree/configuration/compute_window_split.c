#include "quadtree_configuration.h"

static void compute_window_axes_split(int original, int* a, int* b)
{
    unsigned char offset;

    offset = (original % 2);
    (*a) = (original - offset) / 2;
    (*b) = (*a) + offset;
}

void pre_compute_window_split(t_conf* conf)
{
    compute_window_axes_split(conf->root->window.size.x, &conf->window_size[1].x, &conf->window_size[2].x);
    compute_window_axes_split(conf->root->window.size.y, &conf->window_size[1].y, &conf->window_size[2].y);
}

void quadtree_compute_window_child(t_conf* conf)
{
    t_quadtree* root;
    t_quadtree* child;
    t_vec2i     size;

    root = conf->root;
    child = get_current_child(conf);
    size = (t_vec2i){
        .x = conf->window_size[conf->pos.x + 1].x,
        .y = conf->window_size[conf->pos.y + 1].y,
    };
    child->window = (t_window){
        .size = size,
        .offset = vec2i_add(
            root->window.offset,
            (t_vec2i){
                .x = conf->window_size[conf->pos.x].x,
                .y = conf->window_size[conf->pos.y].y,
            }),
    };
    child->window.center = vec2i_add(child->window.offset, vec2f_floor(vec2i_scale(child->window.size, 0.5)));
}