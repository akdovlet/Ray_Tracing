/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:46 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/17 18:17:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

typedef struct s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}	t_projectile;

typedef struct s_env
{
	t_tuple	gravity;
	t_tuple	wind;
}	t_env;


t_tuple	tuple_new(float x, float y, float z, float w);
t_tuple	vector_new(float x, float y, float z);
t_tuple	point_new(float x, float y, float z);

int		float_equal(float a, float b);
int		tuple_cmp(t_tuple a, t_tuple b);
t_tuple	tuple_add(t_tuple a, t_tuple b);
t_tuple	tuple_substract(t_tuple a, t_tuple b);
t_tuple	tuple_negate(t_tuple a);
t_tuple	tuple_multiply(t_tuple a, float scalar);
t_tuple	tuple_divide(t_tuple a, float divisor);
float	tuple_magnitude(t_tuple a);
t_tuple	tuple_normalize(t_tuple a);
float	tuple_dot(t_tuple a, t_tuple b);
t_tuple	tuple_cross(t_tuple a, t_tuple b);


/*	simulation	*/

t_projectile	tick(t_env env, t_projectile proj);


/*	colors	*/

t_tuple	color_new(float red, float green, float blue);

#endif
