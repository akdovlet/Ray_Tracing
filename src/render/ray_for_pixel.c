#include "minirt.h"
#include "graphics.h"
#include "tuple.h"
#include "objects.h"

static t_vec2f precompute_world(t_camera cam, t_vec2i pixel_position)
{
	t_vec2f	position;
	t_vec2f	camera_psize;
	t_vec2f	screen_center;

	screen_center = (t_vec2f){
		.x = cam.half_width,
		.y = cam.half_height,
	};
	position = (t_vec2f){
		.x = pixel_position.x,
		.y = pixel_position.y,
	};
	camera_psize = vec2f_value(cam.psize);
	position = vec2f_add(position, vec2f_value(0.5));
	position = vec2f_multiply(position, camera_psize);
	return (vec2f_substract(screen_center, position));
}

t_ray	ray_for_pixel(t_camera cam, t_vec2i pixel_position)
{
	t_vec2f	world;
	t_tuple	pixel;
	t_ray	ray;

	world = precompute_world(cam, pixel_position);
	pixel = matrix_multiply_tuple(cam.transform, point_new(world.x, world.y, -1));
	ray.origin = matrix_multiply_tuple(cam.transform, point_new(0, 0, 0));
	ray.direction = tuple_normalize(tuple_substract(pixel, ray.origin));
	return (ray);
}