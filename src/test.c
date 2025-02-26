#include "minirt.h"
#include "shapes.h"
#include "matrix.h"
#include "light.h"
#include "tuple.h"
#include "mlx_utils.h"
#include "test.h"
#include "colors.h"

void test_init_tuple()
{
	t_tuple	p;
	t_tuple	v;

	p = point_new(4, -4, 3);
	v = vector_new(4, -4, 3);
	fprintf(stderr, "tuple_new tests:\n");
	fprintf(stderr, "p(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n", p.x, p.y, p.z, p.w);
	fprintf(stderr, "v(x: %.2f, y: %.2f, z: %.2f, w: %.2f)\n\n", v.x, v.y, v.z, v.w);

	fprintf(stderr, "!float_equal test\n");
	fprintf(stderr, "double a: %.2f, double b: %.2f are equal if 0: %d\n\n", 4.2F, 4.1F, !float_equal(4.2f, 4.1f));

	fprintf(stderr, "tuple_equal tests:\n");
	fprintf(stderr, "tuple p and v are equal if 0: %d\n\n", tuple_equal(p, v));
}

void test_matrix_determinant()
{
	/*
	double **mfour = matrix_four_by_four(v1, v2, c1, c2);
	for (int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			fprintf(stderr, " 4x4 matrix[%d][%d]: %.2f", i, j, mfour[i][j]);
		}
		fprintf(stderr, "\n");
	}

	double	**mthree = matrix_three_by_three(v1, v2, c1);
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			fprintf(stderr, " 3x3 matrix[%d][%d]: %.2f", i, j, mthree[i][j]);
		}
		fprintf(stderr, "\n");
	}
	double	**mtwo = matrix_two_by_two(v1, v2);
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
	double	**mfour2 = matrix_four_by_four(tuple_new(-2, 1, 2, 3), tuple_new(3, 2, 1, -1), tuple_new(4, 3, 6 ,5), tuple_new(1, 2, 7, 8));
	double	**mfour3 = matrix_multiply(mfour, mfour2);
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
	double	**midentity = matrix_identity();
	double	**mresult = matrix_multiply(mfour, midentity);
	matrix_print(mresult, 4, 4);
	matrix_free(mfour, 4);
	matrix_free(mresult, 4);


	mtwo = matrix_two_by_two(tuple_new(1, 5, 0, 0), tuple_new(-3, 2, 0, 0));
	fprintf(stderr, "\ndeterminant of 2x2 matrix is: %.2f\n", matrix_determinant(mtwo));
	
	matrix_free(mtwo, 2);
	mthree = matrix_three_by_three(tuple_new(1, 5, 0, 0), tuple_new(-3, 2, 7, 0), tuple_new(0, 6, -3, 0));
	
	fprintf(stderr, "\nSubmatrix test\n");
	fprintf(stderr, "mthree:\n");
	matrix_print(mthree, 3, 3);
	
	fprintf(stderr, "submatrix\n");
	double **submatrix = sub_matrix(mthree, 3, 0, 2);
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


	double	**inverse;

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

	double	**A;
	double	**B;
	double	**C;
	double	**D;
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
	// double **rx = matrix_rotate_x(M_PI / 2);
	// double **scale = matrix_scaling(5, 5, 5);
	// double **translation = matrix_translation(tuple_new(10, 5, 7, 0));
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
	t_tuple	p;
	t_tuple	v;
	t_tuple	new;

	p = point_new(4, -4, 3);
	v = vector_new(4, -4, 3);


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
	v1 = vector_new(1, 2, 3);
	v2 = vector_new(2, 3, 4);
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

}


void test_cofactor(t_matrix m, t_matrix expected)
{
	int index;
	double cofac;
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
	double	cofac;

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
	(void)img;
	// ak_mlx_pixel_put(img, 0xFF0000, center);
		
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
	// ak_mlx_pixel_put(img, 0x00FF00, transform(twelve, t));
	// ak_mlx_pixel_put(img, 0xFFFFFF, transform(twelve, rotate_z(radians(0))));
}

// void	inverse_test()
// {
// 	printf("\nInverse test\n");
// 	t_matrix matrix = {{
// 		{ -5, 2 , 6 , -8 },
// 		{ 1, -5 , 1 , 8},
// 		{ 7 , 7 , -6 , -7 },
// 		{ 1, -3 , 7 , 4 },
// 	}};
// 	t_matrix	id;

// 	id = identity();
// 	inverse(matrix, &id);
// 	print_matrix(id.raw);
// }

void	determinant_test()
{
	double	deter;
	double	cof;

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
	if (tuple_equal(result, expected))
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
	if (tuple_equal(result, expected))
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
	if (tuple_equal(result, expected))
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
	if (tuple_equal(result, expected))
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
	// sph = sphere_default();
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
	// double			dis;

	// ray = ray_new(point_new(0, 0, 5), vector_new(0, 0, 1));
	// sph = sphere_default();
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
	if (tuple_equal(new.origin, expected))
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
	if (tuple_equal(new.origin, expected) || tuple_equal(new.direction, vector_new(0, 3, 0)))
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
	// t_ray			ray;
	// t_shape		sph;
	// double			dis;
	// t_vec2			vec;
	// t_intersection	i;
	// t_intersection	j;

	// printf("object transform test\n");
	// ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	// sph = sphere_default();
	// set_transform(&sph, scale(point_new(2, 2, 2)));
	// dis = intersect(ray, sph, &vec);
	// if (dis < 0)
	// 	fprintf(stderr, "\tno intersection possible\n");
	// if (dis >= 0)
	// 	i = intersection(vec.x, sph, vec, dis);
	// if (dis > 0)
	// 	j = intersection(vec.y, sph, vec, dis);
	// printf("\tintersect at %f and %f\n", vec.x, vec.y);


	// ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	// sph = sphere_default();
	// set_transform(&sph, translate(point_new(5, 0, 0)));
	// dis = intersect(ray, sph, &vec);
	// if (dis < 0)
	// 	printf("\tdiscriminant is: %f, no intersection possible\n", dis);
	// else
	// {
	// 	fprintf(stderr, "\tno intersection possible\n");
	// 	if (dis >= 0)
	// 		i = intersection(vec.x, sph, vec, dis);
	// 	if (dis > 0)
	// 		j = intersection(vec.y, sph, vec, dis);
	// 	printf("\tintersect at %f and %f\n", vec.x, vec.y);
	// }
}

// void	draw_sphere(t_img *img)
// {
// 	t_ray	ray;
// 	double	wall_z;
// 	double	wall_size;
// 	int		y;
// 	int		x;
// 	t_tuple	position;
// 	t_intersection inter;
// 	t_shape	sph;

// 	sph = sphere_default();
// 	set_transform(&sph, scale(point_new(10, 10, 10)));

// 	y = 0;
// 	wall_z = 10;
// 	wall_size = 7;
// 	while (y < HEIGHT - 1)
// 	{
// 		x = 0;
// 		while (x < WIDTH - 1)
// 		{
// 			position = point_new(x + -HEIGHT / 2, y - WIDTH /2, wall_z);
// 			ray = ray_new(point_new(x, y, -5), tuple_normalize(tuple_substract(position, ray.origin)));
// 			if (intersect(ray, sph, &inter.vec) >= 0)
// 				ak_mlx_pixel_put(img, x, y, 0xFF0000);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	intersection_test(void)
// {
// 	printf("\nIntersection test\n");

// 	t_ray ray;
// 	t_shape sph;
// 	t_intersection inter;

// 	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
// 	sph = sphere_default();
// 	inter.xs = intersect(ray, sph);
// 	if (inter.xs.x != 4 || inter.xs.y != 6)
// 		fprintf(stderr, "\tError: expected 4, 6; got: %f, %f\n", inter.xs.x, inter.xs.y);
// 	else
// 		printf("\tOk\n");
// 	inter = hit(inter);
// 	if (inter.t != 4)
// 		fprintf(stderr, "inter t is: %f, expected 4\n", inter.t);

// 	ray = ray_new(point_new(0, 1, -5), vector_new(0, 0, 1));
// 	sph = sphere_default();
// 	inter.xs = intersect(ray, sph);
// 	if (inter.xs.x != 5 || inter.xs.y != 5)
// 		fprintf(stderr, "\tError: expected 4, 6; got: %f, %f\n", inter.xs.x, inter.xs.y);
// 	else
// 		printf("\tOk\n");
// 	inter = hit(inter);
// 	if (inter.t != 5)
// 		fprintf(stderr, "inter t is: %f, expected 5\n", inter.t);

// 	ray = ray_new(point_new(0, 2, -5), vector_new(0, 0, 1));
// 	sph = sphere_default();
// 	inter.xs = intersect(ray, sph);
// 	if (inter.xs.dis >= 0)
// 		fprintf(stderr, "\tError: expected 0; got: %f", inter.xs.dis);
// 	else
// 		printf("\tOk\n");
// 	inter = hit(inter);
// 	if (inter.count != 0)
// 		fprintf(stderr, "inter count is: %d, expected 0\n", inter.count);

// 	ray = ray_new(point_new(0, 0, 0), vector_new(0, 0, 1));
// 	sph = sphere_default();
// 	inter.xs = intersect(ray, sph);
// 	if (inter.xs.x != -1.0 || inter.xs.y != 1)
// 		fprintf(stderr, "\tError: expected -1, 1; got: %f, %f", inter.xs.x, inter.xs.y);
// 	else
// 		printf("\tOk\n");
// 	inter = hit(inter);
// 	if (inter.t != 1)
// 		fprintf(stderr, "inter t is: %f, expected 1\n", inter.t);


// 	ray = ray_new(point_new(0, 0, 5), vector_new(0, 0, 1));
// 	sph = sphere_default();
// 	inter.xs = intersect(ray, sph);
// 	if (inter.xs.x != -6.0 || inter.xs.y != -4.0)
// 		fprintf(stderr, "\tError: expected -6, -4; got: %f, %f", inter.xs.x, inter.xs.y);
// 	else
// 		printf("\tOk\n");
// 	inter = hit(inter);
// 	if (inter.t != 0)
// 		fprintf(stderr, "inter t is: %f, expected 0\n", inter.t);
// }

// void	draw_sphere(t_img *img, t_mlx *mlx)
// {
// 	double			y;
// 	double			x;
// 	double			world_x;
// 	double			world_y;
// 	double			wall_z;
// 	double			wall_size;
// 	double			canvas_pixel;
// 	double			pixel_size;
// 	double			half;
// 	t_tuple			pos;
// 	t_tuple			point;
// 	t_ray			r;
// 	t_shape 		sph;
// 	t_intersection	inter;
// 	t_light			light;
// 	t_tuple			normalv;
// 	t_tuple			eyev;
// 	t_tuple			color;
// 	t_tuple			origin;

// 	y = 0;
// 	origin = point_new(0, 0, -5);
// 	wall_z = 10;
// 	wall_size = 7;
// 	canvas_pixel = 500;
// 	pixel_size = wall_size / canvas_pixel;
// 	half = wall_size / 2;
// 	sph = sphere_default();
// 	sph.matter = material();
// 	sph.matter.color = color_new(1, 0.2, 1);
// 	light = point_light(point_new(-10, -10, -10), color_new(1, 1, 1));
// 	while (y < canvas_pixel - 1)
// 	{
// 		x = 0;
// 		world_y = half - pixel_size * y;
// 		while (x < canvas_pixel - 1)
// 		{
// 			world_x = -half + pixel_size * x;
// 			pos = point_new(world_x, world_y, wall_z);
// 			r = ray_new(origin, tuple_normalize(tuple_substract(pos, origin)));
// 			inter = hit(intersection(sph, intersect(r, sph)));
// 			if (inter.count > 0)
// 			{
// 				point = position(r, inter.t);
// 				eyev = tuple_negate(r.direction);
// 				normalv = normal_at(inter.object, point);
// 				color = lighting(inter.object.matter, light, eyev, normalv, point);
// 				ak_mlx_pixel_put(img, x, HEIGHT - y, tuple_tocolor(color));
// 			}
// 			x++;
// 		}
// 		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
// 		y++;
// 	}
// }

// void	normal_at_test(void)
// {
// 	t_shape	sph;
// 	t_tuple		normal;
// 	t_tuple		expected;

// 	printf("\nnormal at test\n");
// 	sph = sphere_default();
// 	set_transform(&sph, translate(0, 1, 0));
// 	normal = normal_at(sph, point_new(0, 1.70711, -0.70711));
// 	expected = vector_new(0, 0.70711, -0.70711);
// 	if (tuple_equal(normal, expected))
// 	{
// 		fprintf(stderr, "\terror:\texpected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(normal);
// 	}

// 	sph = sphere_default();
// 	set_transform(&sph, multiply_matrix(scale(1, 0.5, 1), rotate_z(M_PI / 5)));
// 	normal = normal_at(sph, point_new(0, sqrt(2) / 2, -sqrt(2) / 2));
// 	expected = vector_new(0, 0.97014, -0.24254);
// 	if (tuple_equal(normal, expected))
// 	{
// 		fprintf(stderr, "\terror:\texpected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(normal);
// 	}
// }

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
	if (tuple_equal(r, expected))
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
	if (tuple_equal(r, expected))
	{
		fprintf(stderr, "\terror:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(r);
	}
	else
		printf("\tOK\n");
}


void	test_light(void)
{
	printf("\nLighting test\n");

	t_material	mat;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_light		light;
	t_tuple		result;
	t_tuple		expected;

	mat = material();
	point = point_new(0, 0, 0);


	eyev = vector_new(0, 0, -1);
	normalv = vector_new(0, 0, -1);
	light = point_light(point_new(0, 0, -10), color_new(1, 1, 1));
	result = lighting(mat, light, eyev, normalv, point);
	expected = color_new(1.9, 1.9, 1.9);
	if (tuple_equal(expected, result))
	{
		fprintf(stderr, "\terror:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(result);
	}
	else
	{
		printf("\tOK\n");
	}


	eyev = vector_new(0, sqrt(2)/2, sqrt(2)/2);
	normalv = vector_new(0, 0, -1);
	light = point_light(point_new(0, 0, -10), color_new(1, 1, 1));
	result = lighting(mat, light, eyev, normalv, point);
	expected = color_new(1.0, 1.0, 1.0);
	if (tuple_equal(expected, result))
	{
		fprintf(stderr, "\terror:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(result);
	}
	else
	{
		printf("\tOK\n");
	}


	eyev = vector_new(0, 0, 0);
	normalv = vector_new(0, 0, -1);
	light = point_light(point_new(0, 10, -10), color_new(1, 1, 1));
	result = lighting(mat, light, eyev, normalv, point);
	expected = color_new(0.7364, 0.7364, 0.7364);
	if (tuple_equal(expected, result))
	{
		fprintf(stderr, "\terror:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(result);
	}
	else
	{
		printf("\tOK\n");
	}



	eyev = vector_new(0, -sqrt(2)/2, -sqrt(2)/2);
	normalv = vector_new(0, 0, -1);
	light = point_light(point_new(0, 10, -10), color_new(1, 1, 1));
	result = lighting(mat, light, eyev, normalv, point);
	expected = color_new(1.6364, 1.6364, 1.6364);
	if (tuple_equal(expected, result))
	{
		fprintf(stderr, "\terror:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(result);
	}
	else
	{
		printf("\tOK\n");
	}


	eyev = vector_new(0, 0, -1);
	normalv = vector_new(0, 0, -1);
	light = point_light(point_new(0, 0, 10), color_new(1, 1, 1));
	result = lighting(mat, light, eyev, normalv, point);
	expected = color_new(0.1, 0.1, 0.1);
	if (tuple_equal(expected, result))
	{
		fprintf(stderr, "\terror:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(result);
	}
	else
	{
		printf("\tOK\n");
	}
}

void	test_intersect_world(void)
{
	int			i;
	t_ray		ray;
	t_world		world;
	t_junction	hits;

	i = 0;
	world = default_world();
	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	intersect_world(&world, ray, &hits);
	printf("hits count is: %d\n", hits.count);
	while (i < hits.count)
	{
		printf("hits[%d].t: %f\n", i, hits.cross[i].t);
		i++;
	}
}

void	test_pre_compute(void)
{
	// t_ray		ray;
	// t_crossing	cross;
	// t_comps		comps;
	// t_junction	junc;

	// printf("\nPre_compute test\n");

	// ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	// cross.obj = sphere_default();
	// cross.t = 4;
	// comps = pre_compute(cross, ray, junc);
	// if (tuple_equal(comps.world_point, point_new(0, 0, -1)))
	// {
	// 	fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
	// 	tuple_print(comps.world_point);
	// }
	// else
	// {
	// 	printf("\tOK\n");
	// }
	// if (tuple_equal(comps.eyev, vector_new(0, 0, -1)))
	// {
	// 	fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
	// 	tuple_print(comps.eyev);
	// }
	// else
	// {
	// 	printf("\tOK\n");
	// }
	// if (tuple_equal(comps.normalv, vector_new(0, 0, -1)))
	// {
	// 	fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
	// 	tuple_print(comps.normalv);
	// }
	// else
	// {
	// 	printf("\tOK\n");
	// }


	// ray = ray_new(point_new(0, 0, 0), vector_new(0, 0, 1));
	// cross.obj = sphere_default();
	// cross.t = 1;
	// comps = pre_compute(cross, ray, junc);
	// if (tuple_equal(comps.world_point, point_new(0, 0, 1)))
	// {
	// 	fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
	// 	tuple_print(comps.world_point);
	// }
	// else
	// {
	// 	printf("\tOK\n");
	// }
	// if (tuple_equal(comps.eyev, vector_new(0, 0, -1)))
	// {
	// 	fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
	// 	tuple_print(comps.eyev);
	// }
	// else
	// {
	// 	printf("\tOK\n");
	// }
	// if (tuple_equal(comps.normalv, vector_new(0, 0, -1)))
	// {
	// 	fprintf(stderr, "\tError: expected: 0, 0, -1\n\tgot:\t");
	// 	tuple_print(comps.normalv);
	// }
	// else
	// {
	// 	printf("\tOK\n");
	// }
	// if (!comps.inside)
	// 	printf("\tError: expected comps.inside = true\n");
	// else
	// 	printf("\tOK\n");
}

void	test_shading(void)
{
	// t_world		world;
	// t_ray		ray;
	// t_crossing	cross;
	// t_comps		comps;
	// t_tuple		color;
	// t_junction	junc;

	// printf("\nShading test\n");
	// world = default_world();
	// // tuple_print(world.light.position);
	// // tuple_print(world.light.intensity);
	// // tuple_print(world.obj[0].coordinates);
	// // tuple_print(world.obj[0].matter.color);
	// // printf("object diffuse: %f, specular: %f, ambient: %f, shininess: %f\n", world.obj[0].matter.diffuse, world.obj[0].matter.specular,
	// // 		world.obj[0].matter.ambient, world.obj[0].matter.shininess);
	// // tuple_print(world.obj[0].coordinates);
	// ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	// cross.t = 4;
	// cross.obj = world.obj[0];
	// comps = pre_compute(cross, ray, junc);
	// color = shade_hit(world, comps, 5);
	// if (tuple_equal(color, color_new(0.380f, 0.475f, 0.285f)))
	// {
	// 	fprintf(stderr, "\tError:\texpected:\t");
	// 	tuple_print(color_new(0.380f, 0.475f, 0.285f));
	// 	fprintf(stderr, "\tgot:\t\t\t");
	// 	tuple_print(color);
	// }
	// else
	// {
	// 	printf("\tOK\n");
	// }


	// ray = ray_new(point_new(0, 0, 0), vector_new(0, 0, 1));
	// world.light = point_light(point_new(0, 0.25, 0), color_new(1, 1, 1));
	// cross.obj = world.obj[1];
	// cross.t = 0.5;
	// comps = pre_compute(cross, ray, junc);
	// color = shade_hit(world, comps, 5);
	// t_tuple expected = color_new(0.90498, 0.90498, 0.90498);
	// if (tuple_equal(color, expected))
	// {
	// 	fprintf(stderr, "\tError:\texpected:\t");
	// 	tuple_print(expected);
	// 	fprintf(stderr, "\tgot:\t\t\t");
	// 	tuple_print(color);
	// }
	// else
	// {
	// 	printf("\tOK\n");
	// }
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
	color = color_at(&world, ray, 5);
	expected = color_new(0, 0, 0);
	if (tuple_equal(color, expected))
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
	color = color_at(&world, ray, 5);
	expected = color_new(0.38066, 0.47583, 0.2855);
	if (tuple_equal(color, expected))
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
	color = color_at(&world, ray, 5);
	expected = world.obj[1].matter.color;
	if (tuple_equal(color, expected))
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

void	test_view_transform(void)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_matrix	m;
	t_matrix	expected;

	printf("\nTest view transform\n");
	from = point_new(0, 0, 0); 
	to = point_new(0, 0, -1);
	up = vector_new(0, 1, 0);
	m = view_transform(from, to, up);
	if (matrix_cmp(m, identity(), 4, 4))
	{
		fprintf(stderr, "\tError:\texpected:\n");
		print_matrix(identity().raw);
		fprintf(stderr, "\tgot:\n");
		print_matrix(m.raw);
	}
	else
	{
		printf("\tOK\n");
	}

	from = point_new(1, 3, 2); 
	to = point_new(4, -2, 8);
	up = vector_new(1, 1, 0);
	m = view_transform(from, to, up);
	expected = (t_matrix){{
		{-0.507093,	0.507093,	0.676123,	-2.366432},
		{0.767716,	0.606091,	0.121218,	-2.828427},
		{-0.358569,	0.597614,	-0.71713,7	-0.000000},
		{0.000000,	0.000000,	0.000000,	1.000000}
	}};
	if (matrix_cmp(m, expected, 4, 4))
	{
		fprintf(stderr, "\tError:\texpected:\n");
		print_matrix(expected.raw);
		fprintf(stderr, "\tgot:\n");
		print_matrix(m.raw);
	}
	else
	{
		printf("\tOK\n");
	}
}


void	test_camera(void)
{
	t_camera	cam;


	printf("\nCamera test\n");
	cam = camera_new(200, 125, M_PI / 2);
	// printf("camera hsize: %f, vsize: %f, fov: %f\n", cam.hsize, cam.vsize, cam.fov);
	// print_matrix(cam.transform.raw);
	if (!float_equal(0.01, cam.psize))
	{
		fprintf(stderr, "\tError: expected: 0.01, got: %f\n", cam.psize);
	}
	else
	{
		printf("\tOK\n");
	}
	cam = camera_new(125, 200, M_PI / 2);
	// printf("camera hsize: %f, vsize: %f, fov: %f\n", cam.hsize, cam.vsize, cam.fov);
	// print_matrix(cam.transform.raw);
	if (!float_equal(0.01, cam.psize))
	{
		fprintf(stderr, "\tError: expected: 0.01, got: %f\n", cam.psize);
	}
	else
	{
		printf("\tOK\n");
	}
}

void	test_ray_for_pixel(void)
{
	t_camera cam;
	t_ray	ray;
	t_ray	expected;

	printf("\nTest ray for pixel\n");
	cam = camera_new(201, 101, M_PI / 2.0f);
	ray_for_pixel(&cam, &ray, 100, 50);
	expected = ray_new(point_new(0, 0, 0), vector_new(0, 0, -1));
	if (tuple_equal(ray.direction, expected.direction) || tuple_equal(ray.origin, expected.origin))
	{
		fprintf(stderr, "\tError:\texpected:\n");
		tuple_print(expected.origin);
		tuple_print(expected.direction);
		fprintf(stderr, "\tgot:\n");
		tuple_print(ray.origin);
		tuple_print(ray.direction);
		fprintf(stderr, "\n");
	}
	else
	{
		printf("\tOK\n");
	}
	cam = camera_new(201, 101, M_PI / 2.0f);
	ray_for_pixel(&cam, &ray, 0, 0);
	expected = ray_new(point_new(0, 0, 0), vector_new(0.66519, 0.33259, -0.66851));
	if (tuple_equal(ray.direction, expected.direction) || tuple_equal(ray.origin, expected.origin))
	{
		fprintf(stderr, "\tError:\texpected:\n");
		tuple_print(expected.origin);
		tuple_print(expected.direction);
		fprintf(stderr, "\tgot:\n");
		tuple_print(ray.origin);
		tuple_print(ray.direction);
		fprintf(stderr, "\n");
	}
	else
	{
		printf("\tOK\n");
	}
	cam = camera_new(201, 101, M_PI / 2.0f);
	cam.transform = multiply_matrix(rotate_y(M_PI / 4.0f), translate(0, -2, 5));
	ray_for_pixel(&cam, &ray, 100, 50);
	expected = ray_new(point_new(0, 2, -5), vector_new(sqrt(2)/2, 0, -sqrt(2)/2));
	if (tuple_equal(ray.direction, expected.direction) || tuple_equal(ray.origin, expected.origin))
	{
		fprintf(stderr, "\tError:\texpected:\n");
		tuple_print(expected.origin);
		tuple_print(expected.direction);
		fprintf(stderr, "\tgot:\n");
		tuple_print(ray.origin);
		tuple_print(ray.direction);
		fprintf(stderr, "\n");
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

void	test_is_shadowed(void)
{
	t_world	world;


	printf("\nTest is_shadowed\n");

	world = default_world();
	if (!is_shadowed(&world, point_new(0, 10, 0)))
		printf("\tOK\n");
	else
	{
		fprintf(stderr, "\tError: should false\n");
	}
	

	if (is_shadowed(&world, point_new(10, -10, 10)))
		printf("\tOK\n");
	else
	{
		fprintf(stderr, "\tError: should be true\n");
	}
	if (!is_shadowed(&world, point_new(-20, 20, -20)))
		printf("\tOK\n");
	else
	{
		fprintf(stderr, "\tError: should be false\n");
	}


	if (!is_shadowed(&world, point_new(-2, 2, -2)))
		printf("\tOK\n");
	else
	{
		fprintf(stderr, "\tError: should be false\n");
	}
}

t_shape	test_shape(void)
{
	return ((t_shape){
		.matter = material(),
		.transform = identity(),
	});
}

// void	test_shape_obj(void)
// {
// 	t_shape	s;
// 	s = test_shape();
// 	s.transform = translate(2, 3, 4);
// 	s.matter.ambient = 1;
// 	print_matrix(s.transform.raw);
// }

// void	test_intersect_plane(void)
// {
// 	t_shape	plane;
// 	t_ray	ray;
// 	t_intersection	hit;

// 	printf("\n Intersect plane test\n");
// 	plane = plane_new();

// 	ray = ray_new(point_new(0, 10, 0), vector_new(0, 0, 1));
// 	hit = intersection(plane, plane.local_interesct(ray, plane));
// 	if (plane.local_interesct(ray, plane).dis >= 0)
// 	{
// 		fprintf(stderr, "\tError: expected hit count 0\n");
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}

// 	ray = ray_new(point_new(0, 0, 0), vector_new(0, 0, 1));
// 	hit = intersection(plane, plane.local_interesct(ray, plane));
// 	if (plane.local_interesct(ray, plane).dis >= 0)
// 	{
// 		fprintf(stderr, "\tError: expected hit count 0\n");
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}

// 	ray = ray_new(point_new(0, 1, 0), vector_new(0, -1, 0));
// 	hit = intersection(plane, plane.local_interesct(ray, plane));
// 	if (hit.count != 1 || hit.t != 1)
// 	{
// 		fprintf(stderr, "\tError: expected hit count 1, got: %d, expected t: 1, got: %f\n", hit.count, hit.t);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}

// 	ray = ray_new(point_new(0, -1, 0), vector_new(0, 1, 0));
// 	hit = intersection(plane, plane.local_interesct(ray, plane));
// 	if (hit.count != 1 || hit.t != 1)
// 	{
// 		fprintf(stderr, "\tError: expected hit count 1, got: %d, expected t: 1, got: %f\n", hit.count, hit.t);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}	
// }

void	test_stripe_at(void)
{
// 	t_pattern	pattern;
// 	t_shape		sph;
// 	t_tuple		color;
// 	t_tuple		expected;
// 	t_material	mat;
// 	t_tuple		eyev;
// 	t_tuple		normalv;
// 	t_light		light;

// 	printf("\n Stripe at test\n");

// 	sph = sphere_default();
// 	//expect white 1, 1, 1
// 	pattern = stripe_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
// 	expected = color_new(1, 1, 1);
// 	color = stripe_at(pattern, point_new(0, 0, 0));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}
	
// 	//expect white 1, 1, 1
// 	expected = color_new(1, 1, 1);
// 	color = stripe_at(pattern, point_new(0, 1, 0));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}

// 	//expect white 1, 1, 1
// 	expected = color_new(1, 1, 1);
// 	color = stripe_at(pattern, point_new(0, 2, 0));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}
	
// /* --------------------------------------------------------------------------- */

// 	expected = color_new(1, 1, 1);
// 	color = stripe_at(pattern, point_new(0, 0, 0));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}
	
// 	expected = color_new(1, 1, 1);
// 	color = stripe_at(pattern, point_new(0, 0, 1));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}
	
// 	expected = color_new(1, 1, 1);
// 	color = stripe_at(pattern, point_new(0, 0, 2));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}

// /* --------------------------------------------------------------------------- */

// 	//expect white 1, 1, 1
// 	expected = color_new(1, 1, 1);
// 	color = stripe_at(pattern, point_new(0, 0, 0));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}
	
// 	expected = color_new(1, 1, 1);
// 	color = stripe_at(pattern, point_new(0.9, 0, 0));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}
	
// 	expected = color_new(0, 0, 0);
// 	color = stripe_at(pattern, point_new(1, 0, 0));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}
// 	expected = color_new(0, 0, 0);
// 	color = stripe_at(pattern, point_new(-0.1, 0, 0));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}
// 	expected = color_new(0, 0, 0);
// 	color = stripe_at(pattern, point_new(-1, 0, 0));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}
// 	expected = color_new(1, 1, 1);
// 	color = stripe_at(pattern, point_new(-1.1, 0, 0));
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError: expected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}

// /* --------------------------------------------------------------------------- */

// 	printf("\n Test stripe at with blinn-phong\n");

// 	mat = material();
// 	mat.pattern = stripe_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
// 	mat.ambient = 1;
// 	mat.diffuse = 0;
// 	mat.specular = 0;
// 	eyev = vector_new(0, 0, -1);
// 	normalv = vector_new(0, 0, -1);	
// 	light = point_light(point_new(0, 0, -10), color_new(1, 1, 1));
// 	color = blinn_phong(mat, light, point_new(0.9, 0, 0), eyev, normalv, false, sph);
// 	expected = color_new(1, 1, 1);
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError:\texpected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t:");
// 		tuple_print(color);
// 	}
// 	else
// 	{
// 		printf("\tOK\n");
// 	}

// 	color = blinn_phong(mat, light, point_new(1.1, 0, 0), eyev, normalv, false, sph);
// 	expected = color_new(0, 0, 0);
// 	if (tuple_equal(color, expected))
// 	{
// 		fprintf(stderr, "\tError:\texpected:\t");
// 		tuple_print(expected);
// 		fprintf(stderr, "\tgot:\t\t\t:");
// 		tuple_print(color);
// 	}
// 	else
// 		printf("\tOK\n");
}

// void	test_gradient(void)
// {
// 	t_pattern pat;
// 	t_tuple		expected;

// 	pat = gradient_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
// 	if (tuple_equal())
// }

void	test_reflection(void)
{
	// t_shape 		plane;
	// t_ray			ray;
	// t_crossing		cross;
	// t_comps			comps;
	// t_world			world;
	// t_tuple			color;
	// t_junction		hits;

	// printf("\nTest reflection\n");

	// plane = plane_new();
	// ray = ray_new(point_new(0, 1, -1), vector_new(0, -sqrt(2)/2, sqrt(2)/2));
	// cross.t = sqrtf(2.0f);
	// cross.obj = plane;
	// comps = pre_compute(cross, ray, hits.cross);
	// tuple_print(comps.reflectv);

	// world = default_world();
	// plane.matter.reflective = 0.5;
	// plane.transform = translate(0, -1, 0);
	// ray = ray_new(point_new(0, 0, -3), vector_new(0, -sqrt(2)/2, sqrt(2)/2));
	// cross.t = sqrtf(2.0f);
	// comps = pre_compute(cross, ray, hits.cross);
	// color = shade_hit(world, comps, 5);
	// tuple_print(color);
}

unsigned int		new_id(void)
{
	static unsigned int	random;

	return (random++);
}

void	test_refraction(void)
{
	t_world		world;
	t_ray		ray;
	t_comps		comps;
	t_junction	junc;

	world.obj[0] = glass_sphere();
	world.obj[1] = glass_sphere();
	world.obj[2] = glass_sphere();

	set_transform(&world.obj[0], scale(2, 2, 2));
	world.obj[0].matter.refractive_index = 1.5;
	set_transform(&world.obj[1], translate(0, 0, -0.25));
	world.obj[1].matter.refractive_index = 2.0;
	set_transform(&world.obj[2], translate(0, 0, 0.25));
	world.obj[2].matter.refractive_index = 2.5;
	
	ray = ray_new(point_new(0, 0, -4), vector_new(0, 0, 1));
	junc.cross[0].t = 2;
	junc.cross[0].obj = &world.obj[0];
	junc.cross[1].t = 2.75;
	junc.cross[1].obj = &world.obj[1];
	junc.cross[2].t = 3.25;
	junc.cross[2].obj = &world.obj[2];
	junc.cross[3].t = 4.75;
	junc.cross[3].obj = &world.obj[1];
	junc.cross[4].t = 5.25;
	junc.cross[4].obj = &world.obj[2];
	junc.cross[5].t = 6;
	junc.cross[5].obj = &world.obj[0];
	junc.count = 6;
	for(int i = 0; i < 6; i++)
	{
		pre_compute(&comps, junc.cross[i], ray, junc);
		printf("n1 is:%f n2 is: %f\n", comps.n1, comps.n2);
	}
}

void	test_negative_intersection(void)
{
	t_world		world;
	t_ray		ray;
	t_junction	junc;

	world.obj[0] = glass_sphere();
	world.obj[1] = glass_sphere();
	world.obj[2] = glass_sphere();

	set_transform(&world.obj[0], scale(2, 2, 2));
	set_transform(&world.obj[1], translate(0, 0, -0.25));
	set_transform(&world.obj[2], translate(0, 0, 0.25));

	world.obj[0].matter.refractive_index = 1.5;
	world.obj[1].matter.refractive_index = 2.0;
	world.obj[2].matter.refractive_index = 2.5;

	world.obj_count = 3;

	ray = ray_new(point_new(0, 0, -4), vector_new(0, 0, 1));
	intersect_world(&world, ray, &junc);
	for (int i = 0; i < junc.count; i++)
		printf("interestction is: %f\n", junc.cross[i].t);
	printf("hit is: %f\n", junc.closest.t);
}

void	test_shade_hit_refraction(void)
{
	t_world	world;
	t_shape	floor;
	t_shape	ball;
	t_ray	ray;
	t_comps	comps;
	t_junction	junc;
	t_tuple		color;

	world = default_world();
	floor = plane_new();
	set_transform(&floor, translate(0, -1, 0));
	floor.matter.transparency = 0.5;
	floor.matter.refractive_index = 1.5;
	world.obj[0] = floor;
	
	ball = sphere_default();
	ball.matter.color = red();
	ball.matter.ambient = 0.5;
	set_transform(&ball, translate(0, -3.5, -0.5));
	world.obj[1] = ball;
	world.obj_count = 2;

	ray = ray_new(point_new(0, 0, -3), vector_new(0, -sqrt(2/2), sqrt(2/2)));
	junc.cross[0].t = sqrt(2);
	junc.cross[0].obj = &floor;
	junc.count = 1;
	pre_compute(&comps, junc.cross[0], ray, junc);
	color = shade_hit(&world, &comps, 5);
	tuple_print(color);
}

void	evaluate(double a, double b, double ea, double eb)
{
	if (!float_equal(a, ea))
		fprintf(stderr, "Error: got: %f, expected %f\n", a, ea);
	else
		printf("OK!\n");
	if (!float_equal(b, eb))
		fprintf(stderr, "Error: got: %f, expected %f\n", b, eb);
	else
		printf("OK!\n");
}

// void	test_cube(void)
// {
// 	t_shape	cube;
// 	t_ray	ray;
// 	t_vec2	xs;

// 	printf("\nTest cube intersect\n");
// 	cube = cube_default();

// 	ray = ray_new(point_new(5, 0.5, 0), vector_new(-1, 0, 0));
// 	xs = cube_intersect(ray, cube);
// 	evaluate(xs.x, xs.y, 4.0, 6.0);

// 	ray = ray_new(point_new(-5, 0.5, 0), vector_new(1, 0, 0));
// 	xs = cube_intersect(ray, cube);
// 	evaluate(xs.x, xs.y, 4.0, 6.0);

// 	ray = ray_new(point_new(0.5, 5, 0), vector_new(0, -1, 0));
// 	xs = cube_intersect(ray, cube);
// 	evaluate(xs.x, xs.y, 4.0, 6.0);

// 	ray = ray_new(point_new(0.5, -5, 0), vector_new(0, 1, 0));
// 	xs = cube_intersect(ray, cube);
// 	evaluate(xs.x, xs.y, 4.0, 6.0);

// 	ray = ray_new(point_new(0.5, 0, 5), vector_new(0, 0, -1));
// 	xs = cube_intersect(ray, cube);
// 	evaluate(xs.x, xs.y, 4.0, 6.0);

// 	ray = ray_new(point_new(0.5, 0, -5), vector_new(0, 0, 1));
// 	xs = cube_intersect(ray, cube);
// 	evaluate(xs.x, xs.y, 4.0, 6.0);

// 	ray = ray_new(point_new(0, 0.5, 0), vector_new(0, 0, 1));
// 	xs = cube_intersect(ray, cube);
// 	evaluate(xs.x, xs.y, -1, 1);
// }

// void	test_cube_normalat(void)
// {
// 	t_shape shape;
// 	t_tuple	point;
// 	t_tuple	expected;

// 	printf("\nTest cube normal at\n");
// 	shape = cube_default();
// 	point = point_new(1, 0.5, -0.8) ;
// 	expected = vector_new(1, 0, 0) ;
// 	if (tuple_equal(cube_normal_at(shape, point), expected))
// 	{
// 		fprintf(stderr, "Error: expected:\n");
// 		tuple_print(expected);
// 		fprintf(stderr, "got:\n");
// 		tuple_print(cube_normal_at(shape, point));
// 	}
// 	else
// 		printf("OK!\n");
// 	point = point_new(-1, -0.2, 0.9);
// 	expected = vector_new(-1, 0, 0) ;
// 	if (tuple_equal(cube_normal_at(shape, point), expected))
// 	{
// 		fprintf(stderr, "Error: expected:\n");
// 		tuple_print(expected);
// 		fprintf(stderr, "got:\n");
// 		tuple_print(cube_normal_at(shape, point));
// 	}
// 	else
// 		printf("OK!\n");
// 	point = point_new(-0.4, 1, -0.1);
// 	expected = vector_new(0, 1, 0) ;
// 	if (tuple_equal(cube_normal_at(shape, point), expected))
// 	{
// 		fprintf(stderr, "Error: expected:\n");
// 		tuple_print(expected);
// 		fprintf(stderr, "got:\n");
// 		tuple_print(cube_normal_at(shape, point));
// 	}
// 	else
// 		printf("OK!\n");
// 	point = point_new(0.3, -1, -0.7);
// 	expected = vector_new(0, -1, 0) ;
// 	if (tuple_equal(cube_normal_at(shape, point), expected))
// 	{
// 		fprintf(stderr, "Error: expected:\n");
// 		tuple_print(expected);
// 		fprintf(stderr, "got:\n");
// 		tuple_print(cube_normal_at(shape, point));
// 	}
// 	else
// 		printf("OK!\n");
// 	point = point_new(-0.6, 0.3, 1) ;
// 	expected = vector_new(0, 0, 1) ;
// 	if (tuple_equal(cube_normal_at(shape, point), expected))
// 	{
// 		fprintf(stderr, "Error: expected:\n");
// 		tuple_print(expected);
// 		fprintf(stderr, "got:\n");
// 		tuple_print(cube_normal_at(shape, point));
// 	}
// 	else
// 		printf("OK!\n");
// 	point = point_new(0.4, 0.4, -1) ;
// 	expected = vector_new(0, 0, -1) ;
// 	if (tuple_equal(cube_normal_at(shape, point), expected))
// 	{
// 		fprintf(stderr, "Error: expected:\n");
// 		tuple_print(expected);
// 		fprintf(stderr, "got:\n");
// 		tuple_print(cube_normal_at(shape, point));
// 	}
// 	else
// 		printf("OK!\n");
// 	point = point_new(1, 1, 1);
// 	expected = vector_new(1, 0, 0) ;
// 	if (tuple_equal(cube_normal_at(shape, point), expected))
// 	{
// 		fprintf(stderr, "Error: expected:\n");
// 		tuple_print(expected);
// 		fprintf(stderr, "got:\n");
// 		tuple_print(cube_normal_at(shape, point));
// 	}
// 	else
// 		printf("OK!\n");
// 	point = point_new(-1, -1, -1);
// 	expected = vector_new(-1, 0, 0) ;
// 	if (tuple_equal(cube_normal_at(shape, point), expected))
// 	{
// 		fprintf(stderr, "Error: expected:\n");
// 		tuple_print(expected);
// 		fprintf(stderr, "got:\n");
// 		tuple_print(cube_normal_at(shape, point));
// 	}
// 	else
// 		printf("OK!\n");
// 	}

void	test_cylinder_intersect(void)
{
	printf("\nCylinder Intersect\nMiss:\n");
	t_shape	cylinder;
	t_ray	ray;
	t_vec2	inter;

	cylinder = cylinder_default();
	ray = ray_new(point_new(1, 0, 0), vector_new(0, 1, 0));
	inter = cylinder.local_interesct(&cylinder, ray);
	if (inter.dis >= 0.0)
		fprintf(stderr, "Error1: expected no intersections\n");
	else
	{
		printf("OK\n");
	}
	
	
	ray = ray_new(point_new(0, 0, 0), vector_new(0, 1, 0));
	inter = cylinder.local_interesct(&cylinder, ray);
	if (inter.dis >= 0.0)
		fprintf(stderr, "Error2: expected no intersections\n");
	else
	{
		printf("OK\n");
	}
	

	ray = ray_new(point_new(0, 0, -5), vector_new(1, 1, 1));
	inter = cylinder.local_interesct(&cylinder, ray);
	if (inter.dis >= 0.0)
		fprintf(stderr, "Error3: expected no intersections\n");
	else
	{
		printf("OK\n");
	}


	printf("Hit:\n");
	ray = ray_new(point_new(1, 0, -5), vector_new(0, 0, 1));
	inter = cylinder.local_interesct(&cylinder, ray);
	if (inter.dis < 0.0 || !float_equal(5.00000, inter.x) || !float_equal(5.00000, inter.y))
	{
		fprintf(stderr, "!float_equal(5.0, 5.0): %d\n", !float_equal(5.000001, 5.0));
		fprintf(stderr, "Error4: dis is: %f, x is: %f, y is: %f\n",inter.dis, inter.x, inter.y);
	}
	else
	{
		printf("OK\n");
	}


	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	inter = cylinder.local_interesct(&cylinder, ray);
	if (inter.dis < 0.0 || !float_equal(4.0, inter.x) || !float_equal(6.0, inter.y))
	{
		fprintf(stderr, "Error5: dis is: %f, x is: %f, y is: %f\n",inter.dis, inter.x, inter.y);
	}
	else
	{
		printf("OK\n");
	}

	ray = ray_new(point_new(0.5, 0, -5), tuple_normalize(vector_new(0.1, 1, 1)));
	inter = cylinder.local_interesct(&cylinder, ray);
	if (inter.dis < 0.0 || !float_equal(6.807982, inter.x) || !float_equal(7.088723, inter.y))
	{
		fprintf(stderr, "Error6: dis is: %f, x is: %f, y is: %f\n",inter.dis, inter.x, inter.y);
	}
	else
	{
		printf("OK\n");
	}
}

void	test_cylinder_normalat(void)
{
	t_shape	cylinder;
	t_tuple	expected;
	t_tuple	normalv;

	printf("\nTest cylinder normalat\n");
	cylinder = cylinder_default();

	normalv = cylinder.local_normalat(&cylinder, point_new(1, 0, 0));
	expected = vector_new(1, 0, 0);
	if (!tuple_equal(normalv, expected))
	{
		fprintf(stderr, "Error: expected:\n");
		tuple_print(expected);
		fprintf(stderr, "got:\n");
		tuple_print(normalv);
	}
	else
		printf("OK\n");

	normalv = cylinder.local_normalat(&cylinder, point_new(0, 5, -1));
	expected = vector_new(0, 0, -1);
	if (!tuple_equal(normalv, expected))
	{
		fprintf(stderr, "Error: expected:\n");
		tuple_print(expected);
		fprintf(stderr, "got:\n");
		tuple_print(normalv);
	}
	else
		printf("OK\n");

	normalv = cylinder.local_normalat(&cylinder, point_new(0, -2, 1));
	expected = vector_new(0, 0, 1);
	if (!tuple_equal(normalv, expected))
	{
		fprintf(stderr, "Error: expected:\n");
		tuple_print(expected);
		fprintf(stderr, "got:\n");
		tuple_print(normalv);
	}
	else
		printf("OK\n");

	normalv = cylinder.local_normalat(&cylinder, point_new(-1, 1, 0));
	expected =	vector_new(-1, 0, 0);
	if (!tuple_equal(normalv, expected))
	{
		fprintf(stderr, "Error: expected:\n");
		tuple_print(expected);
		fprintf(stderr, "got:\n");
		tuple_print(normalv);
	}
	else
		printf("OK\n");

}

// void	test_truncated_cylinder(void)
// {
// 	t_shape	cylinder;
// 	t_ray	ray;
// 	t_vec2	xs;

// 	printf("\n Test truncated cylinder\n");
// 	cylinder = cylinder_default();
// 	cylinder.min = 1.0;
// 	cylinder.max = 2.0;

// 	ray = ray_new(point_new(0, 1.5, 0), tuple_normalize(vector_new(0.1, 1, 0)));
// 	xs = cylinder.local_interesct(ray, cylinder);
// 	if (xs.dis >= 0.0)
// 		fprintf(stderr, "Error: dis is: %f\n", xs.dis);
// 	else
// 		printf("OK\n");

// 	ray = ray_new(point_new(0, 3, -5), tuple_normalize(vector_new(0, 0, 1)));
// 	xs = cylinder.local_interesct(ray, cylinder);
// 	if (xs.dis >= 0.0)
// 		fprintf(stderr, "Error: dis is: %f\n", xs.dis);
// 	else
// 		printf("OK\n");

// 	ray = ray_new(point_new(0, 0, -5), tuple_normalize(vector_new(0, 0, 1)));
// 	xs = cylinder.local_interesct(ray, cylinder);
// 	if (xs.dis >= 0.0)
// 		fprintf(stderr, "Error: dis is: %f\n", xs.dis);
// 	else
// 		printf("OK\n");

// 	ray = ray_new(point_new(0, 2, -5), tuple_normalize(vector_new(0, 0, 1)));
// 	xs = cylinder.local_interesct(ray, cylinder);
// 	if (xs.dis >= 0.0)
// 		fprintf(stderr, "Error: dis is: %f\n", xs.dis);
// 	else
// 		printf("OK\n");

// 	ray = ray_new(point_new(0, 1, -5), tuple_normalize(vector_new(0, 0, 1)));
// 	xs = cylinder.local_interesct(ray, cylinder);
// 	if (xs.dis >= 0.0)
// 		fprintf(stderr, "Error: dis is: %f\n", xs.dis);
// 	else
// 		printf("OK\n");

// 	ray = ray_new(point_new(0, 1.5, -2), tuple_normalize(vector_new(0, 0, 1)));
// 	xs = cylinder.local_interesct(ray, cylinder);
// 	if (xs.dis <= 0.0)
// 		fprintf(stderr, "Error: dis is: %f\n", xs.dis);
// 	else
// 		printf("OK\n");

// }

void	test_capped_cylinder(void)
{
	t_shape cylinder;
	t_ray	ray;
	t_vec2	xs;

	cylinder = cylinder_default();
	cylinder.max = 2;
	cylinder.min = 1;
	cylinder.closed = true;

	printf("\nTest capped cylinder\n");
	// tuple_print(vector_new(0, -1, 0));
	// tuple_print(tuple_normalize(vector_new(0, -1, 0)));
	ray = ray_new(point_new(0, 3, 0), tuple_normalize(vector_new(0, -1, 0)));
	xs = cylinder.local_interesct(&cylinder, ray);
	if (xs.dis <= 0)
		fprintf(stderr, "Error1: discriminant is: %f\n", xs.dis);
	else
	{
		printf("OK\n");
	}

	ray = ray_new(point_new(0, 3, -2), tuple_normalize(vector_new(0, -1, 2)));
	xs = cylinder.local_interesct(&cylinder, ray);
	if (xs.dis <= 0)
		fprintf(stderr, "Error1: discriminant is: %f\n", xs.dis);
	else
	{
		printf("OK\n");
	}

	ray = ray_new(point_new(0, 4, -2), tuple_normalize(vector_new(0, -1, 1)));
	xs = cylinder.local_interesct(&cylinder, ray);
	if (xs.dis <= 0)
		fprintf(stderr, "Error1: discriminant is: %f\n", xs.dis);
	else
	{
		printf("OK\n");
	}

	ray = ray_new(point_new(0, 0, -2), tuple_normalize(vector_new(0, 1, 2)));
	xs = cylinder.local_interesct(&cylinder, ray);
	if (xs.dis <= 0)
		fprintf(stderr, "Error1: discriminant is: %f\n", xs.dis);
	else
	{
		printf("OK\n");
	}

	ray = ray_new(point_new(0, -1, -2), tuple_normalize(vector_new(0, 1, 1)));
	xs = cylinder.local_interesct(&cylinder, ray);
	if (xs.dis <= 0)
		fprintf(stderr, "Error1: discriminant is: %f\n", xs.dis);
	else
	{
		printf("OK\n");
	}
}
