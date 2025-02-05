#include "quadtree_configuration.h"

bool    try_callback(t_conf* conf, t_moment m, t_entity e)
{
    if (conf->callbacks.call == NULL)
        return(true);
    return(conf->callbacks.call[m][e](conf));
}

void    quadtree_request_node_split(t_conf* conf)
{
    conf->current.node.ptr->split = true;
}

/*
 The height of the tree is calculated by taking the log
 of the number of pixels in the image and dividing it by
 the log of 4 (number of children of a node).
 The log of 4 is 2, and the log of the number of pixels
 is the height of the tree.
 The height of the tree is then rounded down to the nearest integer.
 Source : https://anubhavp.dev/blog/qtree.html
    // return (floor(log(width * height) / 2));
*/
size_t quadtree_comptute_depth_from_window_size(t_vec2i window_size)
{
    size_t min;

    min = window.size.y;
    if (window.size.y > window.size.x)
        min = window.size.y;
    return(ceil(log2(min)));
}