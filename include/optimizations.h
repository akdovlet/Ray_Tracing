#ifndef OPTIMIZATIONS_H
#define OPTIMIZATIONS_H

#include "graphics.h"
#include "quadtree.h"

#include <stdio.h>

bool resolve_ambiguity(t_quadtree* quadtree, void* data);


void quadtree_find_object(t_env* env);

void quadtree_resolve_border(t_env* env);


#endif // OPTIMIZATIONS_H
