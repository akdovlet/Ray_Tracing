void	test_ray_for_pixel(void)
{
	t_camera cam;
	t_ray	ray;
	t_ray	expected;

	printf("\nTest ray for pixel\n");
	cam = camera_new(201, 101, M_PI / 2.0f);
	ray = ray_for_pixel(cam, 100, 50);
	expected = ray_new(point_new(0, 0, 0), vector_new(0, 0, -1));
	if (tuple_cmp(ray.direction, expected.direction) || tuple_cmp(ray.origin, expected.origin))
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
	ray = ray_for_pixel(cam, 0, 0);
	expected = ray_new(point_new(0, 0, 0), vector_new(0.66519, 0.33259, -0.66851));
	if (tuple_cmp(ray.direction, expected.direction) || tuple_cmp(ray.origin, expected.origin))
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
	ray = ray_for_pixel(cam, 100, 50);
	expected = ray_new(point_new(0, 2, -5), vector_new(sqrt(2)/2, 0, -sqrt(2)/2));
	if (tuple_cmp(ray.direction, expected.direction) || tuple_cmp(ray.origin, expected.origin))
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
