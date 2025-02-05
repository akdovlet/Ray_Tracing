#include "quadtree_configuration.h"

void    reset_travers_neighbor(t_conf *conf)
{
    conf->current.neighbor.idx = 0;
}

bool    next_neighbor(t_conf *conf)
{
    if (conf->current.neighbor.idx >= MAX_DIRECTION)
        return(false);
    conf->current.neighbor.idx += 1;
    return (true);
}

bool    quadtree_node_travers_neighbors(t_conf *conf, t_callback travers)
{
    size_t  index;
    size_t  any_exist;

    any_exist = 0;
    index = 0;
    while (index < MAX_DIRECTION)
    {
        if(quadtree_node_get_neighbor(conf, index))
        {
            any_exist += 1;
            if(traverse(conf) == false)
                return (false);
        }
        index += 1;
    }
    return (any_exist != 0);
}