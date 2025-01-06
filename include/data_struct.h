/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:20:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/06 19:28:41 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

typedef union u_matrix			t_matrix;
typedef	union u_color			t_color;
typedef enum e_type				t_type;
typedef struct s_object			t_object;
typedef struct s_vtable_shape	t_vtable_shape;

typedef struct s_vec2
{
	float	dis;
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

typedef struct s_shear
{
	float	x;
	float	y;
	float	z;
}	t_shear;

typedef	union u_vec
{
	t_tuple	t1;
	float	v[4];
}	t_vec;

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

enum	e_type
{
	SPHERE,
};

typedef struct s_light
{
	t_tuple	intensity;
	t_tuple	position;
}	t_light;

typedef struct s_material
{
	t_tuple	color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

typedef struct s_object
{
	t_type			type;
	float			radius;
	uintptr_t		id;
	t_tuple			coordinates;
	t_matrix		transform;
	t_material		matter;
}	t_object;

union	u_color
{
	unsigned char	bytes[4];
	unsigned int	color;
};

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_intersection
{
	float					t;
	int						count;
	t_object				object;
	t_vec2					xs;
}	t_intersection;

typedef struct s_crossing
{
	float	t;
	t_object	obj;
}	t_crossing;

typedef struct s_junction
{
	int			count;
	t_crossing	cross[1024];
}	t_junction;

typedef struct s_world
{
	int			obj_count;
	t_object	obj[20];
	t_light		light;
}	t_world;

typedef struct s_comps
{
	float		t;
	bool		inside;
	t_object	obj;
	t_tuple		world_point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		overz;
}	t_comps;

typedef struct s_camera
{
	float		hsize;
	float		vsize;
	float		fov;
	float		psize;
	float		half_view;
	float		half_width;
	float		half_height;
	t_matrix	transform;
}	t_camera;

#endif
