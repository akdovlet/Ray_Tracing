/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:23:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/06 18:25:42 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include "data_struct.h"

t_tuple			tuple_new(float x, float y, float z, float w);
t_tuple			vector_new(float x, float y, float z);
t_tuple			point_new(float x, float y, float z);

int				float_equal(float a, float b);
int				tuple_cmp(t_tuple a, t_tuple b);
t_tuple			tuple_add(t_tuple a, t_tuple b);
t_tuple			tuple_substract(t_tuple a, t_tuple b);
t_tuple			tuple_negate(t_tuple a);
t_tuple			tuple_multiply(t_tuple a, float scalar);
t_tuple			tuple_divide(t_tuple a, float divisor);
float			tuple_magnitude(t_tuple a);
t_tuple			tuple_normalize(t_tuple a);
float			tuple_dot(t_tuple a, t_tuple b);
t_tuple			tuple_cross(t_tuple a, t_tuple b);
void			tuple_print(t_tuple t1);

t_tuple			color_new(float red, float green, float blue);
t_tuple			color_hadamard(t_tuple c1, t_tuple c2);
unsigned int	tuple_tocolor(t_tuple tcolor);

#endif
