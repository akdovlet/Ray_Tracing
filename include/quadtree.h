#ifndef QUADTREE_H
#define QUADTREE_H

#include <stddef.h>
#include <stdbool.h>
#include <math.h>

# include "libft.h"
# include "data_struct.h"

typedef struct s_quadtree_node t_quadtree_node;

typedef enum e_direction {
    EAST,
        // NORTH_EAST, 
        // NORTH,  
        // NORTH_WEST, 
        SOUTH_EAST,
        SOUTH,
        SOUTH_WEST,
    WEST,
        NORTH_WEST, 
        NORTH,  
        NORTH_EAST, 

        // SOUTH_WEST,
        // SOUTH,
        // SOUTH_EAST,
    MAX_DIRECTION,
} t_direction;

typedef struct s_window {
    t_vec2i size;
    t_vec2i offset;
    t_vec2i center;
} t_window;

typedef struct s_neighbors {
    bool    exist;
    int     level;
} t_neighbors;

struct s_quadtree_node {
    bool        split;
    
    size_t      height;
    size_t      depth;
    size_t      position;
    t_quadtree_node* parent;
    t_quadtree_node* childs[4];
    t_neighbors neighbors[MAX_DIRECTION];

    t_window    window;
    bool        is_not_ambiguous;
	uintptr_t	shape_id;
};

typedef struct s_quadtree_layer {
    t_quadtree_node *buffer;
    size_t          size;
    size_t          capacity;
} t_quadtree_layer;

typedef struct s_quadtree {
    t_quadtree_layer    *buffer;
    size_t              size;
    size_t              capacity;
} t_quadtree;

typedef struct s_env t_env;
void quadtree_find_object(t_env* env);

bool is_comps(t_comps* comps, t_env* env, t_vec2i pixel_position);

void quadtree_split(t_quadtree_node* quadtree);


bool    quadtree_new(t_quadtree* quadtree, size_t capacity);
size_t  quadtree_comptute_depth_from_window_size(t_vec2i window_size);



#endif //QUADTREE_H
