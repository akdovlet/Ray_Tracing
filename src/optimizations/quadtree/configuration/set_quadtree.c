#include "quadtree_configuration.h"

void quadtree_init(t_conf* conf)
{
    size_t          i;;
    size_t          size;
    size_t          global_index;
    size_t          local_index;
    t_quadtree*     node;
    static t_vec2i  positions[4] = {{0,0}, {1,0}, {0,1}, {1,1}};
    t_vec2i         pos;

    size = 1;
    node = conf->buffer;
    global_index = 0;
    i = 0;
    while(i < conf->depth)
    {
        local_index = 0;
        conf->window.center = vec2i_scale(conf->window.size, 0.5);
        while(local_index < size)
        {
            pos = positions[local_index % 4];
            node[local_index].depth = conf->depth - i;
            node[local_index].pos = pos;
            node[local_index].childs[pos.x][pos.y] = &conf->buffer[1 + (global_index * 4)];
            node[local_index].root = &conf->buffer[(global_index - 1) / 4];
            node[local_index].window = conf->window;
            node[local_index].window.offset = vec2i_multiply(vec2i_scale(pos, i), conf->window.size);
            node[local_index].window.center = vec2i_add(node[local_index].window.offset, conf->window.center);
            local_index += 1;
            global_index += 1;
        }
        conf->window.size = conf->window.center;
        node += size;
        size *= 4;
        i += 1;
    }
}