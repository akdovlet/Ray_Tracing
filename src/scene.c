#include "minirt.h"
#include "tuple.h"
#include "light.h"

t_material init_floor_material(void)
{
    t_material  out;

    out = material();
	out.pattern = gradient_pattern(color_new(1, 0, 0), color_new(0, 0, 1));
	out.color = color_new(1, 0.2, 1);
	out.specular = 0;
	out.ambient = 0.1;
    return (out);
}

t_shape init_floor(t_material material)
{
	t_shape		floor;

    floor = plane_new();
	floor.transform = translate(1, 0, 3);
	floor.matter = material;
    return (floor);
}

t_shape init_left_wall(void)
{
	t_shape		left_wall;

    left_wall = plane_new();
	left_wall.transform = translate(0, 5, 10);
	left_wall.matter = material();
	left_wall.matter.color = color_new(1, 0.2, 1);
    return (left_wall);
}

t_shape init_middle_sphere(void)
{
	t_shape		middle_sph;

	middle_sph = sphere_default();
	// middle_sph.transform = translate(-0.5, 0, 0.5);
	middle_sph.coordinates = point_new(-0.5, 1, 0.5);
	middle_sph.matter = material();
	middle_sph.matter.pattern = stripe_pattern(color_new(1, 1, 1), color_new(0, 0, 0));
	middle_sph.matter.pattern.transform = scale(30, 0, 0);
	middle_sph.matter.color = color_new(0.1, 1, 0.5);
	middle_sph.matter.diffuse = 0.7;
	middle_sph.matter.specular = 0.3;

    return(middle_sph);
}

t_shape init_right_sphere(void)
{
	t_shape		right_sph;

	right_sph = sphere_default();
	right_sph.transform = multiply_matrix(translate(1.5, 0.5, -0.5), scale(0.5, 0.5, 0.5));
	right_sph.matter = material();
	right_sph.matter.color = color_new(0.5, 1, 0.1);
	right_sph.matter.diffuse = 0.7;
	right_sph.matter.specular = 0.3;
    return (right_sph);
}

t_shape init_left_sphere(void)
{
	t_shape		left_sph;

	left_sph = sphere_default();
	left_sph.transform = multiply_matrix(translate(-1.5, 0.33, -0.5), scale(0.33, 0.33, 0.33));
	left_sph.matter = material();
	left_sph.matter.color = color_new(1, 0.8, 0.1);
	left_sph.matter.diffuse = 0.7;
	left_sph.matter.specular = 0.3;
    return (left_sph);
}

void	scene(t_camera* camera, t_world* world)
{
    t_material floor_material = init_floor_material();

	world->light = point_light(point_new(-10, 3, -10), color_new(1, 1, 1));

	world->obj[0] = init_floor(floor_material);
	world->obj[1] = init_left_wall();
	world->obj[2] = init_middle_sphere();
	world->obj[3] = init_right_sphere();
	world->obj[4] = init_left_sphere();
	world->obj_count = 5;

	for (int i = 0; i < world->obj_count; i++)
		world->obj[i].transform = inverse(world->obj[i].transform);

	(*camera) = camera_new(WIDTH, HEIGHT, M_PI / 3);
	camera_update_transform(
		camera,
		point_new(0, 1.5, -5),
		point_new(0, 1, 0),
		vector_new(0, 1, 0));
}
