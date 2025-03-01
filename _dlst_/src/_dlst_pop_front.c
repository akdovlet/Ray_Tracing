#include "_dlst_.h"

t_dlst  *_dlst_pop_front(t_dlst *dlst, void* (*f)(void *))
{
    t_dlst_node *tmp;

    if (!dlst)
        return NULL;
    tmp = dlst->top;
    if (--dlst->len)
    {
        dlst->top = dlst->top->next;
        dlst->top->prev = NULL;
    }
    if (f)
        tmp->ptr = f(tmp->ptr);
    else
        free(tmp->ptr);
    free(tmp);
    if (!dlst->len)
    {
        free(dlst);
        dlst = NULL;
    }
    return (dlst);
}
