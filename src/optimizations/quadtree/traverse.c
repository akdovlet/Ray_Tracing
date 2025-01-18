#include "quadtree.h"
#include <stdio.h>

bool quadtree_traverse(t_quadtree* quadtree, t_fp_traverse traverse, void* data)
{
	int i =0;
	t_quadtree* current;

	current = quadtree;
	while(current && current->depth)
	{
		i += 1;
		if (traverse(current, data) == false)
			return (false);
		current += 1;
	}
	printf("stoped %d\n", i);
	return (true);
}