/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:58:03 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/09 13:02:14 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "data_struct.h"

t_pattern	stripe_pattern(t_tuple c1, t_tuple c2);
void		set_transform_pattern(t_pattern *pattern, t_matrix m);
t_tuple		pattern_at_shape(t_pattern *pattern, t_shape *shape, t_tuple world_point);
t_pattern	gradient_pattern(t_tuple c1, t_tuple c2);
t_pattern	ring_pattern(t_tuple c1, t_tuple c2);
t_pattern	checkers_pattern(t_tuple c1, t_tuple c2);
t_pattern	radial_pattern(t_tuple c1, t_tuple c2);
t_pattern	spherical_pattern(t_img *img);

t_vec2f		spherical_map(t_tuple point);
t_pattern	texture_map(t_pattern *pattern, t_vec2f (*f)(t_tuple));
t_pattern	uv_checkers(int width, int height, t_tuple c1, t_tuple c2);
t_vec2f		planar_map(t_tuple point);
t_vec2f		cylindrical_map(t_tuple p);
t_tuple		uv_pattern_at(t_pattern *t_map, t_tuple point);
t_faces		uv_align_check(t_tuple main, t_tuple ul, t_tuple ur, t_tuple bl, t_tuple br);
t_pattern	cube_map(t_faces right, t_faces left, t_faces up, t_faces down, t_faces front, t_faces back);

#endif
