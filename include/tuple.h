/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:23:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:18:08 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include "data_struct.h"

v4			tuple_new(double x, double y, double z, double w);
v4			vector_new(double x, double y, double z);
v4			point_new(double x, double y, double z);

// 0 = not equal; 1 = equal
int				float_equal(double a, double b);
int				tuple_equal(v4 a, v4 b);
v4			tuple_add(v4 a, v4 b);
v4			tuple_substract(v4 a, v4 b);
v4			tuple_negate(v4 a);
v4			tuple_multiply(v4 a, double scalar);
v4			tuple_divide(v4 a, double divisor);
double			tuple_magnitude(v4 a);
v4			v4_normalize(v4 a);
double			tuple_dot(v4 a, v4 b);
v4			tuple_cross(v4 a, v4 b);
void			tuple_print(v4 t1);

v4			color_new(double red, double green, double blue);
v4			color_hadamard(v4 c1, v4 c2);
unsigned int	tuple_tocolor(v4 tcolor);

#endif
