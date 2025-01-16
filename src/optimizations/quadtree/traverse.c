#include "quadtree.h"

bool quadtree_traverse(t_quadtree* quadtree, t_fp_traverse traverse, void* data)
{
	t_quadtree* current;
	t_siblings	next_sibling;

	current = quadtree;
	next_sibling = NEXT;
	while(current && current->depth)
	{
		if (traverse(current, data) == false)
			return (false);
		if (!current->siblings[next_sibling] && !current->depth)
			return (true);
		if (current->siblings[next_sibling])
			current = current->siblings[next_sibling];
		else
		{
			if (next_sibling == NEXT)
			{
				current = current->childs[1][1];
				next_sibling = PREV;
			}
			else
			{
				current = current->childs[0][0];
				next_sibling = NEXT;
			}
		}
	}
	return (true);
}