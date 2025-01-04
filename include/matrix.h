
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
t_matrix	rotate_x(float angle);
t_matrix	rotate_y(float angle);
t_matrix	rotate_z(float angle);
t_matrix	shear(t_tuple s1, t_tuple s2);
t_matrix	scale(float x, float y, float z);
t_matrix	translate(float x, float y, float z);
float		cofactor(t_matrix m, size_t x, size_t y);
t_matrix	inverse(t_matrix m);

/*	matrix	*/
t_matrix	multiply_matrix(t_matrix a, t_matrix b);
t_matrix	compose(size_t operation_count, t_matrix* ops);
t_tuple		transform(t_tuple t1, t_matrix m);

void		print_matrix(float m[4][4]);
t_tuple		matrix_multiply_tuple(t_matrix m, t_tuple t1);

//	turns rows into columns
t_matrix	matrix_transpose(t_matrix m);

int			matrix_cmp(t_matrix m1, t_matrix m2, int row, int col);

float		determinant(t_matrix m);

float		radians(float angle);

#endif
