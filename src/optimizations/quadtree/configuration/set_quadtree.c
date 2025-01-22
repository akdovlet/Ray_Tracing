#include "quadtree_configuration.h"

t_vec2i local_position_to_local_vec2i(size_t local_position)
{
    return ((t_vec2i){
        .x = (local_position >> 0) & 1,
        .y = (local_position >> 1) & 1,
    });
}

t_vec2i local_position_to_absolute_vec2i(size_t local_position, size_t height)
{
    size_t  index;
    t_vec2i output;

        
    output = (t_vec2i){0 , 0};
    index = 0;
    while (index < height)
    {
        output.x |= ((local_position >> 0) & 1) << index;
        output.y |= ((local_position >> 1) & 1) << index;
        local_position = local_position >> 2;
        index += 1;
    }
    return (output);
}


void quadtree_set_pos(t_conf* conf)
{
    t_quadtree* node;

    node = &conf->buffer[conf->index];
    node->height = conf->height;
    node->depth = conf->depth - conf->height;
    // node->position = conf->local_index;
    node->position = conf->global_index;
}

void compute_neighbors_mask(t_conf* conf)
{
    conf->neighbor_mask[X] = (conf->neighbor_mask[X] << 2) | 0x01;
    conf->neighbor_mask[Y] = (conf->neighbor_mask[Y] << 2) | 0x02;
}

size_t quad_location_addition_operator(t_conf* conf, size_t location_code, size_t direction_increment)
{
    size_t      index_mask;
    size_t      position_mask[MAX_V];

    index_mask = 0;
    while(index_mask < MAX_V)
    {
        position_mask[index_mask] = location_code;
        position_mask[index_mask] |= conf->neighbor_mask[!index_mask];
        position_mask[index_mask] += (direction_increment & conf->neighbor_mask[index_mask]);
        position_mask[index_mask] &= conf->neighbor_mask[index_mask];
        index_mask += 1;
    }
    return (position_mask[X] + position_mask[Y]);
}

size_t  direction_mask(t_direction direction)
{
    static size_t masks[MAX_DIRECTION] = {
        000001, 000011, 000010, 010111,
        010101, 111111, 101010, 101011,
    };
    return (masks[direction]);
}

char*  direction_name(t_direction direction)
{
    static char* names[MAX_DIRECTION] = {
        [0] = "EAST",
        [1] = "NORTH_EAST",
        [2] = "NORTH",
        [3] = "NORTH_WEST",
        [4] = "WEST",
        [5] = "SOUTH_WEST",
        [6] = "SOUTH",
        [7] = "SOUTH_EAST",
    };
    return (names[direction]);
}

void compute_neighbors(t_conf* conf)
{
    t_quadtree* node;
    size_t      mask;
    size_t      index;

    node = &conf->buffer[conf->index];
    index = 0;
    while(index < MAX_DIRECTION)
    {
        mask = direction_mask(index);
        node->neighbors[index].position = quad_location_addition_operator(conf, node->position, mask);
        // node->neighbors[index].position = quad_location_addition_operator(conf, conf->local_index, mask);
        index += 1;
    }
    /*
    Calculation of neighbors of equal size
    direction = direction_mask[index_direction] << (2 * node->depth); 
    node->neighbors[index_direction] = quad_location_addition_operator(conf, node->position, direction);
    */
}



void quadtree_set_root(t_conf* conf)
{
    t_quadtree* node;

    node = &conf->buffer[conf->index];
    node->parent = conf->buffer;
    node->parent += (conf->index - 1) / 4;
}

void quadtree_set_child(t_conf* conf)
{
    size_t      index;
    size_t      child_index;
    t_quadtree* node;

    node = &conf->buffer[conf->index];
    child_index = 1 + (conf->index * 4);
    index = 0;
    while(index < 4)
    {
        node->childs[index] = conf->buffer + (child_index + index);
        index += 1;
    }
}
#include <stdio.h>

void quadtree_set_window(t_conf* conf)
{
    t_quadtree* node;

    node = &conf->buffer[conf->index];
    node->window = conf->window;
    node->window.offset = vec2i_multiply(node->window.size,
        local_position_to_absolute_vec2i(conf->local_index, node->height)); //the local_index is a hack!!
    // if (node->depth > 6)
    //     printf("%ld (%ld)[%d %d]\n", node->depth, node->position, node->window.offset.x, node->window.offset.y);
    vec2i_add(&node->window.center, node->window.offset);
}

void quadtree_init(t_conf* conf)
{
    size_t  size;

    size = 1;
    while(conf->height < conf->depth)
    {
        conf->height += 1;
        conf->local_index = 0;
        conf->window.center = vec2i_scale(conf->window.size, 0.5);
        compute_neighbors_mask(conf);
        while(conf->local_index < size)
        {
            quadtree_set_pos(conf);
            quadtree_set_root(conf);
            compute_neighbors(conf);
            quadtree_set_child(conf);
            quadtree_set_window(conf);
            conf->local_index += 1;
            conf->index += 1;
            conf->global_index += 1;
        }
        conf->window.size = conf->window.center;
        size *= 4;
    }
}

void quadtree_set_all_neighbors_existance(t_quadtree* node, bool exist)
{
    size_t  index;

    index = 0;
    while(index < MAX_DIRECTION)
    {
        node->neighbors->exist = exist;
        index += 1;
    }
}

void quadtree_split(t_quadtree* quadtree)
{
    size_t      child_index;
    size_t      direction_index;
    t_direction direction;
    t_neighbors neighbor;
    t_quadtree* child;
    static t_direction directions[4][3] = {
        {EAST, NORTH_EAST, NORTH},
        {NORTH, NORTH_WEST, WEST},
        {WEST, SOUTH_WEST, SOUTH},
        {SOUTH, SOUTH_EAST, EAST},
    };

    child_index = 4;
    while (child_index--)
    {
        child = quadtree->childs[child_index];
        quadtree_set_all_neighbors_existance(child, true);
        direction_index = 3;
        while(direction_index--)
        {
            direction = directions[child_index][direction_index];
            neighbor = quadtree->neighbors[direction];
            if (neighbor.exist)
                child->neighbors[direction].level = neighbor.level - 1;
            child->neighbors[direction].exist = neighbor.exist;
        }
    }
}

bool quadtree_check_neighbors(t_quadtree* quadtree, t_fp_traverse traverse, void* data)
{
    size_t      index;
    size_t      any_exist;
    t_quadtree* neighbor;

    any_exist = 0;
    index = MAX_DIRECTION;
    while (index--)
    {
        if (quadtree->neighbors[index].exist == false)
            continue;
        any_exist += 1;
        if (quadtree->neighbors[index].level != 0)
        {
            // printf("(%ld)[%d]\n", quadtree->neighbors[index].position, quadtree->neighbors[index].level);
            // printf("[%d]", quadtree->neighbors[index].level);
            // printf("[%ld %ld %d]", quadtree->height, quadtree->neighbors[index].position, quadtree->neighbors[index].level);
            // printf("[%s %ld]", direction_name(index), index);
        }
        neighbor = quadtree + (quadtree->neighbors[index].position - quadtree->position);
        if(traverse(neighbor, data) == false)
            return (false);
    }
    return (any_exist);
}