/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:13:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/05 01:52:34 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"
#include "colors.h"

t_data	scene_single_sphere(void)
{
	t_world		world;
	t_camera	cam;
	t_shape		sphere;
	t_shape		sphere2;
	t_shape		plane;
	t_data		data;

	sphere = sphere_default();
	sphere2 = sphere_default();
	sphere2.matter.color = color_new(0.902, 0.094, 0.788);
	sphere.matter = emissive_material();
	sphere.matter.emission_power = 200;
	// sphere2.matter.reflective = 1;
	set_transform(&sphere, multiply_matrix(translate(5, 0, -25), scale(10, 10, 10)));
	set_transform(&sphere2, translate(-1, 0, 0));
	plane = plane_new();
	plane.matter.pattern = checkers_pattern(white(), black());
	set_transform(&plane, translate(0, -1, 0));
	
	world.light = point_light(point_new(-5, 8, 3), color_new(1, 1, 1));
	world.obj[0] = sphere;
	world.obj[1] = plane;
	world.obj[2] = sphere2;
	world.obj_count = 3;

	cam = camera_new(WIDTH, HEIGHT, radians(70));
	cam.from =  point_new(0, 0, 3);
	cam.to =  point_new(0, 0, -1);
	cam.up =  vector_new(0, 1, 0);
	camera_update_transform(&cam, cam.from, cam.to, cam.up);
	data.cam = cam;
	data.world = world;
	return (data);
}

t_data	scene_default(void)
{
	t_world		world;
	t_camera	cam;
	t_shape		floor;
	t_shape		wall;
	t_shape		wall2;
	t_shape		sky;
	t_shape		middle_sph;
	t_shape		right_sph;
	t_shape		left_sph;
	t_data		data;

	floor = plane_new();
	set_transform(&floor, translate(0, -2, 0));
	// floor.transform = translate(1, 0, 3);
	floor.matter = material();
	floor.matter.pattern = checkers_pattern(black(), red());
	// set_transform_pattern(&floor.matter.pattern, rotate_y(radians(30)));
	floor.matter.specular = 0.2;
	floor.matter.ambient = 0.7;
	// floor.matter.reflective = 0.5;

	wall = plane_new();
	set_transform(&wall, multiply_matrix(multiply_matrix(translate(0, 0, 20), rotate_x(radians(90))),
											rotate_z(radians(60))));
	wall.matter = material();
	wall.matter.pattern = checkers_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
	wall.matter.specular = 0;
	wall.matter.ambient = 0.7;


	wall2 = plane_new();
	set_transform(&wall2, multiply_matrix(multiply_matrix(translate(0, 0, -4), rotate_x(radians(90))),
											rotate_z(radians(120))));
	wall2.matter = material();
	wall2.matter.pattern = ring_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
	wall2.matter = glass_material();
	wall2.matter.reflective = 1;
	wall2.matter.diffuse = 0.2;
	wall2.matter.specular = 0.7;
	wall2.matter.shininess = 300;
	wall2.matter.ambient = 0.01;
	wall2.matter.refractive_index = 1.458;

	sky = plane_new();
	set_transform(&sky, translate(0, 10, 0));
	sky.matter = material();
	sky.matter.color = color_new(0, 0.957, 1);
	sky.matter.pattern = gradient_pattern(color_new(0, 0.957, 1), color_new(1, 1, 1));
	set_transform_pattern(&sky.matter.pattern, scale(2, 2, 4));

	middle_sph = glass_sphere();
	// middle_sph.matter.pattern = ring_pattern(color_new(1, 0.2, 1), color_new(1, 1, 1));
	set_transform(&middle_sph, translate(1, 0.5, 0));
	// set_transform_pattern(&middle_sph.matter.pattern, scale(0.2, 0.1, 0.07));
	// middle_sph.matter.pattern.transform = scale(, 0, 0);
	middle_sph.matter.reflective = 1;
	middle_sph.matter.transparency = 1;
	middle_sph.matter.color = color_new(0.31, 0.027, 0.027);
	middle_sph.matter.diffuse = 0.3;
	middle_sph.matter.ambient = 0.3;
	middle_sph.matter.specular = 1.0;
	middle_sph.matter.shininess = 300;

	right_sph = sphere_default();
	set_transform(&right_sph, multiply_matrix(translate(0, 0, 5), scale(0.5, 0.5, 0.5)));
	right_sph.matter = material();
	// right_sph.matter.pattern = radial_pattern(color_new(1, 0, 0), color_new(0, 0, 1));
	// set_transform_pattern(&right_sph.matter.pattern, scale(0.2, 0.4, 0.1));
	right_sph.matter.color = color_new(0, 0, 0);
	right_sph.matter.diffuse = 0.3;
	right_sph.matter.specular = 0.3;
	right_sph.matter.reflective = 0.5;

	left_sph = sphere_default();
	set_transform(&left_sph, multiply_matrix(translate(-2, 0, 2), scale(1.5, 1.5, 1.5)));
	left_sph.matter = material();
	// left_sph.matter.pattern = ring_pattern(color_new(1, 0, 0), color_new(0, 0, 0));
	// set_transform_pattern(&left_sph.matter.pattern, scale(0.1, 0.1, 0.1));
	left_sph.matter.color = color_new(0, 0, 0.9);
	left_sph.matter.diffuse = 0.7;
	left_sph.matter.specular = 0.3;
	left_sph.matter.reflective = 0.2;


	world.light = point_light(point_new(-5, 10, -3), color_new(1, 1, 1));
	world.obj[0] = floor;
	world.obj[1] = wall;
	world.obj[5] = wall2;
	world.obj[2] = middle_sph;
	world.obj[3] = left_sph;
	world.obj[5] = right_sph;
	world.obj_count = 4;
	cam = camera_new(WIDTH, HEIGHT, radians(70));
	cam.from =  point_new(0, 0, -3);
	cam.to =  point_new(-0.4, -0.5, 0);
	cam.up =  vector_new(0, 1, 0);
	camera_update_transform(&cam, cam.from, cam.to, cam.up);
	data.cam = cam;
	data.world = world;
	return (data);
}

t_data	scene_watchful_eye(void)
{
	t_world		world;
	t_camera	cam;
	t_shape		floor;
	t_shape		middle_sph;
	t_shape		right_sph;
	t_data		data;

	floor = plane_new();
	set_transform(&floor, translate(0, -1, 0));
	floor.matter.pattern = checkers_pattern(color_new(0.929, 0, 0), color_new(0, 0, 0));

	middle_sph = sphere_default();
	middle_sph.matter.color = color_new(0, 0, 0.1);
	middle_sph.matter.diffuse = 0.01;
	middle_sph.matter.specular = 0;
	middle_sph.matter.reflective = 1;

	right_sph = sphere_default();
	set_transform(&right_sph, multiply_matrix(translate(0, 2, 0), scale(0.5, 0.5, 0.5)));
	right_sph.matter = material();
	right_sph.matter.diffuse = 0.01;
	right_sph.matter.color = black();
	right_sph.matter.specular = 0;
	right_sph.matter.reflective = 1;


	world.light = point_light(point_new(2, 10, -5), color_new(1, 1, 1));
	world.obj[0] = floor;
	world.obj[1] = middle_sph;
	world.obj[2] = right_sph;

	world.obj_count = 3;
	cam = camera_new(WIDTH, HEIGHT, radians(70));
	cam.from =  point_new(0, 0.5, 0);
	cam.to =  point_new(0, 1, 0);
	cam.up =  vector_new(1, 0, 0);
	camera_update_transform(&cam, cam.from, cam.to, cam.up);
	data.cam = cam;
	data.world = world;
	return (data);
}

t_data	scene_cube(void)
{
	t_world		world;
	t_camera	cam;
	t_shape		floor;
	t_shape		cube;
	t_data		data;

	floor = plane_new();
	set_transform(&floor, translate(0, -1, 0));
	floor.matter.pattern = checkers_pattern(black(), red());

	cube = cube_default();
	set_transform(&cube, multiply_matrix(translate(0, 0, 0), rotate_y(radians(10))));

	cube.matter = glass_material();
	cube.matter.color = color_new(0.1, 0.1, 0.1);
	cube.matter.refractive_index = 1.333;

	world.light = point_light(point_new(-5, 8, -3), color_new(1, 1, 1));
	world.obj[0] = floor;
	world.obj[1] = cube;
	world.obj_count = 2;
	cam = camera_new(WIDTH, HEIGHT, radians(70));
	cam.from =  point_new(2, 1, -4);
	cam.to =  point_new(0, -1, -1);
	cam.up =  vector_new(0, 1, 0);
	camera_update_transform(&cam, cam.from, cam.to, cam.up);
	data.cam = cam;
	data.world = world;
	return (data);
}

t_data	scene_cylinder(void)
{
	t_world		world;
	t_camera	cam;
	t_shape		cylinder;
	t_shape		floor;
	t_data		data;


	cylinder = cylinder_default();
	cylinder.matter.reflective = 0.5;
	cylinder.matter.color = red();
	// set_transform(&cylinder, multiply_matrix(translate(0, -0.2, 0), rotate_z(radians(40))));
	// set_transform_pattern(&cylinder.matter.pattern, scale(0.2, 0.4, 0.1));
	// cylinder.matter = glass_material();
	// set_transform(&cylinder, scale(0.7, 0.7, 0.7));
	// cylinder.matter.reflective = 1;
	// cylinder.matter.refractive_index = 1.333;
	cylinder.min = -1;
	cylinder.max = 1;

	floor = plane_new();
	set_transform(&floor, translate(0, -1, 0));
	// floor.transform = translate(1, 0, 3);
	floor.matter = material();
	floor.matter.pattern = checkers_pattern(black(), white());
	// set_transform_pattern(&floor.matter.pattern, rotate_y(radians(30)));
	floor.matter.specular = 0.2;
	floor.matter.ambient = 0.7;
	// floor.matter.transparency = 0.5;

	world.light = point_light(point_new(-5, 8, -3), color_new(1, 1, 1));
	world.obj[0] = cylinder;
	world.obj[1] = floor;
	world.obj_count = 2;
	cam = camera_new(WIDTH, HEIGHT, radians(70));
	cam.from =  point_new(0, 2, -3.5);
	cam.to =  point_new(0, -1, 0);
	cam.up =  vector_new(0, 1, 0);
	camera_update_transform(&cam, cam.from, cam.to, cam.up);
	data.cam = cam;
	data.world = world;
	return (data);
}

t_data	scene_complex(void)
{
	t_world		world;
	t_camera	cam;
	t_shape		cylinder;
	t_shape		cube;
	t_shape		sphere;
	t_shape		wall;
	t_shape		floor;
	t_data		data;


	cube = cube_default();
	// cube.matter = glass_material();
	cube.matter.refractive_index = 1.333;
	// cube.matter.pattern = stripe_pattern(green(), blue());
	set_transform(&cube, translate(3, 0, 0));


	sphere = glass_sphere();
	set_transform(&sphere, multiply_matrix(translate(0, 2, 0), scale(1.5, 1.5, 1.5)));
	// sphere.matter.pattern = checkers_pattern(red(), black());
	// set_transform_pattern(&sphere.matter.pattern, scale(0.3, 0.3, 0.3));

	cylinder = cylinder_default();
	cylinder.matter = glass_material();
	cylinder.matter.color = black();
	// set_transform(&cylinder, multiply_matrix(translate(0, -0.2, 0), rotate_z(radians(40))));
	// set_transform_pattern(&cylinder.matter.pattern, scale(0.2, 0.4, 0.1));
	// cylinder.matter = glass_material();
	// set_transform(&cylinder, scale(0.7, 0.7, 0.7));
	// cylinder.matter.reflective = 1;
	// cylinder.matter.refractive_index = 1.333;
	cylinder.min = -1;
	cylinder.max = 1;

	wall = plane_new();
	set_transform(&wall, multiply_matrix(translate(0, 0, 5), rotate_x(radians(90))));
	wall.matter.pattern = checkers_pattern(red(), black());

	floor = plane_new();
	set_transform(&floor, translate(0, -1, 0));
	floor.matter.pattern = checkers_pattern(black(), white());
	floor.matter.reflective = 0.1;

	world.light = point_light(point_new(-5, 8, -3), color_new(1, 1, 1));
	world.obj[0] = cylinder;
	world.obj[1] = floor;
	world.obj[2] = sphere;
	world.obj[3] = cube;
	world.obj[4] = wall;
	world.obj_count = 5;
	cam = camera_new(WIDTH, HEIGHT, radians(70));
	cam.from =  point_new(0, 0.5, -5);
	cam.to =  point_new(0, 0, 0);
	cam.up =  vector_new(0, 1, 0);
	camera_update_transform(&cam, cam.from, cam.to, cam.up);
	data.cam = cam;
	data.world = world;
	return (data);
}

t_data	scene_standby(void)
{
	t_world		world;
	t_camera	cam;
	t_shape		cylinder;
	t_shape		cube;
	t_shape		sphere;
	t_shape		wall;
	t_shape		floor;
	t_data		data;


	cube = cube_default();
	// cube.matter = glass_material();
	cube.matter.refractive_index = 1.333;
	// cube.matter.pattern = stripe_pattern(green(), blue());
	set_transform(&cube, translate(3, 0, 0));


	sphere = glass_sphere();
	set_transform(&sphere, scale(8, 8, 8));
	sphere.matter.reflective = 1;
	// sphere.matter.pattern = checkers_pattern(red(), black());
	// set_transform_pattern(&sphere.matter.pattern, scale(0.3, 0.3, 0.3));

	cylinder = cylinder_default();
	cylinder.matter.color = black();
	// set_transform(&cylinder, multiply_matrix(translate(0, -0.2, 0), rotate_z(radians(40))));
	// set_transform_pattern(&cylinder.matter.pattern, scale(0.2, 0.4, 0.1));
	// cylinder.matter = glass_material();
	// set_transform(&cylinder, scale(0.7, 0.7, 0.7));
	// cylinder.matter.reflective = 1;
	// cylinder.matter.refractive_index = 1.333;
	cylinder.min = -1;
	cylinder.max = 1;

	wall = plane_new();
	set_transform(&wall, multiply_matrix(translate(0, 0, 5), rotate_x(radians(90))));
	wall.matter.pattern = checkers_pattern(red(), black());

	floor = plane_new();
	set_transform(&floor, translate(0, 0, 0));
	floor.matter.pattern = checkers_pattern(black(), white());
	floor.matter.reflective = 0.1;

	world.light = point_light(point_new(0, 3, 3), color_new(1, 1, 1));
	world.obj[0] = cylinder;
	world.obj[1] = floor;
	world.obj[2] = sphere;
	world.obj[3] = cube;
	world.obj[4] = wall;
	world.obj_count = 3;
	cam = camera_new(WIDTH, HEIGHT, radians(70));
	cam.from =  point_new(0, 0.5, -5);
	cam.to =  point_new(0, 1, 0);
	cam.up =  vector_new(0, 1, 0);
	camera_update_transform(&cam, cam.from, cam.to, cam.up);
	data.cam = cam;
	data.world = world;
	return (data);
}
