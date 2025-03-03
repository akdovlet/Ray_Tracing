/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:03:35 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/03 16:11:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

#include "minirt.h"
#include "data_struct.h"

void			sphere_test(void);

t_vec2			intersect(t_shape *shape, t_ray ray);
t_intersection	intersection(t_shape obj, t_vec2 vec);
void			hit(t_intersection *hit, t_vec2 vec);

void			set_transform(t_shape *obj, t_matrix m);
t_tuple			reflected_color(t_world *world, t_comps *comps, int depth);
t_tuple			normal_at(t_shape *shape, t_tuple point);
t_tuple			reflect(t_tuple in, t_tuple normal);
t_material		material(void);
t_material		emissive_material(void);

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
t_material	glass_material(void);
t_shape	cube_default(void);
t_vec2	cube_intersect(t_shape *shape, t_ray ray);
t_tuple	cube_normal_at(t_shape *shape, t_tuple point);
t_vec2	sphere_intersect(t_shape *shape, t_ray ray);
t_tuple	sphere_normal_at(t_shape *shape, t_tuple point);


unsigned int		new_id(void);

void	intersect_caps(t_shape *cyl, t_ray *ray, t_vec2 *xs);

t_tuple	refracted_color(t_world *world, t_comps *comps, int depth);
t_tuple	refracted_ray(t_comps *comps);
double	schlick(t_comps *comps);

t_shape	cylinder_default(void);
t_vec2	cylinder_intersect(t_shape *shape, t_ray ray);
void	check_trunc(t_vec2 *vec, t_shape *shape, t_ray *ray);

t_shape	cone_default();

t_shape	triangle_default(void);
t_shape	triangle(t_tuple p1, t_tuple p2, t_tuple p3);

#endif
