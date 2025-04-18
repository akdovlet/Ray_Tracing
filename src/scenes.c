/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:13:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/03 14:34:30 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "light.h"
#include "colors.h"

// t_data	scene_inside_sphere(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		floor;
// 	t_shape		wall;
// 	t_shape		wall2;
// 	t_shape		sky;
// 	t_shape		middle_sph;
// 	t_shape		right_sph;
// 	t_shape		left_sph;
// 	t_data		data;

// 	floor = plane_default();
// 	set_transform(&floor, translate(0, -5, 0));
// 	// floor.transform = translate(1, 0, 3);
// 	floor.matter = material();
// 	floor.matter.pattern = checkers_pattern(black(), red());
// 	// set_transform_pattern(&floor.matter.pattern, rotate_y(radians(30)));
// 	floor.matter.specular = 0.2;
// 	floor.matter.ambient = 0.7;
// 	// floor.matter.reflective = 0.5;

// 	wall = plane_default();
// 	set_transform(&wall, multiply_matrix(multiply_matrix(translate(0, 0, 20), rotate_x(radians(90))),
// 											rotate_z(radians(60))));
// 	wall.matter = material();
// 	wall.matter.pattern = checkers_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
// 	wall.matter.specular = 0;
// 	wall.matter.ambient = 0.7;


// 	wall2 = plane_default();
// 	set_transform(&wall2, multiply_matrix(multiply_matrix(translate(0, 0, -4), rotate_x(radians(90))),
// 											rotate_z(radians(120))));
// 	wall2.matter = material();
// 	wall2.matter.pattern = ring_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
// 	wall2.matter = glass_material();
// 	wall2.matter.reflective = 1;
// 	wall2.matter.diffuse = 0.2;
// 	wall2.matter.specular = 0.7;
// 	wall2.matter.shininess = 300;
// 	wall2.matter.ambient = 0.01;
// 	wall2.matter.refractive_index = 1.458;

// 	sky = plane_default();
// 	set_transform(&sky, translate(0, 10, 0));
// 	sky.matter = material();
// 	sky.matter.color = color_new(0, 0.957, 1);
// 	sky.matter.pattern = gradient_pattern(color_new(0, 0.957, 1), color_new(1, 1, 1));
// 	set_transform_pattern(&sky.matter.pattern, scale(2, 2, 4));

// 	middle_sph = sphere_default();
// 	// middle_sph.matter.pattern = ring_pattern(color_new(1, 0.2, 1), color_new(1, 1, 1));
// 	// set_transform(&middle_sph, translate(0, 0, 0));
// 	set_transform(&middle_sph, scale(10, 10, 10));
// 	// middle_sph.matter.pattern.transform = scale(, 0, 0);
// 	middle_sph.matter.reflective = 1;
// 	// middle_sph.matter.transparency = 1;
// 	middle_sph.matter.color = color_new(0.31, 0.027, 0.027);
// 	middle_sph.matter.diffuse = 0.3;
// 	middle_sph.matter.ambient = 0.3;
// 	middle_sph.matter.specular = 1.0;
// 	middle_sph.matter.shininess = 300;

// 	right_sph = sphere_default();
// 	set_transform(&right_sph, multiply_matrix(translate(0, 0, 5), scale(0.5, 0.5, 0.5)));
// 	right_sph.matter = material();
// 	// right_sph.matter.pattern = radial_pattern(color_new(1, 0, 0), color_new(0, 0, 1));
// 	// set_transform_pattern(&right_sph.matter.pattern, scale(0.2, 0.4, 0.1));
// 	right_sph.matter.color = color_new(0, 0, 0);
// 	right_sph.matter.diffuse = 0.3;
// 	right_sph.matter.specular = 0.3;
// 	right_sph.matter.reflective = 0.5;

// 	left_sph = sphere_default();
// 	set_transform(&left_sph, multiply_matrix(translate(-2, 0, 2), scale(1.5, 1.5, 1.5)));
// 	left_sph.matter = material();
// 	// left_sph.matter.pattern = ring_pattern(color_new(1, 0, 0), color_new(0, 0, 0));
// 	// set_transform_pattern(&left_sph.matter.pattern, scale(0.1, 0.1, 0.1));
// 	left_sph.matter.color = color_new(0, 0, 0.9);
// 	left_sph.matter.diffuse = 0.7;
// 	left_sph.matter.specular = 0.3;
// 	left_sph.matter.reflective = 0.2;


// 	world.light = point_light(point_new(-5, 10, -3), color_new(1, 1, 1));
// 	world.obj[0] = floor;
// 	world.obj[1] = middle_sph;
// 	world.obj[2] = left_sph;
// 	world.obj[3] = right_sph;
// 	world.obj_count = 3;
	// cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(0, 0, -3);
// 	cam.to =  point_new(-0.4, -0.5, 0);
// 	cam.up =  vector_new(0, 1, 0);
	// cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_single_sphere(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		sun;
// 	t_shape		sphere2;
// 	t_shape		cube;
// 	t_shape		cone;
// 	t_data		data;

// 	sun = sphere_default();
// 	set_transform(&sun, multiply_matrix(translate(0 , 2, 5), scale(3, 3, 3)));
// 	sun.matter = emissive_material();
// 	sun.matter.emission_power = 20;

// 	sphere2 = sphere_default();
// 	sphere2.matter.color = color_new(1, 0.1, 0.1);
// 	// sphere2.matter.roughness = 0.5;
// 	sphere2.matter.specular = 0.5;
// 	sphere2.matter.roughness = 0.1;
// 	sphere2.matter.metalic = 1;
// 	set_transform(&sphere2, translate(0, 0, 0));


	
// 	cone = cone_default();
// 	cone.min = -0.5;
// 	cone.max = 0.5;
// 	cone.matter.color = color_new(0.1, 0.9, 0.1);
// 	// cone.matter.roughness = 0.5;
// 	cone.matter.specular = 0.5;
// 	cone.matter.roughness = 0.1;
// 	cone.matter.metalic = 1;
// 	set_transform(&cone, translate(1, 0, 0));

	
// 	cube = cube_default();
// 	// cube.matter = emissive_material();
// 	cube.matter.color = color_new(0, 0, 1);
// 	cube.matter.pattern = checkers_pattern(white(), black());
// 	set_transform(&cube, multiply_matrix(translate(0, -3.1, 0), scale(2, 2.2, 2)));
// 	set_transform_pattern(&cube.matter.pattern, scale(0, 0.1, 0.1));
	
// 	world.light = point_light(point_new(-5, 8, 3), color_new(1, 1, 1));
// 	world.obj[0] = sun;
// 	world.obj[1] = cube;
// 	world.obj[2] = sphere2;
// 	world.obj_count = 3;

// 	cam = camera_new(WIDTH, HEIGHT, radians(90));
// 	cam.from =  point_new(0, -0.5, -3);
// 	cam.to =  point_new(0, 0, -1);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_walled(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		sun;
// 	t_shape		sphere2;
// 	t_shape		wall1;
// 	t_shape		wall2;
// 	t_shape		wall3;
// 	t_shape		wall4;
// 	t_shape		wall5;
// 	t_shape		wall6;
// 	t_shape		cube_light;
// 	t_data		data;

// 	sun = sphere_default();
// 	set_transform(&sun, multiply_matrix(translate(1 , 1, 0), scale(1, 1, 1)));
// 	sun.matter = emissive_material();
// 	sun.matter.emission_color = white();

// 	// sphere2 = triangle(point_new(0, 1, 0), point_new(-1, 0, 0), point_new(1, 0, 0));
// 	sphere2	= sphere_default();
// 	sphere2.matter.color = color_new(1, 0, 0.824);
// 	// set_transform(&sphere2, scale(0.5, 0.5, 0.5));
// 	sphere2.matter.roughness = 1;
// 	sphere2.matter.specular = 0.5;

// 	wall1 = cube_default();
// 	// wall1.matter = emissive_material();
// 	wall1.matter.color = white();
// 	wall1.matter.pattern = checkers_pattern(white(), black());
// 	set_transform(&wall1, multiply_matrix(translate(0, -1, 0), scale(2, 0.1, 2)));
// 	set_transform_pattern(&wall1.matter.pattern, scale(0.1, 0.1, 0.1));

// 	wall2 = cube_default();
// 	// wall2.matter = emissive_material();
// 	wall2.matter.color = white();
// 	set_transform(&wall2, multiply_matrix(multiply_matrix(translate(0, 0.5, -2), rotate_x(radians(90))),
// 						scale(2, 0.1, 1.5)));

// 	wall3 = cube_default();
// 	// wall3.matter = emissive_material();
// 	wall3.matter.color = blue();
// 	set_transform(&wall3, multiply_matrix((multiply_matrix(translate(-2, 0.5, 0), rotate_z(radians(90)))),
// 	scale(1.5, 0.1, 2)));
// 	// wall3.matter.roughness = 1;
// 	// wall3.matter.specular = 0.995;
	
// 	wall4 = cube_default();
// 	// wall4.matter = emissive_material();
// 	wall4.matter.color = red();
// 	set_transform(&wall4, multiply_matrix((multiply_matrix(translate(2, 0.5, 0), rotate_z(radians(90)))),
// 	scale(1.5, 0.1, 2)));
// 	// wall4.matter.roughness = 1;
// 	// wall4.matter.specular = 0.1;

// 	wall5 = cube_default();
// 	// wall5.matter = emissive_material();
// 	wall5.matter.color = green();
// 	set_transform(&wall5, multiply_matrix(translate(0, 2, 0), scale(2, 0.1, 2)));
// 	// wall5.matter.roughness = 1;
// 	// wall5.matter.specular = 0.995;

// 	wall6 = cube_default();
// 	// wall6.matter = emissive_material();
// 	wall6.matter.color = white();
// 	set_transform(&wall6, multiply_matrix(multiply_matrix(translate(0, 0.5, 2), rotate_x(radians(90))),
// 						scale(2, 0.1, 1.5)));
// 	// wall6.matter.roughness = 1;
// 	// wall6.matter.specular = 0.995;
	
// 	cube_light = cube_default();
// 	// cube_light.matter = emissive_material();
// 	cube_light.matter.color = white();
// 	cube_light.matter = emissive_material();
// 	set_transform(&cube_light, multiply_matrix(translate(0, 1.8, 0), scale(0.5, 0.01, 0.5)));

// 	world.light = point_light(point_new(-5, 8, 3), color_new(1, 1, 1));

// 	world.obj[0] = sphere2;
// 	world.obj[1] = wall1;
// 	world.obj[2] = wall2;
// 	world.obj[3] = wall3;
// 	world.obj[4] = wall4;
// 	world.obj[5] = wall5;
// 	world.obj[6] = cube_light;
// 	world.obj[7] = wall6;
// 	world.obj_count = 7;

// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(0, 0.3, 3);
// 	cam.to =  point_new(0, 0, -1);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_default(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		floor;
// 	t_shape		wall;
// 	t_shape		wall2;
// 	t_shape		sky;
// 	t_shape		middle_sph;
// 	t_shape		right_sph;
// 	t_shape		left_sph;
// 	t_data		data;

// 	floor = plane_default();
// 	set_transform(&floor, translate(0, -2, 0));
// 	// floor.transform = translate(1, 0, 3);
// 	floor.matter = material();
// 	floor.matter.pattern = checkers_pattern(black(), red());
// 	// set_transform_pattern(&floor.matter.pattern, rotate_y(radians(30)));
// 	floor.matter.specular = 0.2;
// 	floor.matter.ambient = 0.7;
// 	// floor.matter.reflective = 0.5;

// 	wall = plane_default();
// 	set_transform(&wall, multiply_matrix(multiply_matrix(translate(0, 0, 20), rotate_x(radians(90))),
// 											rotate_z(radians(60))));
// 	wall.matter = material();
// 	wall.matter.pattern = checkers_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
// 	wall.matter.specular = 0;
// 	wall.matter.ambient = 0.7;
// 	wall.matter.color = red();


// 	wall2 = plane_default();
// 	set_transform(&wall2, multiply_matrix(multiply_matrix(translate(0, 0, -4), rotate_x(radians(90))),
// 											rotate_z(radians(120))));
// 	wall2.matter = material();
// 	wall2.matter.pattern = ring_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
// 	wall2.matter = glass_material();
// 	wall2.matter.reflective = 1;
// 	wall2.matter.diffuse = 0.2;
// 	wall2.matter.specular = 0.7;
// 	wall2.matter.shininess = 300;
// 	wall2.matter.ambient = 0.01;
// 	wall2.matter.refractive_index = 1.458;

// 	sky = plane_default();
// 	set_transform(&sky, translate(0, 10, 0));
// 	sky.matter = material();
// 	sky.matter.color = color_new(1, 0.957, 1);
// 	sky.matter.pattern = gradient_pattern(color_new(0, 0.957, 1), color_new(1, 1, 1));
// 	set_transform_pattern(&sky.matter.pattern, scale(2, 2, 4));

// 	middle_sph = glass_sphere();
// 	// middle_sph.matter.pattern = ring_pattern(color_new(1, 0.2, 1), color_new(1, 1, 1));
// 	set_transform(&middle_sph, translate(1, 0.5, 0));
// 	// set_transform_pattern(&middle_sph.matter.pattern, scale(0.2, 0.1, 0.07));
// 	// middle_sph.matter.pattern.transform = scale(, 0, 0);
// 	middle_sph.matter.reflective = 1;
// 	middle_sph.matter.transparency = 1;
// 	middle_sph.matter.color = color_new(0.31, 0.027, 0.027);
// 	middle_sph.matter.diffuse = 0.3;
// 	middle_sph.matter.ambient = 0.3;
// 	middle_sph.matter.specular = 1.0;
// 	middle_sph.matter.shininess = 300;

// 	right_sph = sphere_default();
// 	set_transform(&right_sph, multiply_matrix(translate(0, 20, 5), scale(10, 10, 10)));
// 	// right_sph.matter.pattern = radial_pattern(color_new(1, 0, 0), color_new(0, 0, 1));
// 	// set_transform_pattern(&right_sph.matter.pattern, scale(0.2, 0.4, 0.1));
// 	right_sph.matter.color = color_new(0, 0, 0);
// 	right_sph.matter.diffuse = 0.3;
// 	right_sph.matter.specular = 0.3;
// 	right_sph.matter.reflective = 0.5;
// 	right_sph.matter.emission_power = 2.0;
// 	right_sph.matter.emission_color = color_new(0.8, 0.5, 0.2);
// 	right_sph.matter = emissive_material();
// 	right_sph.matter.emission_color = white();

// 	left_sph = sphere_default();
// 	set_transform(&left_sph, multiply_matrix(translate(-2, 0, 2), scale(1.5, 1.5, 1.5)));
// 	left_sph.matter = material();
// 	// left_sph.matter.pattern = ring_pattern(color_new(1, 0, 0), color_new(0, 0, 0));
// 	// set_transform_pattern(&left_sph.matter.pattern, scale(0.1, 0.1, 0.1));
// 	left_sph.matter.color = color_new(0, 0, 0.9);
// 	left_sph.matter.diffuse = 0.7;
// 	left_sph.matter.specular = 0.8;
// 	left_sph.matter.metalic = 0.5;
// 	left_sph.matter.roughness = 0.5;
// 	left_sph.matter.reflective = 0.2;


// 	world.light = point_light(point_new(-5, 10, -3), color_new(1, 1, 1));
// 	world.obj[0] = floor;
// 	world.obj[1] = wall;
// 	world.obj[2] = middle_sph;
// 	world.obj[3] = left_sph;
// 	world.obj[4] = right_sph;
// 	world.obj_count = 5;
// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(2, 0, -3);
// 	cam.to =  point_new(-0.4, -0.5, 0);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_watchful_eye(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		floor;
// 	t_shape		middle_sph;
// 	t_shape		right_sph;
// 	t_data		data;

// 	floor = plane_default();
// 	set_transform(&floor, translate(0, -1, 0));
// 	floor.matter.pattern = checkers_pattern(color_new(0.929, 0, 0), color_new(0, 0, 0));

// 	middle_sph = sphere_default();
// 	middle_sph.matter.color = color_new(0, 0, 0.1);
// 	middle_sph.matter.diffuse = 0.01;
// 	middle_sph.matter.specular = 0;
// 	middle_sph.matter.reflective = 1;

// 	right_sph = sphere_default();
// 	set_transform(&right_sph, multiply_matrix(translate(0, 2, 0), scale(0.5, 0.5, 0.5)));
// 	right_sph.matter = material();
// 	right_sph.matter.diffuse = 0.01;
// 	right_sph.matter.color = black();
// 	right_sph.matter.specular = 0;
// 	right_sph.matter.reflective = 1;


// 	world.light = point_light(point_new(2, 10, -5), color_new(1, 1, 1));
// 	world.obj[0] = floor;
// 	world.obj[1] = middle_sph;
// 	world.obj[2] = right_sph;

// 	world.obj_count = 3;
// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(0, 0.5, 0);
// 	cam.to =  point_new(0, 1, 0);
// 	cam.up =  vector_new(1, 0, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_cube(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		floor;
// 	t_shape		cube;
// 	t_data		data;

// 	floor = plane_default();
// 	set_transform(&floor, translate(0, -1, 0));
// 	floor.matter.pattern = checkers_pattern(black(), red());

// 	cube = cube_default();
// 	cube.matter = emissive_material();
// 	set_transform(&cube, multiply_matrix(translate(0, 2, 0), rotate_y(radians(40))));

// 	world.light = point_light(point_new(-5, 8, -3), color_new(1, 1, 1));
// 	world.obj[0] = floor;
// 	world.obj[1] = cube;
// 	world.obj_count = 2;
// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(0, 2, -5);
// 	cam.to =  point_new(0, 1, 0);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_cylinder(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		cylinder;
// 	t_shape		sun;
// 	t_shape		floor;
// 	t_data		data;


// 	cylinder = cylinder_default();
// 	cylinder.matter.color = red();
// 	// set_transform(&cylinder, rotate_x(90));
// 	// set_transform_pattern(&cylinder.matter.pattern, scale(0.2, 0.4, 0.1));
// 	// cylinder.matter = glass_material();
// 	// set_transform(&cylinder, scale(0.7, 0.7, 0.7));
// 	// cylinder.matter.reflective = 1;
// 	// cylinder.matter.refractive_index = 1.333;
// 	cylinder.min = -1;
// 	cylinder.max = 1;

// 	sun = sphere_default();
// 	sun.matter = emissive_material();
// 	sun.matter.emission_power = 20;
// 	set_transform(&sun, translate(0, 4, 5));
	
// 	floor = plane_default();
// 	set_transform(&floor, translate(0, -1, 0));
// 	// floor.transform = translate(1, 0, 3);
// 	floor.matter = material();
// 	floor.matter.pattern = checkers_pattern(black(), white());
// 	// set_transform_pattern(&floor.matter.pattern, rotate_y(radians(30)));
// 	floor.matter.specular = 0.2;
// 	floor.matter.ambient = 0.7;
// 	// floor.matter.transparency = 0.5;

// 	world.light = point_light(point_new(-5, 8, -3), color_new(1, 1, 1));
// 	world.obj[0] = cylinder;
// 	world.obj[1] = floor;
// 	world.obj[2] = sun;
// 	world.obj_count = 3;
// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(0, 2, -3);
// 	cam.to =  point_new(0, 0, 1);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_complex(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		cylinder;
// 	t_shape		cube;
// 	t_shape		sphere;
// 	t_shape		wall;
// 	t_shape		floor;
// 	t_data		data;

// 	cube = cube_default();
// 	cube.matter = emissive_material();
// 	// cube.matter = glass_material();
// 	// cube.matter.pattern = stripe_pattern(green(), blue());
// 	set_transform(&cube, translate(3, 0, -2));


// 	sphere = glass_sphere();
// 	// sphere.matter = emissive_material();
// 	set_transform(&sphere, multiply_matrix(translate(0, 2, 0), scale(1.5, 1.5, 1.5)));
// 	// sphere.matter.pattern = checkers_pattern(red(), black());
// 	// set_transform_pattern(&sphere.matter.pattern, scale(0.3, 0.3, 0.3));

// 	cylinder = cylinder_default();
// 	cylinder.matter = glass_material();
// 	cylinder.matter.color = black();
// 	set_transform(&cylinder, translate(0, 0, 0));
// 	// set_transform_pattern(&cylinder.matter.pattern, scale(0.2, 0.4, 0.1));
// 	// cylinder.matter = glass_material();
// 	// set_transform(&cylinder, scale(0.7, 0.7, 0.7));
// 	// cylinder.matter.reflective = 1;
// 	// cylinder.matter.refractive_index = 1.333;
// 	cylinder.min = -1;
// 	cylinder.max = 1;

// 	wall = plane_default();
// 	set_transform(&wall, multiply_matrix(translate(0, 0, 5), rotate_x(radians(90))));
// 	wall.matter.pattern = checkers_pattern(red(), black());

// 	floor = plane_default();
// 	set_transform(&floor, translate(0, -1, 0));
// 	floor.matter.pattern = checkers_pattern(black(), white());
// 	floor.matter.reflective = 0.1;

// 	world.light = point_light(point_new(-5, 8, -3), color_new(1, 1, 1));
// 	world.obj[0] = cylinder;
// 	world.obj[1] = floor;
// 	world.obj[2] = sphere;
// 	world.obj[3] = cube;
// 	world.obj[4] = wall;
// 	world.obj_count = 5;
// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(-7, 5, -7);
// 	cam.to =  point_new(0, 0, -1);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_standby(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		cylinder;
// 	t_shape		cube;
// 	t_shape		sphere;
// 	t_shape		wall;
// 	t_shape		floor;
// 	t_data		data;


// 	cube = cube_default();
// 	// cube.matter = glass_material();
// 	cube.matter.refractive_index = 1.333;
// 	// cube.matter.pattern = stripe_pattern(green(), blue());
// 	set_transform(&cube, translate(3, 0, 0));


// 	sphere = glass_sphere();
// 	set_transform(&sphere, scale(8, 8, 8));
// 	sphere.matter.reflective = 1;
// 	// sphere.matter.pattern = checkers_pattern(red(), black());
// 	// set_transform_pattern(&sphere.matter.pattern, scale(0.3, 0.3, 0.3));

// 	cylinder = cylinder_default();
// 	cylinder.matter.color = black();
// 	// set_transform(&cylinder, multiply_matrix(translate(0, -0.2, 0), rotate_z(radians(40))));
// 	// set_transform_pattern(&cylinder.matter.pattern, scale(0.2, 0.4, 0.1));
// 	// cylinder.matter = glass_material();
// 	// set_transform(&cylinder, scale(0.7, 0.7, 0.7));
// 	// cylinder.matter.reflective = 1;
// 	// cylinder.matter.refractive_index = 1.333;
// 	cylinder.min = -1;
// 	cylinder.max = 1;

// 	wall = plane_default();
// 	set_transform(&wall, multiply_matrix(translate(0, 0, 5), rotate_x(radians(90))));
// 	wall.matter.pattern = checkers_pattern(red(), black());

// 	floor = plane_default();
// 	set_transform(&floor, translate(0, 0, 0));
// 	floor.matter.pattern = checkers_pattern(black(), white());
// 	floor.matter.reflective = 0.1;

// 	world.light = point_light(point_new(0, 3, 3), color_new(1, 1, 1));
// 	world.obj[0] = cylinder;
// 	world.obj[1] = floor;
// 	world.obj[2] = sphere;
// 	world.obj[3] = cube;
// 	world.obj[4] = wall;
// 	world.obj_count = 3;
// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(0, 0.5, -5);
// 	cam.to =  point_new(0, 1, 0);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_triangle(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		tri;
// 	t_data		data;
// 	t_shape		floor;

// 	tri = triangle(point_new(1.5, 2, 1.3), point_new(1.4, -1.2, 0.12), point_new(-0.1, 0, -1.3));
// 	// set_transform(&tri, rotate_x(90));
// 	// cube.matter = glass_material();
// 	// cube.matter.pattern = stripe_pattern(green(), blue());
// 	tri.matter = emissive_material();
// 	floor = plane_default();
// 	set_transform(&floor, translate(0, -2, 0));

// 	world.light = point_light(point_new(0, 3, 3), color_new(1, 1, 1));
// 	world.obj[0] = tri;
// 	world.obj[1] = floor;
// 	world.obj_count = 2;
// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(0, 0.5, -5);
// 	cam.to =  point_new(0, 1, 0);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_uv_sphere(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		sphere;
// 	t_pattern	checkers;
// 	t_data		data;

// 	sphere = sphere_default();
// 	checkers = uv_checkers(10, 20, green(), white());
// 	sphere.matter.pattern = texture_map(&checkers, &spherical_map);

// 	world.light = point_light(point_new(-10, 10, -10), color_new(1, 1, 1));
// 	world.obj[0] = sphere;
// 	world.obj_count = 1;
// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(0, 0, -5);
// 	cam.to =  point_new(0, 0, 0);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_uv_plane(void)
// {
// 	t_world		world;
// 	t_camera	cam;
// 	t_shape		plane;
// 	t_shape		cyl;
// 	t_pattern	checkers;
// 	t_data		data;

// 	plane = plane_default();
// 	set_transform(&plane, translate(0, -1, 0));
// 	checkers = uv_checkers(2, 2, green(), white());
// 	plane.matter.pattern = texture_map(&checkers, &planar_map);

// 	cyl = cylinder_default();
// 	set_transform(&cyl, scale(1, 3.1415, 1));
// 	checkers = uv_checkers(10, 20, red(), black());
// 	cyl.matter.pattern = texture_map(&checkers, &cylindrical_map);
	
// 	world.light = point_light(point_new(-10, 10, -10), white());

// 	world.obj[0] = plane;
// 	world.obj[1] = cyl;
// 	world.obj_count = 2;

// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(0, 0, -5);
// 	cam.to =  point_new(0, 0, 0);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// t_data	scene_cube_pattern()
// {
// 	t_faces		left;
// 	t_faces		front;
// 	t_faces		right;
// 	t_faces		back;
// 	t_faces		up;
// 	t_faces		down;
// 	t_pattern	pat;
// 	t_shape		cube;
// 	t_world		world;
// 	t_data		data;
// 	t_camera	cam;

// 	left = uv_align_check(yellow(), cyan(), red(), blue(), brown());
// 	front = uv_align_check(cyan(), red(), yellow(), brown(), green());
// 	right = uv_align_check(red(), yellow(), purple(), green(), white());
// 	back = uv_align_check(green(), purple(), cyan(), white(), blue());
// 	up = uv_align_check(brown(), cyan(), purple(), red(), yellow());
// 	down = uv_align_check(purple(), brown(), green(), blue(), white());
// 	pat = cube_map(right, left, up, down, front, back);
	
// 	cube = cube_default();
// 	cube.matter.pattern = pat;

// 	world.light = point_light(point_new(-10, 10, -10), white());

// 	world.obj[0] = cube;
// 	world.obj_count = 1;

// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(0, 0, -5);
// 	cam.to =  point_new(0, 0, 0);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }

// void	print_pixel(t_img *img)
// {
// 	int	i;
// 	int	j;
// 	uint32_t	color;
	
// 	i = 0;
// 	while (i < img->img_height)
// 	{
// 		j = 0;
// 		while (j < img->img_width)
// 		{
// 			color = pixel_at(img, j, i);
// 			printf("color is: %u\n", color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// t_data	scene_spherical_pattern(t_mlx *mlx)
// {
// 	t_shape		sphere;
// 	t_shape		sun;
// 	t_shape		plane;
// 	t_world		world;
// 	t_data		data;
// 	t_camera	cam;
// 	t_img		map;
// 	t_img		height;

// 	sphere = sphere_default();
// 	map.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./xpm/earthmap.xpm", &map.img_width, &map.img_height);
// 	map.addr = mlx_get_data_addr(map.img_ptr, &map.bits_per_pixel, &map.line_length, &map.endian);
// 	sphere.matter.pattern = spherical_pattern(&map);

// 	height.img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./xpm/earthbump.xpm", &height.img_width, &height.img_height);
// 	height.addr = mlx_get_data_addr(height.img_ptr, &height.bits_per_pixel, &height.line_length, &height.endian);
// 	sphere.matter.pattern.height_map = height;
// 	// set_transform_pattern(&sphere.matter.pattern, scale(0.2, 0.2, 0.2));
// 	// sphere.matter.pattern.uv_mapping = spherical_map;
// 	// sphere.matter.pattern.exists = 1;
// 	// sphere.matter.pattern.transform = identity();
// 	// sphere.matter.pattern.pattern_at = color_at_texture;

// 	sun = sphere_default();
// 	set_transform(&sun, multiply_matrix(translate(0 , 2, 50), scale(20, 20, 20)));
// 	sun.matter = emissive_material();
// 	sun.matter.emission_power = 2;
// 	sun.matter.emission_color = white();
	
// 	plane = plane_default();
// 	set_transform(&plane, translate(0, -2, 1));
// 	// print_pixel(&)
// 	// plane.matter.pattern = planar_pattern(&map, &height);
	
// 	world.light = point_light(point_new(-10, 10, -10), white());
	

// 	world.obj[0] = sphere;
// 	world.obj[1] = sun;
// 	world.obj[2] = plane;
// 	world.obj_count = 2;

// 	cam = camera_new(WIDTH, HEIGHT, radians(70));
// 	cam.from =  point_new(3, 0, -2);
// 	cam.to =  point_new(0, 0, 0);
// 	cam.up =  vector_new(0, 1, 0);
// 	cam_update(&cam, cam.from, cam.to, cam.up);
// 	data.cam = cam;
// 	data.world = world;
// 	return (data);
// }
