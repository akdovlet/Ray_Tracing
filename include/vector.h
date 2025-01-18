#ifndef VECTOR_H
#define VECTOR_H

# include <stdint.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

typedef struct s_vec2f
{
	float	dis;
	float	x;
	float	y;
}	t_vec2f;

bool vec2i_equal(t_vec2i a, t_vec2i b);
t_vec2i vec2i_add(t_vec2i a, t_vec2i b);
t_vec2i vec2i_scale(t_vec2i a, float scale);

t_vec2i vec2i_multiply(t_vec2i a, t_vec2i b);


t_vec2i vec2f_floor(t_vec2f a);
t_vec2f vec2f_add(t_vec2f a, t_vec2f b);
t_vec2f vec2f_substract(t_vec2f a, t_vec2f b);


t_vec2f vec2f_value(float v);
t_vec2f vec2f_multiply(t_vec2f a, t_vec2f b);


typedef struct s_vec3 
{
	int x;	
	int y;	
	int z;	
} t_vec3;

#endif // VECTOR_H
