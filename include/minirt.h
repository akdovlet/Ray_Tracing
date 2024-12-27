/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:46 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/27 19:33:10 by akdovlet         ###   ########.fr       */
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

typedef union u_matrix t_matrix;

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct s_vec3 
{
	int x;	
	int y;	
	int z;	
} t_vec3;

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

typedef struct s_sphere
{
	t_tuple	coordinates;
	float	radius;
}	t_sphere;

typedef	union u_vec
{
	t_tuple	t1;
	float	v[4];
}	t_vec;

struct s_matrix {
	t_tuple r1;
	t_tuple r2;
	t_tuple r3;
	t_tuple r4;
};

union u_matrix
{
	struct
	{
		t_tuple r1;
		t_tuple r2;
		t_tuple r3;
		t_tuple r4;	
	};
	float	raw[4][4];
} __attribute__((__transparent_union__));

typedef struct s_shear
{
	float	x;
	float	y;
	float	z;
}	t_shear;

typedef struct s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}	t_proj;

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

typedef struct s_ray
{
	t_tuple origin;
	t_tuple	direction;
}	t_ray;

void		put_pixel(t_img *img, unsigned int color, t_tuple t1);
void		main_test();
void		inverse_test();
void		determinant_test();
void		position_test(void);

t_matrix	identity(void);
t_matrix	rotate_x(float angle);
t_matrix	rotate_y(float angle);
t_matrix	rotate_z(float angle);
t_matrix	shear(t_shear s1, t_shear s2);
t_matrix	scale(t_tuple t1);
t_matrix	translate(t_tuple t1);
float		cofactor(t_matrix m, size_t x, size_t y);
int			inverse(t_matrix m, t_matrix *m2);
float		intersection(t_ray ray, t_sphere sphere, t_vec2 *vec);

/*	matrix	*/
t_matrix	multiply_matrix(t_matrix a, t_matrix b);
t_matrix	compose(size_t operation_count, t_matrix* ops);
t_tuple		transform(t_tuple t1, t_matrix m);

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

/*	tuple	*/

t_tuple		tuple_new(float x, float y, float z, float w);
t_tuple		vector_new(float x, float y, float z);
t_tuple		point_new(float x, float y, float z);

int			float_equal(float a, float b);
int			tuple_cmp(t_tuple a, t_tuple b);
t_tuple		tuple_add(t_tuple a, t_tuple b);
t_tuple		tuple_substract(t_tuple a, t_tuple b);
t_tuple		tuple_negate(t_tuple a);
t_tuple		tuple_multiply(t_tuple a, float scalar);
t_tuple		tuple_divide(t_tuple a, float divisor);
float		tuple_magnitude(t_tuple a);
t_tuple		tuple_normalize(t_tuple a);
float		tuple_dot(t_tuple a, t_tuple b);
t_tuple		tuple_cross(t_tuple a, t_tuple b);
void		tuple_print(t_tuple t1);
/*	simulation	*/

t_proj		tick(t_env env, t_proj proj);

/*	colors	*/

t_tuple		color_new(float red, float green, float blue);
t_tuple		color_hadamard(t_tuple c1, t_tuple c2);

/*	mlx	*/

int			init_mlx(t_mlx *mlx, t_img *img);
void		mlx_clear(t_mlx *mlx, t_img *img);
void		ak_mlx_pixel_put(t_img *data, float dx, float dy, unsigned int color);
int			key_manager(int keysym, t_mlx *mlx);

/* ray */

t_ray		ray_new(t_tuple origin, t_tuple direction);
float		discriminant(t_ray ray, t_sphere sphere);
t_tuple		position(t_ray ray, float factor);

#endif
