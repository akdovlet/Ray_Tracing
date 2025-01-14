#ifndef QUADTREE_H
#define QUADTREE_H

#include <stddef.h>
#include <stdbool.h>
#include <math.h>

# include "libft.h"

typedef struct s_quadtree t_quadtree;

typedef struct s_zbuffer {
    size_t      size;
    t_quadtree* buffer;
} t_zbuffer;

typedef struct s_window {
    size_t width;
    size_t height;
    size_t offset_x;
    size_t offset_y;
    size_t center_x;
    size_t center_y;
} t_window;

typedef enum e_siblings {
    NEXT,
    PREV,
    MAX_SIBLINGS,
} t_siblings;

typedef enum e_neighbor {
    TOP_LETF, TOP, TOP_RIGHT,
    LEFT, RIGHT,
    BOTTOM_LEFT, BOTTOM, BOTTOM_RIGHT,
    MAX_NEIGHBOR,
} t_neighbor;

struct s_quadtree {
    t_window    window;
    t_quadtree* root;
    size_t      depth;
    t_zbuffer   zbuffer;
    t_quadtree* child[2][2];
    t_quadtree* siblings[MAX_SIBLINGS];
    t_quadtree* neighbor[MAX_NEIGHBOR];

    // t_shape     *shape;
};

void quadtree_set_children(t_quadtree* root);

bool quadtree_new(t_zbuffer* zbuffer, size_t width, size_t height);

typedef struct s_env t_env;
void quadtree_find_object(t_env* env);

#endif //QUADTREE_H
