#include "quadtree_configuration.h"

bool    quadtree_travers(t_conf* conf, t_entity entity, t_callback travers)
{
    if (try_callback(conf, BEFORE, entity) == false)
        return(false);
    conf->travers[entity].reset(conf);
    while(conf->travers[entity].next(conf))
        if(travers(conf) == false)
            return(false);
    if (try_callback(conf, AFTER, entity) == false)
        return(false);
    return(true);
}