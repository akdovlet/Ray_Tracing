/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:23:37 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/04 18:44:10 by akdovlet         ###   ########.fr       */
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

#endif
