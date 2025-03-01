#include "_dlst_.h"

t_dlst  *_dlst_insert_next(t_dlst *dlst, t_dlst_node *node, void *ptr)
{
    t_dlst_node *new;

    if (!dlst)
        return (_dlst_push_back(dlst, ptr));
    new = _dlst_new_node();
    if (!new)
        return (dlst);
    new->prev = node;
    new->next = node->next;
    if (node->next)
        node->next->prev = new;
    node->next = new;
    new->ptr = ptr;
    new->mgr = dlst;
    dlst->len++;
    return (dlst);
}
