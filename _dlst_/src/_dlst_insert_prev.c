#include "_dlst_.h"

t_dlst  *_dlst_insert_prev(t_dlst *dlst, t_dlst_node *node, void *ptr)
{
    t_dlst_node *new;

    if (!dlst)
        return (_dlst_push_back(dlst, ptr));
    new = _dlst_new_node();
    if (!new)
        return (dlst);
    new->next = node;
    new->prev = node->prev;
    if (node->prev)
        node->prev->next = new;
    node->prev = new;
    new->mgr = dlst;
    new->ptr = ptr;
    dlst->len++;
    return (dlst);
}
