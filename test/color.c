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
