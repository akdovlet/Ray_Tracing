#include "quadtree_configuration.h"

void    quadtree_prepare_neighbors_mask(t_conf* conf)
{
    size_t  index;
    size_t  shift_by;

    index = 0;
    while(index < conf->max_depth)
    {
        shift_by = index * 2;
        conf->neighbor_mask.value[X] |= (0x01 << shift_by);
        conf->neighbor_mask.value[Y] |= (0x02 << shift_by);
        index += 1;
    }
}

static size_t compute_equal_level_neighbors_position(t_quadtree_node* node, size_t neighbor_index)
{
    size_t  shift_by;
    size_t  position;
    size_t  mask;

    position = node->position;
    mask = direction_mask(neighbor_index);
    shift_by = 2 * node->height;
    mask <<= shift_by;
    return (quad_location_addition_operator(position, mask));
}

static size_t compute_non_equal_level_neighbors_position(t_quadtree_node* node, size_t neighbor_index)
{
    size_t  shift_by;
    size_t  position;
    size_t  mask;

    position = node->position;
    mask = direction_mask(neighbor_index);
    shift_by = 2 * (node->height - node->neighbors[neighbor_index].level);
    position = (position >> shift_by) << shift_by;
    mask <<= shift_by;
    return (quad_location_addition_operator(position, mask));
}

static size_t compute_neighbors_position(t_quadtree_node* node, size_t neighbor_index)
{
    size_t  result;

    if (node->neighbors[neighbor_index].level < 0)
        result = compute_non_equal_level_neighbors_position(node, neighbor_index);
    else
        result = compute_equal_level_neighbors_position(node, neighbor_index);
    return (result);
}

void    quadtree_node_set_neighbor(t_conf *conf)
{
    size_t layer_index;
    size_t position;

    // fix finding position
    layer_index = conf->current.neighbor.layer_idx;
    position = conf->current.neighbor.position;
    conf->current.neighbor.ptr = &conf->quadtree.buffer[layer_index].buffer[position];
}

bool    quadtree_node_have_neighbor(t_conf *conf, t_direction direction)
{
    t_neighbors neighbor;
    size_t      layer_index;
    size_t      neighbor_position;

    neighbor = conf->current.node.ptr->neighbors[direction];
    if(neighbor.exist == false)
        return(false);
    conf->current.neighbor.layer_idx = conf->current.layer.idx + neighbor.level;
    conf->current.neighbor.position = compute_neighbors_position(conf->current.node.ptr, direction);
    quadtree_node_set_neighbor(conf, layer_index, neighbor_position);
    return (true);
}
