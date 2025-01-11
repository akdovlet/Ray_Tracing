void	test_shading(void)
{
	t_world		world;
	t_ray		ray;
	t_crossing	cross;
	t_comps		comps;
	t_tuple		color;

	printf("\nShading test\n");
	world = default_world();
	// tuple_print(world.light.position);
	// tuple_print(world.light.intensity);
	// tuple_print(world.obj[0].coordinates);
	// tuple_print(world.obj[0].matter.color);
	// printf("object diffuse: %f, specular: %f, ambient: %f, shininess: %f\n", world.obj[0].matter.diffuse, world.obj[0].matter.specular,
	// 		world.obj[0].matter.ambient, world.obj[0].matter.shininess);
	// tuple_print(world.obj[0].coordinates);
	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	cross.t = 4;
	cross.obj = world.obj[0];
	comps = pre_compute(cross, ray);
	color = shade_hit(world, comps);
	if (tuple_cmp(color, color_new(0.380f, 0.475f, 0.285f)))
	{
		fprintf(stderr, "\tError:\texpected:\t");
		tuple_print(color_new(0.380f, 0.475f, 0.285f));
		fprintf(stderr, "\tgot:\t\t\t");
		tuple_print(color);
	}
	else
	{
		printf("\tOK\n");
	}


	ray = ray_new(point_new(0, 0, 0), vector_new(0, 0, 1));
	world.light = point_light(point_new(0, 0.25, 0), color_new(1, 1, 1));
	cross.obj = world.obj[1];
	cross.t = 0.5;
	comps = pre_compute(cross, ray);
	color = shade_hit(world, comps);
	t_tuple expected = color_new(0.90498, 0.90498, 0.90498);
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

void	test_is_shadowed(void)
{
	t_world	world;


	printf("\nTest is_shadowed\n");

	world = default_world();
	if (!is_shadowed(world, point_new(0, 10, 0)))
		printf("\tOK\n");
	else
	{
		fprintf(stderr, "\tError: should false\n");
	}
	

	if (is_shadowed(world, point_new(10, -10, 10)))
		printf("\tOK\n");
	else
	{
		fprintf(stderr, "\tError: should be true\n");
	}


	if (!is_shadowed(world, point_new(-20, 20, -20)))
		printf("\tOK\n");
	else
	{
		fprintf(stderr, "\tError: should be false\n");
	}


	if (!is_shadowed(world, point_new(-2, 2, -2)))
		printf("\tOK\n");
	else
	{
		fprintf(stderr, "\tError: should be false\n");
	}
}
