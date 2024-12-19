/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/19 14:48:50 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
	t_tuple	p;
	t_tuple	v;
	t_tuple	new;
	t_env	env;
	t_projectile proj;

	p = point_new(4, -4, 3);
	v = vector_new(4, -4, 3);
	fprintf(stderr, "tuple_new tests:\n");
	fprintf(stderr, "p(x: %f, y: %f, z: %f, w: %f)\n", p.x, p.y, p.z, p.w);
	fprintf(stderr, "v(x: %f, y: %f, z: %f, w: %f)\n\n", v.x, v.y, v.z, v.w);

	fprintf(stderr, "float_equal test\n");
	fprintf(stderr, "float a: %f, float b: %f are equal if 0: %d\n\n", 4.2F, 4.1F, float_equal(4.2f, 4.1f));

	fprintf(stderr, "tuple_cmp tests:\n");
	fprintf(stderr, "tuple p and v are equal if 0: %d\n\n", tuple_cmp(p, v));

	new = tuple_add(p, v);
	fprintf(stderr, "tuple_add test\n");
	fprintf(stderr, "tuple p + v = tuple(%f, %f, %f, %f)\n\n", \
	new.x, new.y, new.z, new.w);

	t_tuple	p1 = point_new(3, 2, 1);
	t_tuple	p2 = point_new(5, 6, 7);
	new = tuple_substract(p1, p2);
	fprintf(stderr, "tuple_substract test\n");
	fprintf(stderr, "p1(x: %f, y: %f, z: %f, w: %f)\n", p1.x, p1.y, p1.z, p1.w);
	fprintf(stderr, "p2(x: %f, y: %f, z: %f, w: %f)\n\n", p2.x, p2.y, p2.z, p2.w);
	fprintf(stderr, "tuple p1 - p2 = tuple(%f, %f, %f, %f)\n\n", new.x, new.y, new.z, new.w);

	t_tuple	v1 = vector_new(5, 6, 7);
	new = tuple_substract(p1, v1);
	fprintf(stderr, "substracting a vector from a point\n");
	fprintf(stderr, "v1(x: %f, y: %f, z: %f, w: %f)\n", v1.x, v1.y, v1.z, v1.w);
	fprintf(stderr, "tuple p1 - v1 = tuple(%f, %f, %f, %f)\n", new.x, new.y, new.z, new.w);

	t_tuple	v2 = vector_new(3, 2, 1);
	new = tuple_substract(v2, v1);
	fprintf(stderr, "substracting a vector from a vector\n");
	fprintf(stderr, "v2(x: %f, y: %f, z: %f, w: %f)\n", v2.x, v2.y, v2.z, v2.w);
	fprintf(stderr, "tuple v1 - v2 = vector(%f, %f, %f, %f)\n\n", new.x, new.y, new.z, new.w);

	t_tuple	t1 = tuple_new(1, -2, 3, -4);
	new = tuple_negate(t1);
	fprintf(stderr, "Negating a tuple\n");
	fprintf(stderr, "t1(x: %f, y: %f, z: %f, w: %f)\n", t1.x, t1.y, t1.z, t1.w);
	fprintf(stderr, "negated tuple t1 = tuple(%f, %f, %f, %f)\n\n", new.x, new.y, new.z, new.w);

	new = tuple_multiply(t1, 3.5);
	fprintf(stderr, "tuple scalar test\n");
	fprintf(stderr, "scaled by 3.5 tuple t1 = tuple(%f, %f, %f, %f)\n", new.x, new.y, new.z, new.w);
	new = tuple_multiply(t1, 0.5);
	fprintf(stderr, "scaled by 0.5 tuple t1 = tuple(%f, %f, %f, %f)\n", new.x, new.y, new.z, new.w);
	new = tuple_divide(t1, 2);
	fprintf(stderr, "divided by 2 tuple t1 = tuple(%f, %f, %f, %f)\n\n", new.x, new.y, new.z, new.w);
	
	fprintf(stderr, "magnitude test\n");
	fprintf(stderr, "magnite is: %f\n\n", tuple_magnitude(vector_new(0, 1, 0)));
	fprintf(stderr, "magnite is: %f\n\n", tuple_magnitude(vector_new(1, 2, 3)));

	v2 = vector_new(1, 2, 3);
	new = tuple_normalize(v2);
	fprintf(stderr, "normalize test\n");
	fprintf(stderr, "normalized vector v2:1.2.3 is: %f, %f, %f, %f\n\n", new.x, new.y, new.z, new.w);
	
	fprintf(stderr, "dot factor test\n");
	fprintf(stderr, "v1(x: %f, y: %f, z: %f, w: %f)\n", v1.x, v1.y, v1.z, v1.w);
	fprintf(stderr, "v2(x: %f, y: %f, z: %f, w: %f)\n", v2.x, v2.y, v2.z, v2.w);
	fprintf(stderr, "dot factor of v1 and v2 is: %f\n\n", tuple_dot(v1, v2));

	v1 = vector_new(1, 2, 3);
	v2 = vector_new(2, 3, 4);
	fprintf(stderr, "v1(x: %f, y: %f, z: %f, w: %f)\n", v1.x, v1.y, v1.z, v1.w);
	fprintf(stderr, "v2(x: %f, y: %f, z: %f, w: %f)\n", v2.x, v2.y, v2.z, v2.w);
	new = tuple_cross(v1, v2);
	fprintf(stderr, "cross product test\n");
	fprintf(stderr, "cross product of v1 and v2 = %f, %f, %f, %f\n", new.x, new.y, new.z, new.w);
	new = tuple_cross(v2, v1);
	fprintf(stderr, "cross product of v2 and v1 = %f, %f, %f, %f\n\n", new.x, new.y, new.z, new.w);


	fprintf(stderr, "color test\n");	
	t_tuple	color;

	color = color_new(0.5, 0.4, 1.7);
	fprintf(stderr, "color is: x: %f, y: %f, z: %f, w: %f\n\n", color.x, color.y, color.z, color.w);
	
	t_tuple	c1 = color_new(0.9, 0.6, 0.75);
	t_tuple c2 = color_new(0.7, 0.1, 0.25);
	t_tuple	c_new = tuple_add(c1, c2);
	fprintf(stderr, "c1 is: x: %f, y: %f, z: %f, w: %f\n\n", c1.x, c1.y, c1.z, c1.w);
	fprintf(stderr, "c2 is: x: %f, y: %f, z: %f, w: %f\n\n", c2.x, c2.y, c2.z, c2.w);
	fprintf(stderr, "c1 + c2 is: x: %f, y: %f, z: %f, w: %f\n\n", c_new.x, c_new.y, c_new.z, c_new.w);

	c_new = tuple_substract(c1, c2);
	fprintf(stderr, "c1 - c2 is: x: %f, y: %f, z: %f, w: %f\n\n", c_new.x, c_new.y, c_new.z, c_new.w);
	
	t_tuple	c3 = color_new(0.2, 0.3, 0.4);
	fprintf(stderr, "c3 is: x: %f, y: %f, z: %f, w: %f\n\n", c2.x, c2.y, c2.z, c2.w);
	c_new = tuple_multiply(c3, 2);
	fprintf(stderr, "c3 * 2 is: x: %f, y: %f, z: %f, w: %f\n\n", c_new.x, c_new.y, c_new.z, c_new.w);
	
	c1 = color_new(1, 0.2, 0.4);
	c2 = color_new(0.9, 1, 0.1);
	c_new = color_hadamard(c1, c2);
	fprintf(stderr, "c1 * c2 is: x: %f, y: %f, z: %f, w: %f\n\n", c_new.x, c_new.y, c_new.z, c_new.w);
	
	t_img	img;
	t_mlx	mlx;

	init_mlx(&mlx, &img);
	mlx_key_hook(mlx.win_ptr, &key_manager, &mlx);

	fprintf(stderr, "Starting projectile simulation\n");

	proj.position = point_new(0, 0, 0),
	proj.velocity = tuple_multiply(tuple_normalize(vector_new(1, 1.8, 0)), 11.25);

	env.gravity = vector_new(0, -0.1, 0);
	env.wind = vector_new(-0.01, 0, 0);
	fprintf(stderr, "projectile position at start is: x: %f, y: %f, z: %f, w: %f\n", proj.position.x, proj.position.y, proj.position.z, proj.position.w);
	while(1)
	{
		proj = tick(env, proj);
		ak_mlx_pixel_put(&img, proj.position.x, HEIGHT - proj.position.y, 16711680);
		fprintf(stderr, "projectile position is: x: %f, y: %f, z: %f, w: %f\n", proj.position.x, proj.position.y, proj.position.z, proj.position.w);
		if (proj.position.y <= 0)
			break ;
		usleep(10 * 1000);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	}
	fprintf(stderr, "Finished simulation\n\n");

	float **mfour = matrix_four_by_four(v1, v2, c1, c2);
	for (int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			fprintf(stderr, " 4x4 matrix[%d][%d]: %f", i, j, mfour[i][j]);
		}
		fprintf(stderr, "\n");
	}

	float	**mthree = matrix_three_by_three(v1, v2, c1);
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			fprintf(stderr, " 3x3 matrix[%d][%d]: %f", i, j, mthree[i][j]);
		}
		fprintf(stderr, "\n");
	}
	float	**mtwo = matrix_two_by_two(v1, v2);
	for (int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			fprintf(stderr, " 2x2 matrix[%d][%d]: %f", i, j, mtwo[i][j]);
		}
		fprintf(stderr, "\n");
	}
	
	fprintf(stderr, "c3 is: x: %f, y: %f, z: %f, w: %f\n\n", c3.x, c3.y, c3.z, c3.w);
	fprintf(stderr, "c2 is: x: %f, y: %f, z: %f, w: %f\n\n", c2.x, c2.y, c2.z, c2.w);

	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
}
