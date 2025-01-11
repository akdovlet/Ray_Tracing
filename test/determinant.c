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