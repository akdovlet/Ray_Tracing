# include "vector.h"

bool vec2i_equal(t_vec2i a, t_vec2i b)
{
    return (1
        && a.x == b.x
        && a.y == b.y
    );
}

void vec2i_add(t_vec2i *a, t_vec2i b)
{
    a->x += b.x;
    a->y += b.y;
}

t_vec2i vec2i_sum(t_vec2i a, t_vec2i b)
{
    vec2i_add(&a, b);
    return (a);
}

t_vec2i vec2i_substract(t_vec2i a, t_vec2i b)
{
    return ((t_vec2i){
        .x = a.x - b.x,
        .y = a.y - b.y,
    });
}

t_vec2i vec2i_multiply(t_vec2i a, t_vec2i b)
{
    return ((t_vec2i){
        .x = a.x * b.x,
        .y = a.y * b.y,
    });
}

t_vec2i vec2i_scale(t_vec2i a, float scale)
{
    return ((t_vec2i){
        .x = a.x * scale,
        .y = a.y * scale,
    });
}

t_vec2i vec2i_value(int v)
{
    return ((t_vec2i){
        .x = v,
        .y = v,
    });
}

t_vec2i vec2f_floor(t_vec2f a)
{
    return ((t_vec2i){
        .x = floor(a.x),
        .y = floor(a.y),
    });
}


t_vec2f vec2f_value(float v)
{
    return ((t_vec2f){
        .x = v,
        .y = v,
    });
}

t_vec2f vec2f_add(t_vec2f a, t_vec2f b)
{
    return ((t_vec2f){
        .x = a.x + b.x,
        .y = a.y + b.y,
    });
}

t_vec2f vec2f_substract(t_vec2f a, t_vec2f b)
{
    return ((t_vec2f){
        .x = a.x - b.x,
        .y = a.y - b.y,
    });
}

t_vec2f vec2f_multiply(t_vec2f a, t_vec2f b)
{
    return ((t_vec2f){
        .x = a.x * b.x,
        .y = a.y * b.y,
    });
}