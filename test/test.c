#include "minirt.h"
#include "objects.h"
#include "matrix.h"
#include "light.h"
#include "tuple.h"
#include "mlx_utils.h"
#include "test.h"

void test_init_tuple()
{
	t_tuple	p;
	t_tuple	v;

	p = point_new(4, -4, 3);
	v = vector_new(4, -4, 3);
	fprintf(stderr, "tuple_new tests:\n");
	fprintf(stderr, "p(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n", p.x, p.y, p.z, p.w);
	fprintf(stderr, "v(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n\n", v.x, v.y, v.z, v.w);

	fprintf(stderr, "float_equal test\n");
	fprintf(stderr, "float a: %.2f, float b: %.2f are equal if 0: %d\n\n", 4.2F, 4.1F, float_equal(4.2f, 4.1f));

	fprintf(stderr, "tuple_cmp tests:\n");
	fprintf(stderr, "tuple p and v are equal if 0: %d\n\n", tuple_cmp(p, v));
}

void test_matrix_operation()
{
	/*


	float	**inverse;

	fprintf(stderr, "Matrix inverse test\n");
	mfour = matrix_four_by_four(tuple_new(8, -5, 9, 2),
								tuple_new(7, 5, 6, 1),
								tuple_new(-6, 0, 9, 6),
								tuple_new(-3, 0, -9, -4));
	fprintf(stderr, "mfour:\n");
	matrix_print(mfour, 4, 4);
	inverse = matrix_inverse(mfour, 4);
	fprintf(stderr, "\nInverse:\n");
	matrix_print(inverse, 4, 4);
	matrix_free(mfour, 4);
	matrix_free(inverse, 4);

	mfour = matrix_four_by_four(tuple_new(-5, 2, 6, -8),
								tuple_new(1, -5, 1, 8),
								tuple_new(7, 7, -6, -7),
								tuple_new(1, -3, 7, 4));
	fprintf(stderr, "mfour:\n");								
	matrix_print(mfour, 4, 4);
	inverse = matrix_inverse(mfour, 4);
	fprintf(stderr, "\nInverse:\n");
	matrix_print(inverse, 4, 4);
	matrix_free(mfour, 4);
	matrix_free(inverse, 4);

	mfour = matrix_four_by_four(tuple_new(9, 3, 0, 9),
								tuple_new(-5, -2, -6, -3),
								tuple_new(-4, 9, 6, 4),
								tuple_new(-7, 6, 6, 2));
	fprintf(stderr, "mfour:\n");								
	matrix_print(mfour, 4, 4);
	inverse = matrix_inverse(mfour, 4);
	fprintf(stderr, "\nInverse:\n");
	matrix_print(inverse, 4, 4);
	matrix_free(mfour, 4);
	matrix_free(inverse, 4);

	float	**A;
	float	**B;
	float	**C;
	float	**D;
	fprintf(stderr, "matrix C = A * B\nFind A with C * inverse(B)\n");
	A = matrix_four_by_four(tuple_new(3, -9, 7, 3),
								tuple_new(-5, -8, 2, -9),
								tuple_new(-4, 4, 4, 1),
								tuple_new(-6, 5, -1, 1));
	fprintf(stderr, "Matrix A:\n");								
	matrix_print(A, 4, 4);
	B = matrix_four_by_four(tuple_new(8, 2, 2, 2),
								tuple_new(3, -1, 7, 0),
								tuple_new(7, 0, 5, 4),
								tuple_new(6, -2, 0, 5));
	fprintf(stderr, "\nMatrix B:\n");								
	matrix_print(B, 4, 4);
	C = matrix_multiply(A, B);
	fprintf(stderr, "\nMatrix C = A * B:\n");								
	matrix_print(C, 4, 4);
	inverse = matrix_inverse(B, 4);
	fprintf(stderr, "\nInverse B:\n");
	matrix_print(inverse, 4, 4);
	D = matrix_multiply(C, inverse);
	fprintf(stderr, "\nD = C * B = A:\n");
	matrix_print(D, 4, 4);
	matrix_free(A, 4);
	matrix_free(B, 4);
	matrix_free(C, 4);
	matrix_free(D, 4);
	matrix_free(inverse, 4);

	t_tuple t2;

	fprintf(stderr, "\nMatrix translation tests\n");
	A = matrix_translation(tuple_new(5, -3, 2, 1));
	inverse = matrix_inverse(A, 4);
	t1 = point_new(-3, 4, 5);
	t2 = matrix_multiply_tuple(inverse, t1);
	v1 = vector_new(-3, 4, 5);
	v2 = matrix_multiply_tuple(A, v1);
	tuple_print(t2);
	fprintf(stderr, "Vector translation has no effect:\n");
	tuple_print(v1);
	matrix_free(A, 4);
	matrix_free(inverse, 4);

	fprintf(stderr, "\nScaling tests\n");

	fprintf(stderr, "point: -4, 6, 8 scaling to 2, 3, 4\n");
	A = matrix_scaling(2, 3, 4);
	p1 = point_new(-4, 6, 8);
	p2 = matrix_multiply_tuple(A, p1);
	tuple_print(p2);

	fprintf(stderr, "scaling vector test\n");
	fprintf(stderr, "vector -4, 6, 8 scaled with 2, 3, 4\n");
	v1 = vector_new(-4, 6, 8);
	v2 = matrix_multiply_tuple(A, v1);
	tuple_print(v2);	

	fprintf(stderr, "multiply vector by inverse test\n");
	inverse = matrix_inverse(A, 4);
	v2 = matrix_multiply_tuple(inverse, v1);
	tuple_print(v2);
	matrix_free(inverse, 4);
	matrix_free(A, 4);

	fprintf(stderr, "Reflection test\nReflection is scaling by a negative value\n");
	fprintf(stderr, "Given scaling -1, 1, 1 and point 2, 3, 4\n");
	p1 = point_new(2, 3, 4);
	A = matrix_scaling(-1, 1, 1);
	p2 = matrix_multiply_tuple(A, p1);
	tuple_print(p2);
	matrix_free(A, 4);

	fprintf(stderr, "\nrotate_x test\n");
	p1 = point_new(0, 1, 0);
	t_tuple half_quarter = rotate_x(M_PI / 4, p1);
	fprintf(stderr, "half quarter rotation:\n");
	tuple_print(half_quarter);
	fprintf(stderr, "full quarter rotation:\n");
	t_tuple full_quarter = rotate_x(M_PI / 2, p1);
	tuple_print(full_quarter);

	fprintf(stderr, "\nrotate_y test\n");
	p1 = point_new(0, 0, 1);
	half_quarter = rotate_y(M_PI / 4, p1);
	fprintf(stderr, "half quarter rotation:\n");
	tuple_print(half_quarter);
	fprintf(stderr, "full quarter rotation:\n");
	full_quarter = rotate_y(M_PI / 2, p1);
	tuple_print(full_quarter);

	fprintf(stderr, "\nrotate_z test\n");
	p1 = point_new(0, 1, 0);
	half_quarter = rotate_z(M_PI / 4, p1);
	fprintf(stderr, "half quarter rotation:\n");
	tuple_print(half_quarter);
	fprintf(stderr, "full quarter rotation:\n");
	full_quarter = rotate_z(M_PI / 2, p1);
	tuple_print(full_quarter);


	// fprintf(stderr, "\nShearing test\n");
	// p1 = point_new(2, 3, 4);
	// p2 = shearing(shear_new(0, 0, 0), shear_new(0, 0, 1), p1);
	// tuple_print(p2);

	// fprintf(stderr, "\nTransformatin sequence\n");
	// p1 = point_new(1, 0, 1);
	// float **rx = matrix_rotate_x(M_PI / 2);
	// float **scale = matrix_scaling(5, 5, 5);
	// float **translation = matrix_translation(tuple_new(10, 5, 7, 0));
	// p2 = matrix_multiply_tuple(rx, p1);
	// tuple_print(p2);
	// p2 = matrix_multiply_tuple(scale, p2);
	// tuple_print(p2);
	// t_tuple p3 = matrix_multiply_tuple(translation, p2);
	// tuple_print(p3);
	// T = matrix_multiply(translation, scale);
	// F = matrix_multiply(T, A);
	// p3 = matrix_multiply_tuple(F, p1);
	// tuple_print(p3);
	*/
}

void	put_pixel(t_img *img, unsigned int color, t_tuple t1)
{
	t_tuple center;
	
	center = (t_tuple){WIDTH / 2, HEIGHT / 2, 0, 1};
	t1 = tuple_add(center, t1);
	put_pixel_to_image(img, t1.x, t1.y, color);
}

void	test_clock(t_img *img)
{
	fprintf(stderr, "\nClock test\n");
	t_tuple	center = {};
	put_pixel(img, 0xFF0000, center);
		
	t_tuple	translation = point_new(1, -HEIGHT * 0.375, 1);
	t_tuple twelve = tuple_add(center, translation);
	fprintf(stderr, "twelve\n");
	tuple_print(twelve);
	fprintf(stderr, "translation\n");
	tuple_print(translation);

	// t_matrix l = {{
	// 	{ -2, -8 , 3 , 5 },
	// 	{ -3, 1 , 7 , 3 },
	// 	{ 1 , 2 , -9 , 6 },
	// 	{ -6, 7 , 7 , -9 },
	// }};

	// fprintf(stderr, "determinant is: %f\n", determinant(l));

	t_matrix t = compose(2, (t_matrix[]){
		rotate_z(radians(90)),
		translate(1, -HEIGHT * 0.375, 1),
	});
	fprintf(stderr, "compose matrix:\n");
	print_matrix(t.raw);
	// put_pixel(img, 0x00FF00, transform(twelve, t));
	// put_pixel(img, 0xFFFFFF, transform(twelve, rotate_z(radians(0))));
}

void	inverse_test()
{
	printf("\nInverse test\n");
	t_matrix matrix = {{
		{ -5, 2 , 6 , -8 },
		{ 1, -5 , 1 , 8},
		{ 7 , 7 , -6 , -7 },
		{ 1, -3 , 7 , 4 },
	}};
	t_matrix	id;

	id = identity();
	inverse(matrix, &id);
	print_matrix(id.raw);
}

void main_test()
{
	t_matrix matrice = {{
		{ -2, -8 , 3 , 5 },
		{ -3, 1 , 7 , 3 },
		{ 1 , 2 , -9 , 6 },
		{ -6, 7 , 7 , -9 },
	}};
	t_matrix expected_cofactor = {{
		{690 , 447, 210, 51},
		{-253, -394, -431, -473},
		{552, -138, 345, -207},
		{667, 25 ,203 ,185}
	}};
	test_cofactor(matrice, expected_cofactor);
	test_cofactor2(matrice, expected_cofactor);
}

void	position_test(void)
{
	printf("\nPosition test\n");

	t_ray ray;
	t_tuple	result;
	t_tuple expected;

	ray = ray_new(point_new(2, 3, 4), vector_new(1, 0, 0));
	result = position(ray, 0);
	expected = point_new(2, 3, 4);
	if (tuple_cmp(result, expected))
	{
		fprintf(stderr, "Error: result: ");
		tuple_print(result);
		fprintf(stderr, "expected: ");
		tuple_print(expected);
	}
	else
	{
		printf("OK\n");
	}
	result = position(ray, 1);
	expected = point_new(3, 3, 4);
	if (tuple_cmp(result, expected))
	{
		fprintf(stderr, "Error: result: ");
		tuple_print(result);
		fprintf(stderr, "expected: ");
		tuple_print(expected);
	}
	else
	{
		printf("OK\n");
	}
	result = position(ray, -1);
	expected = point_new(1, 3, 4);
	if (tuple_cmp(result, expected))
	{
		fprintf(stderr, "Error: result: ");
		tuple_print(result);
		fprintf(stderr, "expected: ");
		tuple_print(expected);
	}
	else
	{
		printf("OK\n");
	}
	result = position(ray, 2.5);
	expected = point_new(4.5, 3, 4);
	if (tuple_cmp(result, expected))
	{
		fprintf(stderr, "Error: result: ");
		tuple_print(result);
		fprintf(stderr, "expected: ");
		tuple_print(expected);
	}
	else
	{
		printf("OK\n");
	}
}

void	sphere_test(void)
{
	// t_shape		sph;
	// t_ray			ray;
	// t_intersection	inter;

	// ray = ray_new(point_new(0, 0, 5), vector_new(0, 0, 1));
	// sph = sphere(point_new(0, 0, 0), 1);
	// if (intersect(ray, sph, &inter.vec))
	// 	fprintf(stderr, "No intersection possible\n");
	// else
	// {
	// 	printf("interest at %f and %f\n", inter.vec.x, inter.vec.y);
	// }
	
}

void	object_test(void)
{
	// t_ray			ray;
	// t_shape		sph;
	// t_vec2			vec;
	// t_intersection	i;
	// t_intersection	j;
	// float			dis;

	// ray = ray_new(point_new(0, 0, 5), vector_new(0, 0, 1));
	// sph = sphere(point_new(0, 0, 0), 1);
	// dis = intersect(ray, sph, &vec);
	// if (dis >= 0)
	// 	i = intersection(vec.x, sph, vec, dis);
	// if (dis > 0)
	// 	j = intersection(vec.y, sph, vec, dis);
}

void	transform_test()
{
	t_ray	ray;
	t_ray	new;
	t_tuple	expected;

	printf("Ray transform test\n");
	ray = ray_new(point_new(1, 2, 3), vector_new(0, 1, 0));
	new = ray_transform(ray, translate(3, 4, 5));
	expected = point_new(4, 6, 8);
	printf("\tRay translate:\n");
	if (tuple_cmp(new.origin, expected))
	{
		fprintf(stderr, "\ttransform_test: error: expected:\n");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\n");
		tuple_print(ray.origin);
	}
	else
		printf("\tOK\n");
	printf("\tRay scale:\n");
	new = ray_transform(ray, scale(2, 3, 4));
	expected = point_new(2, 6, 12);
	if (tuple_cmp(new.origin, expected) || tuple_cmp(new.direction, vector_new(0, 3, 0)))
	{
		fprintf(stderr, "\ttransform_test: error: expected:\n");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\n");
		tuple_print(ray.origin);
	}
	else
		printf("\tOK\n");
}

void	object_transform_test(void)
{
	t_ray			ray;
	t_shape		sph;
	float			dis;
	t_vec2			vec;
	t_intersection	i;
	t_intersection	j;

	printf("object transform test\n");
	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	sph = sphere(point_new(0, 0, 0), 1);
	set_transform(&sph, scale(point_new(2, 2, 2)));
	dis = intersect(ray, sph, &vec);
	if (dis < 0)
		fprintf(stderr, "\tno intersection possible\n");
	if (dis >= 0)
		i = intersection(vec.x, sph, vec, dis);
	if (dis > 0)
		j = intersection(vec.y, sph, vec, dis);
	printf("\tintersect at %f and %f\n", vec.x, vec.y);


	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	sph = sphere(point_new(0, 0, 0), 1);
	set_transform(&sph, translate(point_new(5, 0, 0)));
	dis = intersect(ray, sph, &vec);
	if (dis < 0)
		printf("\tdiscriminant is: %f, no intersection possible\n", dis);
	else
	{
		fprintf(stderr, "\tno intersection possible\n");
		if (dis >= 0)
			i = intersection(vec.x, sph, vec, dis);
		if (dis > 0)
			j = intersection(vec.y, sph, vec, dis);
		printf("\tintersect at %f and %f\n", vec.x, vec.y);
	}
}

void	draw_sphere(t_img *img)
{
	t_ray	ray;
	float	wall_z;
	float	wall_size;
	int		y;
	int		x;
	t_tuple	position;
	t_intersection inter;
	t_shape	sph;

	sph = sphere(point_new(0, 0, 1), 1);
	set_transform(&sph, scale(point_new(10, 10, 10)));

	y = 0;
	wall_z = 10;
	wall_size = 7;
	while (y < HEIGHT - 1)
	{
		x = 0;
		while (x < WIDTH - 1)
		{
			position = point_new(x + -HEIGHT / 2, y - WIDTH /2, wall_z);
			ray = ray_new(point_new(x, y, -5), tuple_normalize(tuple_substract(position, ray.origin)));
			if (intersect(ray, sph, &inter.vec) >= 0)
				ak_mlx_pixel_put(img, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void	draw_sphere(t_img *img, t_mlx *mlx)
{
	float			y;
	float			x;
	float			world_x;
	float			world_y;
	float			wall_z;
	float			wall_size;
	float			canvas_pixel;
	float			pixel_size;
	float			half;
	t_tuple			pos;
	t_tuple			point;
	t_ray			r;
	t_shape 		sph;
	t_intersection	inter;
	t_light			light;
	t_tuple			normalv;
	t_tuple			eyev;
	t_tuple			color;
	t_tuple			origin;

	y = 0;
	origin = point_new(0, 0, -5);
	wall_z = 10;
	wall_size = 7;
	canvas_pixel = 500;
	pixel_size = wall_size / canvas_pixel;
	half = wall_size / 2;
	sph = sphere(point_new(0, 0, 0), 1.0f);
	sph.matter = material();
	sph.matter.color = color_new(1, 0.2, 1);
	light = point_light(point_new(-10, -10, -10), color_new(1, 1, 1));
	while (y < canvas_pixel - 1)
	{
		x = 0;
		world_y = half - pixel_size * y;
		while (x < canvas_pixel - 1)
		{
			world_x = -half + pixel_size * x;
			pos = point_new(world_x, world_y, wall_z);
			r = ray_new(origin, tuple_normalize(tuple_substract(pos, origin)));
			inter = hit(intersection(sph, intersect(r, sph)));
			if (inter.count > 0)
			{
				point = position(r, inter.t);
				eyev = tuple_negate(r.direction);
				normalv = normal_at(inter.object, point);
				color = lighting(inter.object.matter, light, eyev, normalv, point);
				ak_mlx_pixel_put(img, x, HEIGHT - y, tuple_tocolor(color));
			}
			x++;
		}
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
		y++;
	}
}

void	normal_at_test(void)
{
	t_shape	sph;
	t_tuple		normal;
	t_tuple		expected;

	printf("\nnormal at test\n");
	sph = sphere(point_new(0, 0, 0), 1);
	set_transform(&sph, translate(0, 1, 0));
	normal = normal_at(sph, point_new(0, 1.70711, -0.70711));
	expected = vector_new(0, 0.70711, -0.70711);
	if (tuple_cmp(normal, expected))
	{
		fprintf(stderr, "\terror:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(normal);
	}

	sph = sphere(point_new(0, 0, 0), 1);
	set_transform(&sph, multiply_matrix(scale(1, 0.5, 1), rotate_z(M_PI / 5)));
	normal = normal_at(sph, point_new(0, sqrt(2) / 2, -sqrt(2) / 2));
	expected = vector_new(0, 0.97014, -0.24254);
	if (tuple_cmp(normal, expected))
	{
		fprintf(stderr, "\terror:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(normal);
	}
}

void	transpose_test(void)
{
	t_matrix	original;
	t_matrix	new;
	t_matrix	expected;
	fprintf(stderr, "\nmatrix transpose test\n");
	original = (t_matrix){{
		{0, 9, 3, 0},
		{9, 8, 0, 8},
		{1, 8, 5, 3},
		{0, 0, 5, 8}
	}};
	new = matrix_transpose(original);
	expected = (t_matrix){{
		{0, 9, 1, 0},
		{9, 8, 8, 0},
		{3, 0, 5, 5},
		{0, 8, 3, 8}
	}};
	if (matrix_cmp(new, expected, 4, 4))
	{
		fprintf(stderr, "\terror:\texpected:\n");
		print_matrix(expected.raw);
		fprintf(stderr, "\tgot:\n");
		print_matrix(new.raw);
	}
	else
		printf("\tOK");
}

void	reflect_test(void)
{
	t_tuple	v;
	t_tuple	n;
	t_tuple	r;
	t_tuple	expected;

	printf("\nreflect test\n");
	v = vector_new(1, -1, 0);
	n = vector_new(0, 1, 0);
	r = reflect(v, n);
	expected = vector_new(1, 1, 0);
	if (tuple_cmp(r, expected))
	{
		fprintf(stderr, "\terror:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(r);
	}
	else
	{
		printf("\tOK\n");
	}

	v = vector_new(0, -1, 0);
	n = vector_new(sqrt(2)/2, sqrt(2)/2, 0);
	r = reflect(v, n);
	expected = vector_new(1, 0, 0);
	if (tuple_cmp(r, expected))
	{
		fprintf(stderr, "\terror:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(r);
	}
	else
		printf("\tOK\n");
}

void	test_pre_compute(void)
{
	t_ray		ray;
	t_crossing	cross;
	t_comps		comps;

	printf("\nPre_compute test\n");

	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	cross.obj = sphere(point_new(0, 0, 0), 1);
	cross.t = 4;
	comps = pre_compute(cross, ray);
	if (tuple_cmp(comps.world_point, point_new(0, 0, -1)))
	{
		fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
		tuple_print(comps.world_point);
	}
	else
	{
		printf("\tOK\n");
	}
	if (tuple_cmp(comps.eyev, vector_new(0, 0, -1)))
	{
		fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
		tuple_print(comps.eyev);
	}
	else
	{
		printf("\tOK\n");
	}
	if (tuple_cmp(comps.normalv, vector_new(0, 0, -1)))
	{
		fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
		tuple_print(comps.normalv);
	}
	else
	{
		printf("\tOK\n");
	}


	ray = ray_new(point_new(0, 0, 0), vector_new(0, 0, 1));
	cross.obj = sphere(point_new(0, 0, 0), 1);
	cross.t = 1;
	comps = pre_compute(cross, ray);
	if (tuple_cmp(comps.world_point, point_new(0, 0, 1)))
	{
		fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
		tuple_print(comps.world_point);
	}
	else
	{
		printf("\tOK\n");
	}
	if (tuple_cmp(comps.eyev, vector_new(0, 0, -1)))
	{
		fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
		tuple_print(comps.eyev);
	}
	else
	{
		printf("\tOK\n");
	}
	if (tuple_cmp(comps.normalv, vector_new(0, 0, -1)))
	{
		fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
		tuple_print(comps.normalv);
	}
	else
	{
		printf("\tOK\n");
	}
	if (!comps.inside)
		printf("\tError: expected comps.inside = true\n");
	else
		printf("\tOK\n");
}

void	test_color_at(void)
{
	t_world	world;
	t_ray	ray;
	t_tuple	color;
	t_tuple	expected;

	printf("\nColor at test\n");
	world = default_world();
	ray = ray_new(point_new(0, 0, -5), vector_new(0, 1, 0));
	color = color_at(world, ray);
	expected = color_new(0, 0, 0);
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}


	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	color = color_at(world, ray);
	expected = color_new(0.38066, 0.47583, 0.2855);
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}

	t_shape tmp;
	world.obj[1].matter.ambient = 1;
	world.obj[0].matter.ambient = 1;
	tmp = world.obj[0];
	world.obj[0] = world.obj[1];
	world.obj[1] = tmp;
	ray = ray_new(point_new(0, 0, 0.75), vector_new(0, 0, -1));
	color = color_at(world, ray);
	expected = world.obj[1].matter.color;
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}
}

void	test_render_world(t_img *img, t_mlx *mlx)
{
	t_world		world;
	t_camera	cam;
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;

	world = default_world();
	cam = camera_new(11, 11, M_PI / 2.0f);
	from = point_new(0, 0, -5);
	to = point_new(0, 0, 0);
	up = vector_new(0, 1, 0);
	cam.transform = view_transform(from, to, up);
	render(cam, world, img, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
}

t_shape	test_shape(void)
{
	return ((t_shape){
		.matter = material(),
		.transform = identity(),
	});
}

void	test_shape_obj(void)
{
	t_shape	s;
	s = test_shape();
	s.transform = translate(2, 3, 4);
	s.matter.ambient = 1;
	print_matrix(s.transform.raw);
}

void	test_intersect_plane(void)
{
	t_shape	plane;
	t_ray	ray;
	t_intersection	hit;

	printf("\n Intersect plane test\n");
	plane = plane_new();

	ray = ray_new(point_new(0, 10, 0), vector_new(0, 0, 1));
	hit = intersection(plane, plane.local_interesct(ray, plane));
	if (plane.local_interesct(ray, plane).dis >= 0)
	{
		fprintf(stderr, "\tError: expected hit count 0\n");
	}
	else
	{
		printf("\tOK\n");
	}

	ray = ray_new(point_new(0, 0, 0), vector_new(0, 0, 1));
	hit = intersection(plane, plane.local_interesct(ray, plane));
	if (plane.local_interesct(ray, plane).dis >= 0)
	{
		fprintf(stderr, "\tError: expected hit count 0\n");
	}
	else
	{
		printf("\tOK\n");
	}

	ray = ray_new(point_new(0, 1, 0), vector_new(0, -1, 0));
	hit = intersection(plane, plane.local_interesct(ray, plane));
	if (hit.count != 1 || hit.t != 1)
	{
		fprintf(stderr, "\tError: expected hit count 1, got: %d, expected t: 1, got: %f\n", hit.count, hit.t);
	}
	else
	{
		printf("\tOK\n");
	}

	ray = ray_new(point_new(0, -1, 0), vector_new(0, 1, 0));
	hit = intersection(plane, plane.local_interesct(ray, plane));
	if (hit.count != 1 || hit.t != 1)
	{
		fprintf(stderr, "\tError: expected hit count 1, got: %d, expected t: 1, got: %f\n", hit.count, hit.t);
	}
	else
	{
		printf("\tOK\n");
	}	
}



