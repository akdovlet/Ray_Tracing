typedef union u_matrix t_matrix;

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct s_vec3 
{
	int x;	
	int y;	
	int z;	
} t_vec3;

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

/*	tuple	*/
t_tuple		tuple_new(float x, float y, float z, float w);
t_tuple		vector_new(float x, float y, float z);
t_tuple		point_new(float x, float y, float z);

int			float_equal(float a, float b);
int			tuple_cmp(t_tuple a, t_tuple b);
t_tuple		tuple_add(t_tuple a, t_tuple b);
t_tuple		tuple_substract(t_tuple a, t_tuple b);
t_tuple		tuple_negate(t_tuple a);
t_tuple		tuple_multiply(t_tuple a, float scalar);
t_tuple		tuple_divide(t_tuple a, float divisor);
float		tuple_magnitude(t_tuple a);
t_tuple		tuple_normalize(t_tuple a);
float		tuple_dot(t_tuple a, t_tuple b);
t_tuple		tuple_cross(t_tuple a, t_tuple b);
void		tuple_print(t_tuple t1);

typedef	union u_vec
{
	t_tuple	t1;
	float	v[4];
}	t_vec;

union u_matrix
{
	struct
	{
		t_tuple r1;
		t_tuple r2;
		t_tuple r3;
		t_tuple r4;	
	};
	float	raw[4][4];
} __attribute__((__transparent_union__));

t_matrix	identity(void);
t_matrix	rotate_x(float angle);
t_matrix	rotate_y(float angle);
t_matrix	rotate_z(float angle);
t_matrix	shear(t_shear s1, t_shear s2);
t_matrix	scale(t_tuple t1);
t_matrix	translate(t_tuple t1);
float		cofactor(t_matrix m, size_t x, size_t y);
int			inverse(t_matrix m, t_matrix *m2);
/*	matrix	*/
t_matrix	multiply_matrix(t_matrix a, t_matrix b);
t_matrix	compose(size_t operation_count, t_matrix* ops);
t_tuple		transform(t_tuple t1, t_matrix m);
