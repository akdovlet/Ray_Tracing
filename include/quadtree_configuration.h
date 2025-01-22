#ifndef QUADTREE_CONFIGURATION_H
#define QUADTREE_CONFIGURATION_H

# include "quadtree.h"
# include "data_struct.h"

typedef enum e_v {
    X, Y,
    MAX_V,
} t_v;

typedef struct s_conf {
    size_t      local_index;
    size_t      global_index;

    size_t      index;
    t_window    window;
    size_t      depth;
    size_t      height;
    size_t      node_count;
    t_quadtree* buffer;

    size_t      neighbor_mask[MAX_V];
} t_conf;

void quadtree_init(t_conf* conf);



#endif // QUADTREE_CONFIGURATION_H
