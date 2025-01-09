/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:20:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/09 18:54:53 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

typedef float t_tuple __attribute__((vector_size(16)));
typedef struct s_matrix
{
	t_tuple	raw[4];
}	t_matrix;

typedef	union u_color			t_color;
typedef enum e_type				t_type;
typedef struct s_shape			t_shape;
typedef struct s_vtable_shape	t_vtable_shape;
typedef struct s_intersection	t_intersection;

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


typedef	union u_vec
{
	t_tuple	t1;
}	t_vec;

union u_matrix
{

	
};// __attribute__((__transparent_union__));

enum	e_type
{
	SPHERE,
	PLANE,
};

typedef struct s_light
{
	t_tuple	intensity;
	t_tuple	position;
}	t_light;

typedef struct	s_pattern
{
	int		exists;
	t_tuple	color1;
	t_tuple	color2;
}	t_pattern;

typedef struct s_material
{
	float		ambient;
	float		diffuse;
	float		specular;
	float		shininess;
	t_tuple		color;
	t_pattern	pattern;
}	t_material;

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

typedef struct	s_shape
{
	t_type			type;
	float			radius;
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
	float					t;
	int						count;
	t_shape				object;
	t_vec2					xs;
};

typedef struct s_crossing
{
	float	t;
	t_shape	obj;
}	t_crossing;

typedef struct s_junction
{
	int			count;
	t_crossing	cross[1024];
}	t_junction;

typedef struct s_world
{
	int			obj_count;
	t_shape		obj[20];
	t_light		light;
}	t_world;


typedef struct s_comps
{
	float		t;
	bool		inside;
	t_shape	obj;
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
