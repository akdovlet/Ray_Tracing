/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:03:35 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/30 12:44:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

#include "minirt.h"
#include "data_struct.h"


t_object		sphere(t_tuple point, float radius);
void			sphere_test(void);

float			intersect(t_ray ray, t_object object, t_vec2 *vec);
t_intersection	interesection(float t, t_object obj, t_vec2 vec, float dis);
float			hit(t_vec2 vec);
t_ray			ray_transform(t_ray ray, t_matrix m);
void			set_transform(t_object *obj, t_matrix m);

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
