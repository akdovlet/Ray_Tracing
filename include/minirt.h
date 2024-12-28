/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:46 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/28 19:56:33 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "X11/keysym.h"
# include "mlx.h"
# include "libft.h"

# define WIDTH 900
# define HEIGHT 550

# include "matrix.h"
# include "objects.h"
# include "mlx_utils.h"

typedef struct s_shear
{
	float	x;
	float	y;
	float	z;
}	t_shear;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_interesection
{
	float		t;
	int			count;
	t_object	object;
	t_vec2		vec;
}	t_intersection;


void		put_pixel(t_img *img, unsigned int color, t_tuple t1);

float		intersection(t_ray ray, t_sphere sphere, t_vec2 *vec);

void		ak_pixel_put(t_img *data, t_tuple t1, unsigned int color);

void		print_matrix(float m[4][4]);
t_tuple		matrix_multiply_tuple(t_matrix m, t_tuple t1);

//	turns rows into columns
void		matrix_transpose(float	**m);

int			matrix_cmp(t_matrix m1, t_matrix m2, int row, int col);

//	using printf prints every data point in a given array
void		matrix_print(float **m, int row, int col);

float		determinant(t_matrix m);

float		**matrix_inverse(float **m, int size);

float		radians(float angle);


/* ray */

t_ray		ray_new(t_tuple origin, t_tuple direction);
float		discriminant(t_ray ray, t_sphere sphere);
t_tuple		position(t_ray ray, float factor);

#endif
