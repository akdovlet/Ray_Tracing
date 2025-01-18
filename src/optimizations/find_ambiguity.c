#include "graphics.h"
#include "objects.h"
#include <stdlib.h>

// utils
bool is_quadtree_null(t_quadtree* quadtree)
{
	return (quadtree == NULL);
}

bool is_quadtree_have_parent(t_quadtree* quadtree)
{
	return (is_quadtree_null(quadtree) && quadtree->root);
}

// this one is okay
bool is_siblings_different(t_quadtree* quadtree)
{
	t_quadtree* sibling;
    t_vec2i i;

    i.x = 0;
    while (i.x < 2)
    {
        i.y = 0;
        while(i.y < 2)
        {
			sibling = quadtree->root->childs[i.x][i.y];
			if(sibling != quadtree && sibling->shape_id != quadtree->shape_id)
				return (true);
			i.y += 1;
        }
		i.x += 1;
    }
	return (false);
}

// those three one seems also okay
t_quadtree* find_vertical_uncle(t_quadtree* quadtree)
{
	t_vec2i		opposit;
	t_quadtree* parent;

	if(is_quadtree_have_parent(quadtree) == false)
		return (NULL);
	parent = quadtree->root;
	opposit = quadtree->pos;
	opposit.x = !opposit.x;

	if (parent->pos.x == quadtree->pos.x)
		return (find_vertical_uncle(parent));
	return (parent->root);
	// if (parent->root)
	// 	return (parent->root->childs[opposit.x][opposit.y]);
	// return (NULL);
}

t_quadtree* find_horizontal_uncle(t_quadtree* quadtree)
{
	t_vec2i		opposit;
	t_quadtree* parent;

	if(is_quadtree_have_parent(quadtree) == false)
		return (NULL);
	parent = quadtree->root;
	opposit = quadtree->pos;
	opposit.y = !quadtree->pos.y;

	if (parent->pos.y == quadtree->pos.y)
		return (find_horizontal_uncle(parent));
	if (parent->root)
		return (parent->root->childs[opposit.x][opposit.y]);
	return (NULL);
}


t_quadtree* find_diagonal_cousin_vertical(t_quadtree* quadtree)
{
	t_vec2i		opposit;
	t_quadtree	*uncle;

	if(is_quadtree_have_parent(quadtree) == false)
		return (NULL);
	opposit.x = !quadtree->pos.x;
	opposit.y = !quadtree->pos.y;

	uncle = NULL;

	if (quadtree->root->pos.y == quadtree->pos.y)
		uncle = find_diagonal_cousin_vertical(quadtree->root);

	else if(is_quadtree_have_parent(quadtree->root) == false)
		return (NULL);
	else
		uncle = quadtree->root->root->childs[quadtree->root->pos.x][!quadtree->root->pos.y];
	return (uncle->childs[opposit.x][opposit.y]);
}

t_quadtree* find_diagonal_cousin_horizontal(t_quadtree* quadtree)
{
	t_vec2i		opposit;
	t_quadtree	*uncle;

	if(is_quadtree_have_parent(quadtree) == false)
		return (NULL);
	opposit.x = !quadtree->pos.x;
	opposit.y = !quadtree->pos.y;

	uncle = NULL;

	if (quadtree->root->pos.x == quadtree->pos.x)
		uncle = find_diagonal_cousin_horizontal(quadtree->root);

	else if(is_quadtree_have_parent(quadtree->root) == false)
		return (NULL);
	else
		uncle = quadtree->root->root->childs[!quadtree->root->pos.x][quadtree->root->pos.y];
	return (uncle->childs[opposit.x][opposit.y]);
}

t_quadtree* find_diagonal_cousin_diagonal(t_quadtree* quadtree)
{
	t_vec2i		opposit;
	t_quadtree	*uncle;

	if(is_quadtree_have_parent(quadtree) == false)
		return (NULL);
	opposit.x = !quadtree->pos.x;
	opposit.y = !quadtree->pos.y;

	uncle = NULL;

	if (vec2i_equal(quadtree->pos, quadtree->root->pos))
		uncle = find_diagonal_cousin_diagonal(quadtree->root);

	else if(is_quadtree_have_parent(quadtree->root) == false)
		return (NULL);
	else
		uncle = quadtree->root->root->childs[!quadtree->root->pos.x][!quadtree->root->pos.y];
	return (uncle->childs[opposit.x][opposit.y]);
}

t_quadtree* find_diagonal_cousin(t_quadtree* quadtree)
{
	if(is_quadtree_have_parent(quadtree) == false)
		return (NULL);

	if (vec2i_equal(quadtree->root->pos, quadtree->pos))
		return (find_diagonal_cousin_diagonal(quadtree));

	if (quadtree->root->pos.y == quadtree->pos.y)
		return (find_diagonal_cousin_vertical(quadtree));

	if (quadtree->root->pos.x == quadtree->pos.x)
		return (find_diagonal_cousin_horizontal(quadtree));

	return (NULL);
}

bool is_cousin_different(t_quadtree* quadtree)
{
	t_quadtree* parent;

	parent = quadtree->root;
	while(parent && (vec2i_equal(parent->pos, quadtree->pos)))
		parent = parent->root;
	if (parent == NULL)
		return (false);
	
	
	// t_quadtree* uncle;

	// // horizontal opposite
	// uncle = find_vertical_uncle(quadtree->root);
	// if (!uncle)
	// 	return (true);
	// if (uncle && (0
	// 	|| uncle->childs[!quadtree->pos.x][0]->shape_id != quadtree->shape_id
	// 	|| uncle->childs[!quadtree->pos.x][1]->shape_id != quadtree->shape_id))
	// 	return (true);

	// // vertical opposite
	// uncle = find_horizontal_uncle(quadtree->root);
	// if (!uncle)
	// 	return (true);
	// 	// printf("lol\n");

	// if (uncle && (0
	// 	|| uncle->childs[0][!quadtree->pos.y]->shape_id != quadtree->shape_id
	// 	|| uncle->childs[1][!quadtree->pos.y]->shape_id != quadtree->shape_id))
	// 	return (true);
	
	/*
	// diagonal opposite
	t_quadtree* cousin;

	cousin = find_diagonal_cousin(quadtree);
	if (cousin == NULL)
	{
		// quadtree->is_not_ambiguous = false;
		return (true);
	}
	if (cousin && cousin->shape_id != quadtree->shape_id)
	{
		// cousin->is_not_ambiguous = false;
		// quadtree->is_not_ambiguous = false;
		return (true);
	}
	*/

	return (false);
}

bool is_ambiguity(t_quadtree* quadtree)
{
	if (!quadtree)
		return(false);
	if (quadtree->depth == 0)
		return(false);
	if (quadtree->is_not_ambiguous == true)
		return (false);
	if (quadtree->root == NULL)
		return (true);
	
	// if (quadtree->root->is_not_ambiguous)
	// {
	// 	quadtree->is_not_ambiguous = true;
	// 	quadtree->shape_id = quadtree->root->shape_id;
	// }

	if(is_siblings_different(quadtree))
		return (true);
	// else
	// 	quadtree->is_not_ambiguous = true;

	

	// if (is_cousin_different(quadtree))
	// {
	// 	quadtree->is_not_ambiguous = false;
	// 	return (true);
	// }
	// quadtree->is_not_ambiguous = true;
	return(true);
}