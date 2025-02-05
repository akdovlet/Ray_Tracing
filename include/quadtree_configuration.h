#ifndef QUADTREE_CONFIGURATION_H
#define QUADTREE_CONFIGURATION_H

# include "quadtree.h"
# include "data_struct.h"

typedef enum e_v {
    X, Y,
    MAX_V,
} t_v;

typedef struct s_vec2s {
    size_t value[MAX_V];
} t_vec2s;

typedef bool (*t_callback)(t_conf*);

typedef enum e_moment {
    BEFORE, AFTER,
    MAX_MOMENT
} t_moment;

typedef enum e_entity {
    LAYER, NODE, NEIGHBOR,
    MAX_ENTITY
} t_entity;

typedef struct s_travers {
    t_callback reset;
    t_callback next;
} t_travers;

typedef struct s_conf_callbacks {
    t_callback call[MAX_MOMENT][MAX_ENTITY];
} t_conf_callbacks;

typedef struct s_conf {
    t_vec2s     window_size;
    size_t      max_depth;
    t_vec2s     neighbor_mask;
    
    t_quadtree  quadtree;

    struct {
        struct {
            size_t              idx;
            t_quadtree_layer    *ptr;
        } layer;
        struct {
            size_t          idx;
            t_quadtree_node *ptr;
        } node;
        struct {
            size_t          idx;

            size_t          layer_idx;
            size_t          position;
            t_quadtree_node *ptr;
        } neighbor;
    } current;

    t_travers           travers[MAX_ENTITY];
    t_conf_callbacks    callbacks;

    void*   data;

    t_window    window;
    size_t      depth;
    size_t      height;
    size_t      node_count;
    t_quadtree_node* buffer;
} t_conf;

size_t quad_location_addition_operator(size_t location_code, size_t direction_increment);

void quadtree_prepare_neighbors_mask(t_conf* conf); //??

// Utils
bool    try_callback(t_conf* conf, t_moment m, t_entity e);
void    quadtree_request_node_split(t_conf* conf);

// Travers
void    reset_travers_layer(t_conf *conf);
bool    next_layer(t_conf *conf);

void    reset_travers_node(t_conf *conf);
bool    next_node(t_conf *conf);

void    reset_travers_neighbor(t_conf *conf);
bool    next_neighbor(t_conf *conf);

// Build
bool    build(t_vec2s window_size, t_conf_callbacks callbacks, void* data);

// Neighbor
bool    quadtree_node_travers_neighbors(t_conf *conf, t_callback travers);

#endif // QUADTREE_CONFIGURATION_H
