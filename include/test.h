/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:23:37 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/14 14:34:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include "data_struct.h"

void		main_test();
void		determinant_test();
void		position_test(void);
void		transform_test();
void		object_transform_test(void);
void		draw_sphere(t_img *img, t_mlx *mlx);
void		normal_at_test(void);
void		transpose_test(void);
void		reflect_test(void);
void		test_light(void);
void		test_color();
void		intersection_test(void);
void		test_intersect_world(void);
void		test_pre_compute(void);
void		test_shading(void);
void		test_color_at(void);
void		test_view_transform(void);
void		test_camera(void);
void		test_ray_for_pixel(void);
void		test_render_world(t_img *img, t_mlx *mlx);
void		test_is_shadowed(void);
void		test_intersect_plane(void);
void		test_stripe_at(void);
void		test_reflection(void);
void		test_refraction(void);
void		test_negative_intersection(void);
void		test_shade_hit_refraction(void);

t_data		scene_single_sphere(void);
t_data		scene_default(void);
t_data		scene_watchful_eye(void);
t_data		scene_cube(void);
t_data		scene_cylinder(void);
t_data		scene_complex(void);
t_data		scene_standby(void);
t_data		scene_walled(void);
t_data		scene_inside_sphere(void);
t_data		scene_uv_sphere(void);
t_data		scene_uv_plane(void);
t_data		scene_cube_pattern(void);
t_data		scene_spherical_pattern(t_mlx *mlx);

void		test_cube(void);
void		test_normal_end_caps(void);
void		test_cube_normalat(void);
void		test_cylinder_intersect(void);
void		test_cylinder_normalat(void);
void		test_truncated_cylinder(void);
void		test_capped_cylinder(void);
void		test_cylinder_normal_at_caps(void);
void		test_cone_intersect(void);
void		test_triangle_normal(void);
void		test_triangle_intersect(void);
t_data		scene_triangle(void);
void		test_spherical_mapping(void);
void	test_atof(char *str);
void	test_parsing(char *str);
#endif
