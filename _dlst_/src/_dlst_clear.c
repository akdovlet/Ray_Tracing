#include "_dlst_.h"

t_dlst  *_dlst_clear(t_dlst *dlst, void* (*f)(void *))
{
    while (dlst)
        dlst = _dlst_pop_back(dlst, f);
    return (dlst);
}
