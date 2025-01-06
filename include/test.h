/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:23:37 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/06 18:55:00 by akdovlet         ###   ########.fr       */
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
void		test_scene(t_img *img, t_mlx *mlx);
void		test_is_shadowed(void);

#endif
