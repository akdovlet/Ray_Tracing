/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:03:35 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 18:52:14 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

#include "minirt.h"
#include "data_struct.h"

void			sphere_test(void);

t_vec2			intersect(t_ray ray, t_shape object);
t_intersection	intersection(t_shape obj, t_vec2 vec);
t_intersection	hit(t_intersection inter);

t_ray			ray_transform(t_ray ray, t_matrix m);
void			set_transform(t_shape *obj, t_matrix m);
v4			reflected_color(t_world *world, t_comps *comps, int depth);
v4			normal_at(t_shape obj, v4 world_point);
v4			reflect(v4 in, v4 normal);
t_material		material(void);
t_material		emissive_material(void);

t_world			default_world(void);
void			intersect_world(t_world *world, t_ray ray, t_junction *hits);
void			pre_compute(t_comps *new, t_crossing cross, t_ray ray, t_junction arr);
v4			color_at(t_world *world, t_ray ray, int depth);
t_matrix		view_transform(v4 from, v4 to, v4 up);
t_shape			sphere_default(void);

t_camera		camera_new(double hsize, double vsize, double fov);
void 			camera_update_transform(t_camera *cam, v4 from, v4 to, v4 up);

t_shape			plane_new(void);

t_shape	glass_sphere(void);
t_shape	cube_default(void);
t_vec2	cube_intersect(t_ray ray, t_shape shape);
v4	cube_normal_at(t_shape obj, v4 point);
t_vec2	sphere_intersect(t_ray ray, t_shape shape);
v4	sphere_normal_at(t_shape obj, v4 world_point);


unsigned int		new_id(void);


v4	refracted_color(t_world *world, t_comps *comps, int depth);
v4	refracted_ray(t_comps *comps);
double	schlick(t_comps comps);

t_shape	cylinder_default(void);

#endif
