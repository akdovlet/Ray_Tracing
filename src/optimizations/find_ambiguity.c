#include "graphics.h"
#include "objects.h"
#include <stdlib.h>


// this one is okay
static bool is_siblings_different(t_quadtree* quadtree)
{
    t_vec2i i;

    i.x = 0;
    while (i.x < 2)
    {
        i.y = 0;
        while(i.y < 2)
        {
			if(quadtree->root->childs[i.x][i.y] != quadtree)
			{
				if(quadtree->root->childs[i.x][i.y]->shape_id != quadtree->shape_id)
					return(true);
			}
			i.y += 1;
        }
		i.x += 1;
    }
	return (false);
}

// those three one seems also okay
static t_quadtree* find_vertical_uncle(t_quadtree* quadtree)
{
	t_vec2i		opposit;
	t_quadtree* parent;
	t_quadtree* uncle;

	if(quadtree == NULL)
		return (NULL);
	parent = quadtree->root;
	if (parent == NULL)
		return (NULL);
	opposit = quadtree->pos;
	opposit.x = !opposit.x;

	if (parent->pos.x == quadtree->pos.x)
	{
		uncle = find_vertical_uncle(parent);
		return (uncle->childs[opposit.x][opposit.y]);
	}
	if (parent->root)
		return (parent->root->childs[opposit.x][opposit.y]);
	return (NULL);
}

static t_quadtree* find_horizontal_uncle(t_quadtree* quadtree)
{
	t_vec2i		opposit;
	t_quadtree* parent;
	t_quadtree* uncle;

	if(quadtree == NULL)
		return (NULL);
	parent = quadtree->root;
	if (parent == NULL)
		return (NULL);
	opposit = quadtree->pos;
	opposit.y = !quadtree->pos.y;

	if (parent->pos.y == quadtree->pos.y)
	{
		uncle = find_horizontal_uncle(parent);
		return (uncle->childs[opposit.x][opposit.y]);
	}
	if (parent->root)
		return (parent->root->childs[opposit.x][opposit.y]);
	return (NULL);
}

static t_quadtree* find_diagonal_cousin(t_quadtree* quadtree)
{
	t_vec2i		opposit;
	t_quadtree* parent;
	t_quadtree* uncle;

	if(quadtree == NULL)
		return (NULL);
	parent = quadtree->root;
	if (parent == NULL)
		return (NULL);
	opposit.x = !quadtree->pos.x;
	opposit.y = !quadtree->pos.y;

	if (vec2i_equal(parent->pos, quadtree->pos))
	{
		uncle = find_horizontal_uncle(parent);
		return (uncle->childs[opposit.x][opposit.y]);
	}
	if (parent->root)
		return (parent->root->childs[opposit.x][opposit.y]);
	return (NULL);
}

bool is_cousin_different(t_quadtree* quadtree)
{
	t_quadtree* parent;
	t_quadtree* uncle;

	parent = quadtree->root;
	while(parent && (vec2i_equal(parent->pos, quadtree->pos)))
		parent = parent->root;
	if (parent == NULL)
		return (false);
	
	// horizontal opposite
	uncle = find_vertical_uncle(quadtree->root);
	if (uncle && (0
		|| uncle->childs[!quadtree->pos.x][0]->shape_id != quadtree->shape_id
		|| uncle->childs[!quadtree->pos.x][1]->shape_id != quadtree->shape_id))
		return (true);

	// vertical opposite
	uncle = find_horizontal_uncle(quadtree->root);
	if (uncle && (0
		|| uncle->childs[0][!quadtree->pos.y]->shape_id != quadtree->shape_id
		|| uncle->childs[1][!quadtree->pos.y]->shape_id != quadtree->shape_id))
		return (true);

	uncle = find_diagonal_cousin(quadtree->root);
	if (uncle && (0
		|| uncle->childs[!quadtree->pos.x][!quadtree->pos.y]->shape_id != quadtree->shape_id
		|| uncle->childs[!quadtree->pos.x][!quadtree->pos.y]->shape_id != quadtree->shape_id))
		return (true);
	return (false);
}

bool is_ambiguity(t_quadtree* quadtree)
{
	if (!quadtree)
		return(false);
	if (quadtree->depth == 0)
		return(false);
	if (quadtree->root == NULL)
		return (true);
	if (quadtree->is_not_ambiguous == true)
		return (false);
	if (is_siblings_different(quadtree))
		return (true);
	if (is_cousin_different(quadtree))
		return (true);
	quadtree->is_not_ambiguous = true;
	return(false);
}