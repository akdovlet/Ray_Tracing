#ifndef QUADTREE_H
#define QUADTREE_H

#include <stddef.h>
#include <stdbool.h>
#include <math.h>

# include "libft.h"
# include "data_struct.h"

typedef struct s_quadtree t_quadtree;

typedef enum e_direction {
    EAST,
    NORTH_EAST,
    NORTH,
    NORTH_WEST,
    WEST,
    SOUTH_WEST,
    SOUTH,
    SOUTH_EAST,
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
    size_t  position;
} t_neighbors;

struct s_quadtree {
    size_t      height;
    size_t      depth;
    size_t      position;
    t_quadtree* parent;
    t_quadtree* childs[4];
    t_neighbors neighbors[MAX_DIRECTION];

    t_window    window;
    bool        is_not_ambiguous;
	uintptr_t	shape_id;
};

t_quadtree* quadtree_new(t_vec2i window_size);

typedef struct s_env t_env;
void quadtree_find_object(t_env* env);

// traversal
typedef bool (t_fp_traverse)(t_quadtree*, void*);
bool quadtree_traverse(t_quadtree* quadtree, t_fp_traverse traverse, void* data);

bool is_comps(t_comps* comps, t_env* env, t_vec2i pixel_position);

void quadtree_split(t_quadtree* quadtree);
bool quadtree_check_neighbors(t_quadtree* quadtree, t_fp_traverse traverse, void* data);

#endif //QUADTREE_H
