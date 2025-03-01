#include "_dlst_.h"

t_dlst  *_dlst_push_front(t_dlst *dlst, void *ptr)
{
    t_dlst_node *node;

    node = _dlst_new_node();
    if (!node)
        return (dlst);
    if (!dlst)
    {
        dlst = _dlst_new();
        if (!dlst)
            return (free(node), NULL);
        dlst->top = node;
        dlst->bot = node;
    }
    else 
    {
        node->next = dlst->top;
        dlst->top->prev = node;
        dlst->top = node;
    }
    node->mgr = dlst;
    node->ptr = ptr;
    dlst->len++;
    return (dlst);
}
