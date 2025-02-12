/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:58:03 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 18:52:14 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "data_struct.h"

t_pattern	stripe_pattern(v4 c1, v4 c2);
void		set_transform_pattern(t_pattern *pattern, t_matrix m);
v4		pattern_at_shape(t_pattern pattern, t_shape shape, v4 world_point);
t_pattern	gradient_pattern(v4 c1, v4 c2);
t_pattern	ring_pattern(v4 c1, v4 c2);
t_pattern	checkers_pattern(v4 c1, v4 c2);
t_pattern	radial_pattern(v4 c1, v4 c2);

#endif
