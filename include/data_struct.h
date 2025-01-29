/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:20:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/29 15:31:15 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

typedef union u_matrix			t_matrix;
typedef	union u_color			t_color;
typedef enum e_type				t_type;
typedef struct s_shape			t_shape;
typedef struct s_vtable_shape	t_vtable_shape;
typedef struct s_intersection	t_intersection;

typedef struct s_vec2
{
	double	dis;
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vec3 
{
	int x;	
	int y;	
	int z;	
} t_vec3;

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct s_shear
{
	double	x;
	double	y;
	double	z;
}	t_shear;

typedef double v4 __attribute__((vector_size(16)));

typedef	union u_vec
{
	t_tuple	t1;
	v4		v;
}	t_vec;

union	u_matrix
{
	struct
	{
		t_tuple r1;
		t_tuple r2;
		t_tuple r3;
		t_tuple r4;
	};
	double	raw[4][4];
} __attribute__((__transparent_union__));

enum	e_type
{
	SPHERE,
	PLANE,
};

typedef struct	s_light
{
	t_tuple	intensity;
	t_tuple	position;
}	t_light;

typedef struct	s_pattern
{
	int			exists;
	t_tuple		color1;
	t_tuple		color2;
	t_matrix	transform;
	t_tuple		(*pattern_at)(struct s_pattern pattern, t_tuple point);
}	t_pattern;

typedef struct s_material
{
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	double		reflective;
	double		transparency;
	double		refractive_index;
	t_tuple		color;
	t_pattern	pattern;
}	t_material;

union	u_color
{
	struct
	{
			/* data */
	};
	
	unsigned char	bytes[4];
	unsigned int	color;
};

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct	s_shape
{
	t_type			type;
	double			radius;
	uintptr_t		id;
	t_tuple			coordinates;
	t_matrix		transform;
	t_material		matter;
	t_ray			local_ray;
	t_tuple			local_normal;
	t_vec2			(*local_interesct)(t_ray, struct s_shape);
	t_tuple			(*local_normalat)(struct s_shape, t_tuple point);
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
	size_t	shape_index;
	// t_shape	obj;
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
	struct {
		t_shape		*buffer;
		size_t		count;
	} intersect_lst;
	t_light		light;
}	t_world;


typedef struct s_comps
{
	bool		inside;
	size_t		shape_index;
	double		t;
	double		n1;
	double		n2;
	t_tuple		world_point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		reflectv;
	t_tuple		overz;
	t_tuple		under_point;
	// t_shape		obj;
}	t_comps;

typedef struct s_container
{
	t_shape				shape;
	struct s_container	*next;
}	t_container;

typedef struct s_camera
{
	double		hsize;
	double		vsize;
	double		fov;
	double		psize;
	double		half_view;
	double		half_width;
	double		half_height;
	t_matrix	transform;
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
}	t_camera;

# include "mlx_utils.h"

typedef struct	s_data
{
	t_camera	cam;
	t_world		world;
	t_img		img;
	t_mlx		mlx;
}	t_data;

#endif
