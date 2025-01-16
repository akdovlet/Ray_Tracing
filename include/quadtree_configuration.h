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
    t_quadtree* prev;
    t_quadtree* current;

    // to assign the child node pointer to the memory
    size_t z_buffer_size;
    size_t z_buffer_offset;
} t_conf;

typedef void(*t_fp_quadtree_builder)(t_conf*);

// compute window split
void pre_compute_window_split(t_conf* conf);
void quadtree_compute_window_child(t_conf* conf);

// assign child node
void pre_compute_zbuffer_size(t_conf* conf);
void quadtree_assign_child(t_conf* conf);

//link nodes
void quadtree_link_node(t_conf* conf);

// utils
t_quadtree* get_current_child(t_conf* conf);

#endif // QUADTREE_CONFIGURATION_H
