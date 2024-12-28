#include "minirt.h"

typedef uintptr_t				t_object_id;
typedef enum e_type				t_object_type;
typedef struct s_shape			t_shape;
typedef struct s_vtable_shape	t_vtable_shape;


enum	e_type
{
	SPHERE,
};

struct s_shape {
	t_object_type	type;
	t_object_id		id;
};

struct s_vtable_shape {
	void (*intersection)(t_shape*, t_ray*);
};


// typedef	struct s_object
// {
// 	enum e_type type;
// 	union
// 	{
// 		t_sphere	sphere;
// 	};
// }	t_object;

/// IMPLEMENTATION

typedef struct s_sphere
{
	t_shape	header;
	t_tuple	coordinates;
	float	radius;
}	t_sphere;

t_sphere	sphere(t_tuple point, float radius);
void		sphere_test(void);

void intersection_sphere(t_shape *d, t_ray* r)
{
	t_sphere* s = d;
	return;
}

t_vtable_shape v_table_sphere = {
	.intersection = intersection_sphere,
};


void intersection(t_shape *s, t_ray* r)
{
	v_table_shape[s->type].intersection(s, r);
}
