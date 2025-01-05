/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:03:35 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/05 18:18:32 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

#include "minirt.h"
#include "data_struct.h"

t_object		sphere(t_tuple point, float radius);
void			sphere_test(void);

t_vec2			intersect(t_ray ray, t_object object);
t_intersection	intersection(t_object obj, t_vec2 vec);
t_intersection	hit(t_intersection inter);

t_ray			ray_transform(t_ray ray, t_matrix m);
void			set_transform(t_object *obj, t_matrix m);
t_tuple			normal_at(t_object obj, t_tuple world_point);
t_tuple			reflect(t_tuple in, t_tuple normal);
t_material		material(void);

t_world			default_world(void);
t_junction		intersect_world(t_world world, t_ray ray);
t_comps			pre_compute(t_crossing cross, t_ray ray);
t_tuple			color_at(t_world world, t_ray ray);
t_matrix		view_transform(t_tuple from, t_tuple to, t_tuple up);

t_camera		camera_new(float hsize, float vsize, float fov);

// struct s_vtable_shape {
// 	void (*intersection)(t_object*, t_ray*);
// };


/// IMPLEMENTATION


// void intersection_sphere(t_shape *d, t_ray* r)
// {
// 	t_sphere* s = d;
// 	return;
// }

// t_vtable_shape v_table_sphere = {
// 	.intersection = intersection_sphere,
// };


// void intersection(t_shape *s, t_ray* r)
// {
// 	v_table_shape[s->type].intersection(s, r);
// }

#endif
