/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:46 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/23 18:59:20 by akdovlet         ###   ########.fr       */
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

typedef	struct s_canvas
{
	t_tuple	color;
}	t_canvas;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

/*	matrix	*/

float	**matrix_init(int row, int column);
void	*matrix_free(float **matrix, int size);
float	**matrix_four_by_four(t_tuple t1, t_tuple t2, t_tuple t3, t_tuple t4);
float	**matrix_three_by_three(t_tuple t1, t_tuple t2, t_tuple t3);
float	**matrix_two_by_two(t_tuple t1, t_tuple t2);

float	**matrix_multiply(float **a, float **b);
t_tuple	matrix_multiply_tuple(float **a, t_tuple t1);

//	allocates and returns a 4x4 identity matrix
float	**matrix_identity();

//	turns rows into columns
void	matrix_transpose(float	**m);

int		matrix_cmp(float **m1, float **m2, int row, int col);

//	using printf prints every data point in a given array
void	matrix_print(float **m, int row, int col);

// calculates the determinant of a 2x2 matrix
float	matrix_determinant(float **m);
float	matrix_determinant_recursion(float **m, int size);

// divide and conquer, creates sub matrix and calculates its determinant
float	matrix_minor(float **m, int row, int col, int size);
float	matrix_cofactor(float **m, int row, int col, int size);

float	**matrix_inverse(float **m, int size);

float	**matrix_translation(t_tuple tuple);
float	**matrix_scaling(float x, float y, float z);

t_tuple	rotate_x(float angle, t_tuple point);


float	radians(float angle);

//	allocates and returns a copy of the given matrix with the given row
//	and column removed
float	**sub_matrix(float **m, int size, int row, int col);

/*	tuple	*/

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
void	tuple_print(t_tuple t1);

/*	simulation	*/

t_projectile	tick(t_env env, t_projectile proj);


/*	colors	*/

t_tuple	color_new(float red, float green, float blue);
t_tuple	color_hadamard(t_tuple c1, t_tuple c2);

/*	mlx	*/

int		init_mlx(t_mlx *mlx, t_img *img);
void	mlx_clear(t_mlx *mlx, t_img *img);
void	ak_mlx_pixel_put(t_img *data, float dx, float dy, unsigned int color);
int		key_manager(int keysym, t_mlx *mlx);

#endif
