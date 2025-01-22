#include "quadtree.h"
#include "quadtree_configuration.h"

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
static void quadtree_comptute_depth(t_conf* conf)
{
    size_t min;

    min = conf->window.size.y;
    if (conf->window.size.y > conf->window.size.x)
        min = conf->window.size.y;
    conf->depth = ceil(log2(min)) + 1;
}

/*
 Source: https://stackoverflow.com/questions/4846357/finding-size-of-perfect-quad-tree
*/
static void quadtree_compute_node_count(t_conf* conf)
{
    conf->node_count = (pow(4, conf->depth) - 1) / 3;
}

static void quadtree_alloc_nodes(t_conf* conf)
{
    conf->buffer = ft_calloc(sizeof(t_quadtree), conf->node_count);
}

t_quadtree* quadtree_new(t_vec2i window_size)
{
    t_conf  conf;

    conf = (t_conf){
        .window.size = window_size,
    };
    quadtree_comptute_depth(&conf);
    quadtree_compute_node_count(&conf);
    quadtree_alloc_nodes(&conf);
    if (conf.buffer == NULL)
        return(NULL);
    quadtree_init(&conf);
    return (conf.buffer);
}