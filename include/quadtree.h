#ifndef QUADTREE_H
#define QUADTREE_H

#include <stddef.h>
#include <stdbool.h>
#include <math.h>

# include "libft.h"
# include "data_struct.h"

typedef struct s_quadtree t_quadtree;

typedef struct s_zbuffer {
    size_t      size;
    t_quadtree* buffer;
} t_zbuffer;

typedef struct s_window {
    t_vec2i size;
    t_vec2i offset;
    t_vec2i center;
} t_window;

typedef enum e_siblings {
    NEXT,
    PREV,
    MAX_SIBLINGS,
} t_siblings;

struct s_quadtree {
    t_vec2i     pos;
    t_window    window;
    t_quadtree* root;
    size_t      depth;
    t_zbuffer   zbuffer;
    t_quadtree* childs[2][2];
    t_quadtree* siblings[MAX_SIBLINGS];

    bool            is_not_ambiguous;
	uintptr_t		shape_id;
};

void quadtree_set_children(t_quadtree* root);

bool quadtree_new(t_zbuffer* zbuffer, t_vec2i window_size);

typedef struct s_env t_env;
void quadtree_find_object(t_env* env);

// traversal
typedef bool (t_fp_traverse)(t_quadtree*, void*);
bool quadtree_traverse(t_quadtree* quadtree, t_fp_traverse traverse, void* data);


bool is_comps(t_comps* comps, t_env* env, t_quadtree* quadtree);

#endif //QUADTREE_H
