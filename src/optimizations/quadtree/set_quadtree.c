#include "quadtree_configuration.h"

#include <stdio.h>

/*START direction*/
size_t  direction_mask(t_direction direction)
{
    static size_t masks[MAX_DIRECTION] = {
        0b000001, 0b000011, 0b000010, 0b010111,
        0b010101, 0b111111, 0b101010, 0b101011,
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
/*END direction*/

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

void quadtree_set_child(t_conf* conf)
{
    size_t      index;
    size_t      child_index;
    t_quadtree_node* node;

    node = &conf->buffer[conf->index];
    child_index = 1 + (conf->index * 4);
    index = 0;
    while(index < 4)
    {
        node->childs[index] = conf->buffer + (child_index + index);
        index += 1;
    }
}

void quadtree_set_window(t_conf* conf)
{
    t_quadtree_node* node;

    node = &conf->buffer[conf->index];
    node->window = conf->window;
    node->window.offset = vec2i_multiply(node->window.size,
        local_position_to_absolute_vec2i(conf->local_index, node->height)); //the local_index is a hack!!
    // if (node->depth > 6)
    //     printf("%ld (%ld)[%d %d]\n", node->depth, node->position, node->window.offset.x, node->window.offset.y);
    vec2i_add(&node->window.center, node->window.offset);
}


///

void quadtree_set_all_neighbors_existance(t_quadtree_node* node, bool exist)
{
    size_t  index;

    index = 0;
    while(index < MAX_DIRECTION)
    {
        node->neighbors[index].exist = exist;
        index += 1;
    }
}

void quadtree_split(t_quadtree_node* quadtree)
{
    size_t      child_index;
    size_t      direction_index;
    t_neighbors neighbor;
    t_quadtree_node* child;

    child_index = 0;
    while (child_index < 4)
    {
        child = quadtree->childs[child_index];
        quadtree_set_all_neighbors_existance(child, true);
        direction_index = 0;
        while(direction_index < MAX_DIRECTION)
        {
            neighbor = quadtree->neighbors[direction_index];
    
            // neighbors_position = compute_neighbors_position(quadtree, index);

            if (neighbor.exist)
                child->neighbors[direction_index].level = neighbor.level - 1;
            else
                child->neighbors[direction_index].exist = false;

            direction_index += 1;
        }
        // debug_quadtree_neighbors_existance(child);
        child_index += 1;
    }
}
