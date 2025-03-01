#include "_dlst_.h"

t_dlst  *_dlst_pop_back(t_dlst *dlst, void* (*f)(void *))
{
    t_dlst_node *tmp;

    if (!dlst)
        return NULL;
    tmp = dlst->bot;
    if (--dlst->len)
    {
        dlst->bot = dlst->bot->prev;
        dlst->bot->next = NULL;
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
