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
