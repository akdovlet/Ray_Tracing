/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:20:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/14 14:08:28 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# include "mlx_utils.h"

typedef	union u_color			t_color;
typedef struct s_shape			t_shape;
typedef struct s_intersection	t_intersection;
typedef double v4 __attribute__((__vector_size__(32), __aligned__(32)));
typedef double v2 __attribute__((vector_size(8), __aligned__(8)));

typedef union s_vec2
{
	struct {
		double	dis;
		double	x;
		double	y;		
	};
	double	vec3[3];
}	t_vec2;

union u_vec4
{
	v4	vec4;
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
	
};
typedef union u_vec4 t_vec4;


typedef struct s_vec3 
{
	int x;	
	int y;	
	int z;	
}	t_vec3;

typedef struct s_dvec3 
{
	double a;	
	double b;	
	double c;	
}	t_dvec3;

typedef	struct s_matrix
{
	v4	arr[4];
}	t_matrix;

typedef struct	s_light
{
	v4	intensity;
	v4	position;
}	t_light;

typedef struct	s_pattern
{
	int			exists;
	v4		color1;
	v4		color2;
	t_matrix	transform;
	v4		(*pattern_at)(struct s_pattern pattern, v4 point);
}	t_pattern;

typedef struct s_material
{
	double		ambient;
	double		roughness;
	double		metalic;
	double		diffuse;
	double		specular;
	double		shininess;
	double		reflective;
	double		transparency;
	double		refractive_index;
	double		emission_power;
	v4		color;
	v4		emission_color;
	t_pattern	pattern;
}	t_material;

union	u_color
{
	unsigned char	bytes[4];
	unsigned int	color;
};

typedef struct s_ray
{
	v4	origin;
	v4	direction;
}	t_ray;

typedef struct	s_shape
{
	double			min;
	double			max;
	uintptr_t		id;
	v4				coordinates;
	t_matrix		transform;
	t_material		matter;
	t_vec2			(*local_interesct)(t_ray, struct s_shape);
	v4				(*local_normalat)(struct s_shape, v4 point);
}	t_shape;

struct s_intersection
{
	bool					hit;
	double					t;
	int						count;
	t_shape					object;
	t_vec2					xs;
};

typedef struct s_crossing
{
	double	t;
	t_shape	*obj;
}	t_crossing;

typedef struct s_junction
{
	bool		hit;
	int			count;
	t_crossing	closest;
	t_crossing	cross[100];
}	t_junction;

typedef struct s_world
{
	int			obj_count;
	t_shape		obj[20];
	t_light		light;
}	t_world;


typedef struct s_comps
{
	bool		inside;
	double		t;
	double		n1;
	double		n2;
	v4		world_point;
	v4		eyev;
	v4		normalv;
	v4		reflectv;
	v4		overz;
	v4		under_point;
	t_shape		*obj;
}	t_comps;

typedef struct s_container
{
	t_shape				*shape;
	struct s_container	*next;
}	t_container;

typedef struct s_camera
{
	int			hsize;
	int			vsize;
	double		fov;
	double		psize;
	double		pitch;
	double		yaw;
	double		roll;
	double		half_view;
	double		half_width;
	double		half_height;
	v2			last_mouse_position;
	t_matrix	transform;
	v4		from;
	v4		to;
	v4		up;
	v4		right;
}	t_camera;

typedef struct	s_data
{
	t_camera	cam;
	t_world		world;
	t_img		img;
	t_mlx		mlx;
}	t_data;

#endif
