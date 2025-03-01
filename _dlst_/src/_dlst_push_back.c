#include "_dlst_.h"

t_dlst  *_dlst_push_back(t_dlst *dlst, void *ptr)
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
        node->prev = dlst->bot;
        dlst->bot->next = node;
        dlst->bot = node;
    }
    node->mgr = dlst;
    node->ptr = ptr;
    dlst->len++;
    return (dlst);
}
