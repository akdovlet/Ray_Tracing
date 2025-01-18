#ifndef QUADTREE_CONFIGURATION_H
#define QUADTREE_CONFIGURATION_H

# include "quadtree.h"
# include "data_struct.h"
# include <stdio.h> // TODO: remove it

typedef struct s_conf {
    t_vec2i     pos;
    t_quadtree* root;

    // for window position and size
    t_vec2i window_size[3];

    // for linking the nodes
    t_quadtree* current;
    t_quadtree* prev;

    t_window    window;
    size_t      depth;
    size_t      node_count;
    t_quadtree* buffer;
} t_conf;

void quadtree_init(t_conf* conf);
void compute_window_split(t_vec2i size, t_window* windows);

#endif // QUADTREE_CONFIGURATION_H
