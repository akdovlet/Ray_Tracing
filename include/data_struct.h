/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:20:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 16:27:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# include "mlx_utils.h"
# include <stdint.h>
# include <stdbool.h>

typedef union u_matrix			t_matrix;
typedef	union u_color			t_color;
typedef struct s_shape			t_shape;
typedef struct s_intersection	t_intersection;

typedef struct s_vec2f
{
	double	x;
	double	y;
}	t_vec2f;

typedef union s_vec3f
{
	struct {
		double	dis;
		double	x;
		double	y;
	};
	double	vec3[3];
}	t_vec3f;

typedef struct s_vec3 
{
	int x; 
	int y;
	int z;
} t_vec3;

typedef struct s_dvec3 
{
	double a;
	double b;
	double c;
} t_dvec3;

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef double v4 __attribute__((vector_size(16)));
typedef double v2 __attribute__((vector_size(8)));

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

typedef struct	s_light
{
	t_tuple	intensity;
	t_tuple	position;
}	t_light;

typedef struct	s_sky
{
	double	intensity;
	t_tuple	color;
	bool	sky_box;
}	t_sky;

typedef struct	s_faces
{
	t_tuple	main;
	t_tuple	ul;
	t_tuple	ur;
	t_tuple	bl;
	t_tuple	br;
}	t_faces;

typedef struct	s_pattern
{
	int			exists;
	int			width;
	int			height;
	t_tuple		color1;
	t_tuple		color2;
	t_matrix	transform;
	t_vec2f		(*uv_mapping)(t_tuple);
	t_tuple		(*pattern_at)(struct s_pattern *, t_tuple );
	struct s_pattern	*uv_pattern;
	t_faces		faces[6];
	t_img		map;
	t_img		height_map;
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
	t_tuple		color;
	t_tuple		specular_color;
	t_tuple		emission_color;
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
	uintptr_t		id;
	t_tuple			coordinates;
	t_matrix		transform;
	t_material		matter;
	union{
		struct{
			t_tuple	p1;
			t_tuple	p2;
			t_tuple	p3;
			t_tuple	e1;
			t_tuple	e2;
			t_tuple	normal;
		};
		struct{
			bool	closed;
			double	min;
			double	max;
		};
	};
	t_vec3f			(*local_intersect)(struct s_shape *, t_ray);
	t_tuple			(*local_normalat)(struct s_shape *, t_tuple);
}	t_shape;

struct s_intersection
{
	bool					hit;
	double					t;
	int						count;
	t_vec3f					xs;
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

typedef struct s_camera
{
	int			hsize;
	int			vsize;
	double		fov;
	double		psize;
	double		half_view;
	double		half_width;
	double		half_height;
	double		cam_distance;
	t_matrix	transform;
	t_matrix	view;
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_tuple		true_up;
	t_tuple		left;
	t_tuple		forward;
}	t_camera;

typedef struct s_world
{
	int			obj_count;
	t_shape		*obj;
	t_light		light;
	t_sky		sky;
	t_camera	cam;
}	t_world;

typedef struct	s_objlst
{
	struct s_objlst	*next;
}	t_objlst;

typedef struct s_lightlst
{
	t_light				light;
	struct s_lightlst	*next;
}	t_lightlst;

typedef struct	s_parse
{
	int			obj_count;
	int			light_count;
	t_objlst	*obj;
	t_lightlst	*light;
}	t_parse;

typedef struct s_comps
{
	bool		inside;
	double		t;
	double		n1;
	double		n2;
	t_tuple		world_point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		diffusev;
	t_tuple		reflectv;
	t_tuple		overz;
	t_tuple		under_point;
	t_shape		*obj;
}	t_comps;

typedef struct s_container
{
	t_shape				*shape;
	struct s_container	*next;
}	t_container;

typedef struct	s_data
{
	int			job_end;
	int			frame_index;
	int			skip;
	double		ts;
	double		ts_last;
	bool		moved;
	t_camera	cam;
	t_world		world;
	t_img		img;
	t_mlx		mlx;
	t_ray		*rays;
	t_tuple		*accumulation;
}	t_data;

typedef struct s_groups
{
	t_shape	*triangles;
}	t_groups;



#endif
