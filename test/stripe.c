void	test_stripe_at(void)
{
	t_pattern	pattern;
	t_shape		sph;
	t_tuple		color;
	t_tuple		expected;
	t_material	mat;
	t_tuple		eyev;
	t_tuple		normalv;
	t_light		light;

	printf("\n Stripe at test\n");

	sph = sphere_default();
	//expect white 1, 1, 1
	pattern = stripe_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
	expected = color_new(1, 1, 1);
	color = stripe_at(pattern, point_new(0, 0, 0));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}
	
	//expect white 1, 1, 1
	expected = color_new(1, 1, 1);
	color = stripe_at(pattern, point_new(0, 1, 0));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}

	//expect white 1, 1, 1
	expected = color_new(1, 1, 1);
	color = stripe_at(pattern, point_new(0, 2, 0));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}
	
/* --------------------------------------------------------------------------- */

	expected = color_new(1, 1, 1);
	color = stripe_at(pattern, point_new(0, 0, 0));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}
	
	expected = color_new(1, 1, 1);
	color = stripe_at(pattern, point_new(0, 0, 1));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}
	
	expected = color_new(1, 1, 1);
	color = stripe_at(pattern, point_new(0, 0, 2));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}

/* --------------------------------------------------------------------------- */

	//expect white 1, 1, 1
	expected = color_new(1, 1, 1);
	color = stripe_at(pattern, point_new(0, 0, 0));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}
	
	expected = color_new(1, 1, 1);
	color = stripe_at(pattern, point_new(0.9, 0, 0));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}
	
	expected = color_new(0, 0, 0);
	color = stripe_at(pattern, point_new(1, 0, 0));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}
	expected = color_new(0, 0, 0);
	color = stripe_at(pattern, point_new(-0.1, 0, 0));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}
	expected = color_new(0, 0, 0);
	color = stripe_at(pattern, point_new(-1, 0, 0));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}
	expected = color_new(1, 1, 1);
	color = stripe_at(pattern, point_new(-1.1, 0, 0));
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError: expected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}

/* --------------------------------------------------------------------------- */

	printf("\n Test stripe at with blinn-phong\n");

	mat = material();
	mat.pattern = stripe_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
	mat.ambient = 1;
	mat.diffuse = 0;
	mat.specular = 0;
	eyev = vector_new(0, 0, -1);
	normalv = vector_new(0, 0, -1);	
	light = point_light(point_new(0, 0, -10), color_new(1, 1, 1));
	color = blinn_phong(mat, light, point_new(0.9, 0, 0), eyev, normalv, false, sph);
	expected = color_new(1, 1, 1);
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t:");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}

	color = blinn_phong(mat, light, point_new(1.1, 0, 0), eyev, normalv, false, sph);
	expected = color_new(0, 0, 0);
	if (tuple_cmp(color, expected))
	{
		fprintf(stderr, "\tError:\texpected:\t");
		tuple_print(expected);
		fprintf(stderr, "\tgot:\t\t\t:");
		tuple_print(color);
	}
	else
		printf("\tOK\n");
}
