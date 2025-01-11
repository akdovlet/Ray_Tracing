void	test_camera(void)
{
	t_camera	cam;


	printf("\nCamera test\n");
	cam = camera_new(200, 125, M_PI / 2);
	// printf("camera hsize: %f, vsize: %f, fov: %f\n", cam.hsize, cam.vsize, cam.fov);
	// print_matrix(cam.transform.raw);
	if (float_equal(0.01, cam.psize))
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
	if (float_equal(0.01, cam.psize))
	{
		fprintf(stderr, "\tError: expected: 0.01, got: %f\n", cam.psize);
	}
	else
	{
		printf("\tOK\n");
	}
}