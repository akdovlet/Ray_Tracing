#include "quadtree_configuration.h"

void    reset_travers_layer(t_conf *conf)
{
    conf->current.layer.idx = 0;
    conf->current.layer.ptr = NULL;
}

bool    next_layer(t_conf *conf)
{
    if(conf->current.layer.idx >= conf->quadtree->size)
        return(reset_travers_layer(conf), false);
    if(conf->current.layer.ptr != NULL)
        conf->current.layer.idx += 1;
    conf->current.layer.ptr = &conf->quadtree.buffer[conf->current.layer.idx];
    return(true);
}
