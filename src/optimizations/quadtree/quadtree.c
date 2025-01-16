#include "quadtree.h"
#include <stdio.h>

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
static size_t quadtree_comptute_depth(t_vec2i window_size)
{
    size_t min;

    min = window_size.y;
    if (window_size.y > window_size.x)
        min = window_size.y;
    return (ceil(log2(min)));
}

/*
 Source: https://stackoverflow.com/questions/4846357/finding-size-of-perfect-quad-tree
*/
static size_t quadtree_compute_node_count(size_t depth)
{
    return ((pow(4, depth) - 1) / 3);
}

bool zbuffer_alloc(t_zbuffer* zbuffer, size_t size)
{
    zbuffer->size = size;
    zbuffer->buffer = ft_calloc(size, sizeof(t_quadtree));
    return(zbuffer->buffer != NULL);
}

bool quadtree_new(t_zbuffer* zbuffer, t_vec2i window_size)
{
    size_t      depth;
    size_t      node_count;
    t_quadtree* root;

    depth = quadtree_comptute_depth(window_size);
    node_count = quadtree_compute_node_count(depth);
    printf("width: %d height: %d depth: %ld node count: %ld\n", window_size.x, window_size.y, depth, node_count);
    if(zbuffer_alloc(zbuffer, node_count) == false)
        return (false);
    root = &zbuffer->buffer[0];
    root->depth = depth;
    root->zbuffer.size = zbuffer->size - 1;
    root->zbuffer.buffer = &zbuffer->buffer[1];
    root->window = (t_window){
        .size = window_size,
        .center = vec2f_floor(vec2i_scale(window_size, 0.5)),
    };
    quadtree_set_children(root);
    return (true);
}