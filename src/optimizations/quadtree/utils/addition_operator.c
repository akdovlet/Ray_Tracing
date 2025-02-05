#include "quadtree_configuration.h"

size_t quad_location_addition_operator(size_t location_code, size_t direction_increment)
{
    size_t  index_mask;
    t_vec2s position_mask;
    t_vec2s neighbor_mask;

    neighbor_mask = compute_neighbors_mask(NULL);
    index_mask = 0;
    while(index_mask < MAX_V)
    {
        position_mask.value[index_mask] = location_code;
        position_mask.value[index_mask] |= neighbor_mask.value[!index_mask];
        position_mask.value[index_mask] += (direction_increment & neighbor_mask.value[index_mask]);
        position_mask.value[index_mask] &= neighbor_mask.value[index_mask];
        index_mask += 1;
    }
    return (position_mask.value[X] | position_mask.value[Y]);
}