void	test_intersect_world(void)
{
	int			i;
	t_ray		ray;
	t_world		world;
	t_junction	hits;

	i = 0;
	world = default_world();
	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	intersect_world(world, ray, &hits);
	printf("hits count is: %d\n", hits.count);
	while (i < hits.count)
	{
		printf("hits[%d].t: %f\n", i, hits.cross[i].t);
		i++;
	}
}

void	intersection_test(void)
{
	printf("\nIntersection test\n");

	t_ray ray;
	t_shape sph;
	t_intersection inter;

	ray = ray_new(point_new(0, 0, -5), vector_new(0, 0, 1));
	sph = sphere(point_new(0, 0, 0), 1);
	inter.xs = intersect(ray, sph);
	if (inter.xs.x != 4 || inter.xs.y != 6)
		fprintf(stderr, "\tError: expected 4, 6; got: %f, %f\n", inter.xs.x, inter.xs.y);
	else
		printf("\tOk\n");
	inter = hit(inter);
	if (inter.t != 4)
		fprintf(stderr, "inter t is: %f, expected 4\n", inter.t);

	ray = ray_new(point_new(0, 1, -5), vector_new(0, 0, 1));
	sph = sphere(point_new(0, 0, 0), 1);
	inter.xs = intersect(ray, sph);
	if (inter.xs.x != 5 || inter.xs.y != 5)
		fprintf(stderr, "\tError: expected 4, 6; got: %f, %f\n", inter.xs.x, inter.xs.y);
	else
		printf("\tOk\n");
	inter = hit(inter);
	if (inter.t != 5)
		fprintf(stderr, "inter t is: %f, expected 5\n", inter.t);

	ray = ray_new(point_new(0, 2, -5), vector_new(0, 0, 1));
	sph = sphere(point_new(0, 0, 0), 1);
	inter.xs = intersect(ray, sph);
	if (inter.xs.dis >= 0)
		fprintf(stderr, "\tError: expected 0; got: %f", inter.xs.dis);
	else
		printf("\tOk\n");
	inter = hit(inter);
	if (inter.count != 0)
		fprintf(stderr, "inter count is: %d, expected 0\n", inter.count);

	ray = ray_new(point_new(0, 0, 0), vector_new(0, 0, 1));
	sph = sphere(point_new(0, 0, 0), 1);
	inter.xs = intersect(ray, sph);
	if (inter.xs.x != -1.0 || inter.xs.y != 1)
		fprintf(stderr, "\tError: expected -1, 1; got: %f, %f", inter.xs.x, inter.xs.y);
	else
		printf("\tOk\n");
	inter = hit(inter);
	if (inter.t != 1)
		fprintf(stderr, "inter t is: %f, expected 1\n", inter.t);


	ray = ray_new(point_new(0, 0, 5), vector_new(0, 0, 1));
	sph = sphere(point_new(0, 0, 0), 1);
	inter.xs = intersect(ray, sph);
	if (inter.xs.x != -6.0 || inter.xs.y != -4.0)
		fprintf(stderr, "\tError: expected -6, -4; got: %f, %f", inter.xs.x, inter.xs.y);
	else
		printf("\tOk\n");
	inter = hit(inter);
	if (inter.t != 0)
		fprintf(stderr, "inter t is: %f, expected 0\n", inter.t);
}
