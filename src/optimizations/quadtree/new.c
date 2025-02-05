#include "quadtree.h"

bool    quadtree_alloc_layer(t_quadtree_layer* layer, size_t capacity)
{
    if (layer == NULL || capacity < 1)
        return (false);
    layer->size = 0;
    layer->capacity = capacity;
    layer->buffer = malloc(sizeof(t_quadtree_node) * capacity);
    return (layer->buffer != NULL);
}

bool    quadtree_alloc(t_quadtree* quadtree, size_t capacity)
{
    if (quadtree == NULL || capacity < 1)
        return (false);
    quadtree->size = size;
    quadtree->capacity = capacity;
    quadtree->buffer = malloc(sizeof(t_quadtree_layer) * capacity);
    return(quadtree->buffer != NULL):
}

bool    quadtree_add_layer(t_quadtree* quadtree, size_t layer_capacity)
{
    if (quadtree == NULL)
        return(false);
    if (quadtree->size >= quadtree->capacity)
        return(false);    
    if(quadtree_alloc_layer(&quadtree->buffer[quadtree->size], layer_capacity) == false)
        return(false);
    quadtree->size += 1;
    return(true);
}

bool    quadtree_new(t_quadtree* quadtree, size_t capacity)
{
    return (1
        && quadtree_alloc(quadtree, capacity)
        && quadtree_add_layer(quadtree, 1));
}