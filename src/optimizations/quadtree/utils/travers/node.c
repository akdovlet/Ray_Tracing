#include "quadtree_configuration.h"

void    reset_travers_node(t_conf *conf)
{
    conf->current.node.idx = 0;
    conf->current.node.ptr = NULL;
}

bool    next_node(t_conf *conf)
{
    if(conf->current.node.idx >= conf->current.layer.ptr->size)
        return(false);
    conf->current.node.ptr = &conf->current.layer.ptr->buffer[conf->current.node.idx];
    conf->current.node.idx += 1;
    return(true);
}