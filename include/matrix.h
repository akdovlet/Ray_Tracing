
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:12:26 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/31 16:07:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

#include "data_struct.h"

/*	tuple	*/

t_matrix	identity(void);
t_matrix	rotate_x(double angle);
t_matrix	rotate_y(double angle);
t_matrix	rotate_z(double angle);
t_matrix	shear(v4 s1, v4 s2);
t_matrix	scale(double x, double y, double z);
t_matrix	translate(double x, double y, double z);
double		cofactor(t_matrix m, size_t x, size_t y);
t_matrix	inverse(t_matrix m);

/*	matrix	*/
t_matrix	multiply_matrix(t_matrix a, t_matrix b);
t_matrix	compose(size_t operation_count, t_matrix* ops);
v4		transform(v4 t1, t_matrix m);

void		print_matrix(v4 m[4]);
v4		matrix_multiply_tuple(t_matrix m, v4 t1);

//	turns rows into columns
t_matrix	matrix_transpose(t_matrix m);

int			matrix_cmp(t_matrix m1, t_matrix m2, int row, int col);

double		determinant(t_matrix m);

double		radians(double angle);

#endif
