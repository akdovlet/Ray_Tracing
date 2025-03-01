#include "_dlst_.h"

t_dlst  *_dlst_foreach(t_dlst *dlst, void (*f)(void *))
{
    t_dlst_node *tmp;

    if (!dlst)
        return (NULL);
    if (!f)
        return (dlst);
    tmp = dlst->top;
    while (tmp)
    {
        f(tmp->ptr);
        tmp = tmp->next;
    }
    return (dlst);
}
