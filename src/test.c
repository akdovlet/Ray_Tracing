#include "minirt.h"


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

void test_matrix_determinant()
{
	/*
	float **mfour = matrix_four_by_four(v1, v2, c1, c2);
	for (int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			fprintf(stderr, " 4x4 matrix[%d][%d]: %.2f", i, j, mfour[i][j]);
		}
		fprintf(stderr, "\n");
	}

	float	**mthree = matrix_three_by_three(v1, v2, c1);
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			fprintf(stderr, " 3x3 matrix[%d][%d]: %.2f", i, j, mthree[i][j]);
		}
		fprintf(stderr, "\n");
	}
	float	**mtwo = matrix_two_by_two(v1, v2);
	for (int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			fprintf(stderr, " 2x2 matrix[%d][%d]: %.2f", i, j, mtwo[i][j]);
		}
		fprintf(stderr, "\n");
	}
	matrix_free(mfour, 4);
	matrix_free(mthree, 3);
	matrix_free(mtwo, 2);

	fprintf(stderr, "\nMatrix multiply_matrix tests\n");
	mfour = matrix_four_by_four(tuple_new(1, 2, 3, 4), tuple_new(5, 6, 7, 8), tuple_new(9, 8, 7 ,6), tuple_new(5, 4, 3, 2));
	float	**mfour2 = matrix_four_by_four(tuple_new(-2, 1, 2, 3), tuple_new(3, 2, 1, -1), tuple_new(4, 3, 6 ,5), tuple_new(1, 2, 7, 8));
	float	**mfour3 = matrix_multiply(mfour, mfour2);
	for (int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			fprintf(stderr, " mulitplication 4x4 matrix[%d][%d]: %.2f", i, j, mfour3[i][j]);
		}
		fprintf(stderr, "\n");
	}
	matrix_free(mfour2, 4);
	matrix_free(mfour3, 4);
	t_tuple result = matrix_multiply_tuple(mfour, tuple_new(1, 2, 3, 1));
	fprintf(stderr, "matrix multiply_matrix by tuple result: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n\n", result.x, result.y, result.z, result.w);
	fprintf(stderr, "c2 is: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n\n", c2.x, c2.y, c2.z, c2.w);
	matrix_free(mfour, 4);
	mfour = matrix_four_by_four(tuple_new(0, 1, 2, 4), tuple_new(1, 2, 4 ,8), tuple_new(2, 4, 8, 16), tuple_new(4, 8, 16, 32)); 
	float	**midentity = matrix_identity();
	float	**mresult = matrix_multiply(mfour, midentity);
	matrix_print(mresult, 4, 4);
	matrix_free(mfour, 4);
	matrix_free(mresult, 4);
	
	fprintf(stderr, "\nmatrix transpose test\n");
	mfour = matrix_four_by_four(tuple_new(0, 9, 3, 0), tuple_new(9, 8, 0, 8), tuple_new(1, 8, 5 , 3), tuple_new(0, 0, 5, 8));
	matrix_transpose(mfour);
	matrix_print(mfour, 4, 4);
	matrix_free(mfour, 4);

	mtwo = matrix_two_by_two(tuple_new(1, 5, 0, 0), tuple_new(-3, 2, 0, 0));
	fprintf(stderr, "\ndeterminant of 2x2 matrix is: %.2f\n", matrix_determinant(mtwo));
	
	matrix_free(mtwo, 2);
	mthree = matrix_three_by_three(tuple_new(1, 5, 0, 0), tuple_new(-3, 2, 7, 0), tuple_new(0, 6, -3, 0));
	
	fprintf(stderr, "\nSubmatrix test\n");
	fprintf(stderr, "mthree:\n");
	matrix_print(mthree, 3, 3);
	
	fprintf(stderr, "submatrix\n");
	float **submatrix = sub_matrix(mthree, 3, 0, 2);
	matrix_print(submatrix, 2, 2);

	matrix_free(mthree, 3);
	matrix_free(submatrix, 2);

	mfour = matrix_four_by_four(tuple_new(-6, 1, 1, 6), tuple_new(-8, 5, 8 , 6), tuple_new(-1, 0, 8, 2), tuple_new(-7, 1, -1, 1));
	submatrix = sub_matrix(mfour, 4, 2, 1);

	fprintf(stderr, "submatrix of 4x4\n");
	matrix_print(submatrix, 3, 3);
	matrix_free(mfour, 4);
	matrix_free(submatrix, 3);

	fprintf(stderr, "matrix cofactor test\n");
	mthree = matrix_three_by_three(tuple_new(3, 5, 0, 0), tuple_new(2, -1, -7, 0), tuple_new(6, -1, 5, 0));
	fprintf(stderr, "cofactor of mtrhee at row/col %d/%d: %f\n", 1, 0, matrix_cofactor(mthree, 1, 0, 3));
	mfour	= matrix_four_by_four(tuple_new(-2, -8, 3, 5), tuple_new(-3, 1, 7, 3), tuple_new(1, 2, -9, 6), tuple_new(-6, 7 , 7, -9));
	fprintf(stderr, "cofactor of mfour at row/col %d/%d: %f\n", 0, 0, matrix_cofactor(mfour, 0, 0, 4));
	fprintf(stderr, "cofactor of mfour at row/col %d/%d: %f\n", 0, 1, matrix_cofactor(mfour, 0, 1, 4));
	fprintf(stderr, "cofactor of mfour at row/col %d/%d: %f\n", 0, 2, matrix_cofactor(mfour, 0, 2, 4));
	fprintf(stderr, "cofactor of mfour at row/col %d/%d: %f\n", 0, 3, matrix_cofactor(mfour, 0, 3, 4));
	matrix_free(mthree, 3);
	matrix_free(mfour, 4);
	
	fprintf(stderr, "matrix 3x3:\n");
	fprintf(stderr, "|	1	|	2	|	6	|\n");
	fprintf(stderr, "|	-5	|	8	|	-4	|\n");
	fprintf(stderr, "|	2	|	6	|	4	|\n\n");
	mthree = matrix_three_by_three(tuple_new(1, 2, 6, 0), tuple_new(-5, 8, -4, 0), tuple_new(2, 6, 4, 0));
	fprintf(stderr, "cofactor of mthree at row/col %d/%d: %f\n", 0, 2, matrix_cofactor(mthree, 0, 2, 3));
	matrix_free(mthree, 3);

	fprintf(stderr, "matrix 4x4:\n");
	fprintf(stderr, "|	-2	|	-8	|	3	|	5	|\n");
	fprintf(stderr, "|	-3	|	1	|	7	|	3	|\n");
	fprintf(stderr, "|	1	|	2	|	-9	|	6	|\n");
	fprintf(stderr, "|	-6	|	7	|	7	|	-9	|\n\n");
	mfour	= matrix_four_by_four(tuple_new(-2, -8, 3, 5), tuple_new(-3, 1, 7, 3), tuple_new(1, 2, -9, 6), tuple_new(-6, 7 , 7, -9));
	fprintf(stderr, "determinant of mfour: %f\n", matrix_determinant_recursion(mfour, 4));
	matrix_free(mfour, 4);

	fprintf(stderr, "matrix 4x4:\n");
	fprintf(stderr, "|	6	|	4	|	4	|	4	|\n");
	fprintf(stderr, "|	5	|	5	|	7	|	6	|\n");
	fprintf(stderr, "|	4	|	-9	|	3	|	-7	|\n");
	fprintf(stderr, "|	9	|	1	|	7	|	-6	|\n\n");
	mfour	= matrix_four_by_four(tuple_new(6, 4, 4, 4), tuple_new(5, 5, 7, 6), tuple_new(4, -9, 3, -7), tuple_new(9, 1 , 7, -6));
	fprintf(stderr, "determinant of mfour: %f\n", matrix_determinant_recursion(mfour, 4));
	matrix_free(mfour, 4);

	fprintf(stderr, "matrix 4x4:\n");
	fprintf(stderr, "|	-4	|	2	|	-2	|	-3	|\n");
	fprintf(stderr, "|	9	|	6	|	2	|	6	|\n");
	fprintf(stderr, "|	0	|	-5	|	1	|	-5	|\n");
	fprintf(stderr, "|	0	|	0	|	0	|	-0	|\n\n");
	mfour	= matrix_four_by_four(tuple_new(-4, 2, -2, -3), tuple_new(9, 6, 2, 6), tuple_new(0, -5, 1, -5), tuple_new(0, 0 , 0, 0));
	fprintf(stderr, "determinant of mfour: %f\n", matrix_determinant_recursion(mfour, 4));
	matrix_free(mfour, 4);
*/
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

void test_color()
{

	/*
	t_tuple	p;
	t_tuple	v;
	t_tuple	new;

	p = point_new(4, -4, 3);
	v = vector_new(4, -4, 3);
	test_init_tuple(p, v);


	new = tuple_add(p, v);
	fprintf(stderr, "tuple_add test\n");
	fprintf(stderr, "tuple p + v = tuple(%.2f, %.2f, %.2f, %.2f)\n\n", \
	new.x, new.y, new.z, new.w);

	t_tuple	p1 = point_new(3, 2, 1);
	t_tuple	p2 = point_new(5, 6, 7);
	new = tuple_substract(p1, p2);
	fprintf(stderr, "tuple_substract test\n");
	fprintf(stderr, "p1(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n", p1.x, p1.y, p1.z, p1.w);
	fprintf(stderr, "p2(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n\n", p2.x, p2.y, p2.z, p2.w);
	fprintf(stderr, "tuple p1 - p2 = tuple(%.2f, %.2f, %.2f, %.2f)\n\n", new.x, new.y, new.z, new.w);

	t_tuple	v1 = vector_new(5, 6, 7);
	new = tuple_substract(p1, v1);
	fprintf(stderr, "substracting a vector from a point\n");
	fprintf(stderr, "v1(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n", v1.x, v1.y, v1.z, v1.w);
	fprintf(stderr, "tuple p1 - v1 = tuple(%.2f, %.2f, %.2f, %.2f)\n", new.x, new.y, new.z, new.w);

	t_tuple	v2 = vector_new(3, 2, 1);
	new = tuple_substract(v2, v1);
	fprintf(stderr, "substracting a vector from a vector\n");
	fprintf(stderr, "v2(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n", v2.x, v2.y, v2.z, v2.w);
	fprintf(stderr, "tuple v1 - v2 = vector(%.2f, %.2f, %.2f, %.2f)\n\n", new.x, new.y, new.z, new.w);

	t_tuple	t1 = tuple_new(1, -2, 3, -4);
	new = tuple_negate(t1);
	fprintf(stderr, "Negating a tuple\n");
	fprintf(stderr, "t1(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n", t1.x, t1.y, t1.z, t1.w);
	fprintf(stderr, "negated tuple t1 = tuple(%.2f, %.2f, %.2f, %.2f)\n\n", new.x, new.y, new.z, new.w);

	new = tuple_multiply(t1, 3.5);
	fprintf(stderr, "tuple scalar test\n");
	fprintf(stderr, "scaled by 3.5 tuple t1 = tuple(%.2f, %.2f, %.2f, %.2f)\n", new.x, new.y, new.z, new.w);
	new = tuple_multiply(t1, 0.5);
	fprintf(stderr, "scaled by 0.5 tuple t1 = tuple(%.2f, %.2f, %.2f, %.2f)\n", new.x, new.y, new.z, new.w);
	new = tuple_divide(t1, 2);
	fprintf(stderr, "divided by 2 tuple t1 = tuple(%.2f, %.2f, %.2f, %.2f)\n\n", new.x, new.y, new.z, new.w);
	
	fprintf(stderr, "magnitude test\n");
	fprintf(stderr, "magnite is: %.2f\n\n", tuple_magnitude(vector_new(0, 1, 0)));
	fprintf(stderr, "magnite is: %.2f\n\n", tuple_magnitude(vector_new(1, 2, 3)));

	v2 = vector_new(1, 2, 3);
	new = tuple_normalize(v2);
	fprintf(stderr, "normalize test\n");
	fprintf(stderr, "normalized vector v2:1.2.3 is: %.2f, %.2f, %.2f, %.2f\n\n", new.x, new.y, new.z, new.w);
	
	fprintf(stderr, "dot factor test\n");
	fprintf(stderr, "v1(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n", v1.x, v1.y, v1.z, v1.w);
	fprintf(stderr, "v2(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n", v2.x, v2.y, v2.z, v2.w);
	fprintf(stderr, "dot factor of v1 and v2 is: %.2f\n\n", tuple_dot(v1, v2));

	v1 = vector_new(1, 2, 3);
	v2 = vector_new(2, 3, 4);
	fprintf(stderr, "v1(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n", v1.x, v1.y, v1.z, v1.w);
	fprintf(stderr, "v2(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n", v2.x, v2.y, v2.z, v2.w);
	new = tuple_cross(v1, v2);
	fprintf(stderr, "cross product test\n");
	fprintf(stderr, "cross product of v1 and v2 = %.2f, %.2f, %.2f, %.2f\n", new.x, new.y, new.z, new.w);
	new = tuple_cross(v2, v1);
	fprintf(stderr, "cross product of v2 and v1 = %.2f, %.2f, %.2f, %.2f\n\n", new.x, new.y, new.z, new.w);


	fprintf(stderr, "color test\n");	
	t_tuple	color;

	color = color_new(0.5, 0.4, 1.7);
	fprintf(stderr, "color is: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n\n", color.x, color.y, color.z, color.w);
	
	t_tuple	c1 = color_new(0.9, 0.6, 0.75);
	t_tuple c2 = color_new(0.7, 0.1, 0.25);
	t_tuple	c_new = tuple_add(c1, c2);
	fprintf(stderr, "c1 is: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n\n", c1.x, c1.y, c1.z, c1.w);
	fprintf(stderr, "c2 is: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n\n", c2.x, c2.y, c2.z, c2.w);
	fprintf(stderr, "c1 + c2 is: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n\n", c_new.x, c_new.y, c_new.z, c_new.w);

	c_new = tuple_substract(c1, c2);
	fprintf(stderr, "c1 - c2 is: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n\n", c_new.x, c_new.y, c_new.z, c_new.w);
	
	t_tuple	c3 = color_new(0.2, 0.3, 0.4);
	fprintf(stderr, "c3 is: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n\n", c2.x, c2.y, c2.z, c2.w);
	c_new = tuple_multiply(c3, 2);
	fprintf(stderr, "c3 * 2 is: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n\n", c_new.x, c_new.y, c_new.z, c_new.w);
	
	c1 = color_new(1, 0.2, 0.4);
	c2 = color_new(0.9, 1, 0.1);
	c_new = color_hadamard(c1, c2);
	fprintf(stderr, "c1 * c2 is: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n\n", c_new.x, c_new.y, c_new.z, c_new.w);
 */
}


void test_cofactor(t_matrix m, t_matrix expected)
{
	int index;
	float cofac;
	int x, y;

	index = -1;
	while (++index < 16)
	{
		x = (index % 4);
		y = (index / 4);
		cofac = cofactor(m, x, y);
		printf("Cofactor for {%d %d} = %f\n", x, y, cofac);
		if (cofac != expected.raw[x][y])
		{
			fprintf(stderr, 
			"ERROR:"
			" The expected cofactor doesn't match with result "
			"at {%d, %d}, result = %f, expected = %f\n",
			x, y, cofac, expected.raw[x][y]);
		}
	}
}

void	test_cofactor2(t_matrix m, t_matrix expected)
{
	int	i;
	int	j;
	float	cofac;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			cofac = cofactor(m, j, i);
			if (cofac != expected.raw[i][j])
				fprintf(stderr, "error: wrong cofactor: %f; expected: %f\n"
					, cofac, expected.raw[i][j]);
		}
	}
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
		translate(translation),
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

void	determinant_test()
{
	float	deter;
	float	cof;

	printf("\ndeterminant test\n");
	t_matrix matrix = {{
		{ -2, -8 , 3 , 5 },
		{ -3, 1 , 7 , 3},
		{ 1 , 2 , -9 , 6 },
		{ -6, 7 , 7 , -9 },
	}};
	cof = cofactor(matrix, 1, 0);
	printf("cofactor of 0,1 is: %f\n", cof);
	deter = determinant(matrix);
	if (deter != -4071)
		fprintf(stderr, "Error: wrong determinant: %f, expected: -4071\n", deter);
	else
		printf("Determinant OK\n");
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
	t_sphere	sph;
	t_ray		ray;
	t_intersection	inter;

	ray = ray_new(point_new(0, 0, 5), vector_new(0, 0, 1));
	sph = sphere(point_new(0, 0, 0), 1);
	if (intersection(ray, sph, &inter))
		fprintf(stderr, "No interesection possible\n");
	else
	{
		printf("interest at %f and %f\n", inter.vec.x, inter.vec.y);
	}
	
}

void	object_test(void)
{
	t_object		obj;
	t_intersection	i;
	t_ray			ray;
	t_sphere		sph;
	t_vec2			vec;

	ray = ray_new(point_new(0, 0, 5), vector_new(0, 0, 1));
	sph = sphere(point_new(0, 0, 0), 1);
	i =
}
