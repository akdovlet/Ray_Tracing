#include "_dlst_.h"

t_dlst_node *_dlst_new_node(void)
{
	t_dlst_node	*node;

    node = malloc(sizeof(t_dlst_node));
    if (!node)
        return (NULL);
    *node = (t_dlst_node){0};
    return (node);
}
