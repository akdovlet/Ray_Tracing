/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:46 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/16 18:48:42 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINIRT_H
# define MINIRT_H

#include <stdio.h>
#include <math.h>

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

t_tuple	tuple_new(int x, int y, int z, int w);
t_tuple	vector_new(int x, int y, int z);
t_tuple	point_new(int x, int y, int z);
int		tuple_cmp(t_tuple a, t_tuple b);
int		float_equal(float a, float b);
t_tuple	tuple_add(t_tuple a, t_tuple b);
t_tuple	tuple_substract(t_tuple a, t_tuple b);
t_tuple	tuple_negate(t_tuple a);
t_tuple	tuple_multiply(t_tuple a, float scalar);
t_tuple	tuple_divide(t_tuple a, float divisor);
float	tuple_magnitude(t_tuple a);
t_tuple	tuple_normalize(t_tuple a);

#endif
