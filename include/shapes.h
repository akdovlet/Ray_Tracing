/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:03:35 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/01 14:53:32 by akdovlet         ###   ########.fr       */
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
t_tuple			reflected_color(t_world *world, t_comps *comps, int depth);
t_tuple			normal_at(t_shape obj, t_tuple world_point);
t_tuple			reflect(t_tuple in, t_tuple normal);
t_material		material(void);

t_world			default_world(void);
void			intersect_world(t_world *world, t_ray ray, t_junction *hits);
void			pre_compute(t_comps *new, t_crossing cross, t_ray ray, t_junction arr);
t_tuple			color_at(t_world *world, t_ray ray, int depth);
t_matrix		view_transform(t_tuple from, t_tuple to, t_tuple up);
t_shape			sphere_default(void);

t_camera		camera_new(double hsize, double vsize, double fov);
void 			camera_update_transform(t_camera *cam, t_tuple from, t_tuple to, t_tuple up);

t_shape			plane_new(void);

t_shape	glass_sphere(void);
t_shape	cube_default(void);
t_vec2	cube_intersect(t_ray ray, t_shape shape);
t_tuple	cube_normal_at(t_shape obj, t_tuple point);
t_vec2	sphere_intersect(t_ray ray, t_shape shape);
t_tuple	sphere_normal_at(t_shape obj, t_tuple world_point);


unsigned int		new_id(void);


t_tuple	refracted_color(t_world *world, t_comps *comps, int depth);
double	schlick(t_comps comps);

t_shape	cylinder_default(void);

#endif
