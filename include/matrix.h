
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
t_matrix	shear(t_tuple s1, t_tuple s2);
t_matrix	scale(double x, double y, double z);
t_matrix	t_scale(t_tuple t);
t_matrix	translate(double x, double y, double z);
t_matrix	t_translate(t_tuple t);
double		cofactor(t_matrix m, size_t x, size_t y);
t_matrix	inverse(t_matrix m);

/*	matrix	*/
t_matrix	multiply_matrix(t_matrix a, t_matrix b);
t_matrix	compose(size_t operation_count, t_matrix* ops);

void		print_matrix(t_matrix m);
t_tuple		transform(t_matrix m, t_tuple t1);

//	turns rows into columns
t_matrix	matrix_transpose(t_matrix m);

int			matrix_cmp(t_matrix m1, t_matrix m2, int row, int col);

double		determinant(t_matrix m);

double		radians(double angle);

#endif
