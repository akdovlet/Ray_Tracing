#ifndef QUADTREE_H
#define QUADTREE_H

#include <stddef.h>
#include <stdbool.h>
#include <math.h>

# include "libft.h"
# include "data_struct.h"

typedef struct s_quadtree t_quadtree;

typedef struct s_window {
    t_vec2i size;
    t_vec2i offset;
    t_vec2i center;
} t_window;

struct s_quadtree {
    t_vec2i     pos;
    t_window    window;
    t_quadtree* root;
    size_t      depth;
    t_quadtree* childs[2][2];

    bool        is_not_ambiguous;
	uintptr_t	shape_id;
};

t_quadtree* quadtree_new(t_vec2i window_size);

typedef struct s_env t_env;
void quadtree_find_object(t_env* env);

// traversal
typedef bool (t_fp_traverse)(t_quadtree*, void*);
bool quadtree_traverse(t_quadtree* quadtree, t_fp_traverse traverse, void* data);

bool is_comps(t_comps* comps, t_env* env, t_quadtree* quadtree);

bool is_quadtree_have_parent(t_quadtree* quadtree);

#endif //QUADTREE_H
