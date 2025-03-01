#include "_dlst_.h"
#include "stdio.h"

t_dlst  *_dlst_del(t_dlst *dlst, t_dlst_node *node, void* (*f)(void *))
{
    if (!dlst)
        return (NULL);
    if (!node)
        return (dlst);
    if (dlst->top == node)
        return (_dlst_pop_front(dlst, f));
    if (dlst->bot == node)
        return (_dlst_pop_back(dlst, f));
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if (f)
        node->ptr = f(node->ptr);
    else if (node->ptr)
        free(node->ptr);
    free(node);
    dlst->len--;
    return (dlst);
}
