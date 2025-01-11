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
	if (tuple_cmp(expected, result))
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
	if (tuple_cmp(expected, result))
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
	if (tuple_cmp(expected, result))
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
	if (tuple_cmp(expected, result))
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
	if (tuple_cmp(expected, result))
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

