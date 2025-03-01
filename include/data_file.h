#ifndef __DATA_FILE_H__
# define __DATA_FILE_H__

# include "_dlst_.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>

typedef struct s_data_ambient_light	t_data_ambient_light;
typedef struct s_data_camera		t_data_camera;
typedef struct s_data_light			t_data_light;
typedef struct s_data_sphere		t_data_sphere;
typedef struct s_data_plane			t_data_plane;
typedef struct s_data_cylinder		t_data_cylinder;
typedef struct s_data_file			t_data_file;

typedef struct s_data_vec3
{
	double							x;
	double							y;
	double							z;
}									t_data_vec3;

// INIT
int									_data_set(t_data_file *data,
										char *rt_filename);
t_data_vec3							_data_get_vec3(char *str);
void								_data_unset(t_data_file *data);
// UTILS
void								_print_array(char **array);
void								_free_array(char **array);
int									ft_strslen(char **array);
int									_is_up(char c, char *str);
// CHECK
int									_check_line_empty(char *line);
int									_check_line_char(char *line);
int									_check_vec3(char *str);
int									_check_float(char *str);
int									_check_rt_filename(char *rt_filename);
// CLAMP
t_data_vec3							vec3_clamp(t_data_vec3 v, double upr,
										double lowr);
// AMBIENT LIGHT
int									_pars_ambient_light(t_data_file *data,
										char **values);
void								*_clear_ambient_light(t_data_ambient_light *ambient_light);
// CAMERA
int									_pars_camera(t_data_file *data,
										char **values);
void								*_clear_camera(t_data_camera *camera);
// LIGHT
int									_pars_light(t_data_file *data,
										char **values);
void								*_clear_light(t_data_light *light);
// SPHERE
int									_pars_sphere(t_data_file *data,
										char **values);
void								*_clear_sphere(t_data_sphere *sphere);
// PLANE
int									_pars_plane(t_data_file *data,
										char **values);
void								*_clear_plane(t_data_plane *plane);
// CYLINDER
int									_pars_cylinder(t_data_file *data,
										char **values);
void								*_clear_cylinder(t_data_cylinder *cylinder);

struct								s_data_ambient_light
{
	float							ratio;
	t_data_vec3						color;
};

struct								s_data_camera
{
	t_data_vec3						position;
	t_data_vec3						normal;
	float							fov;
};

struct								s_data_light
{
	t_data_vec3						position;
	float							ratio;
	t_data_vec3						color;
};

struct								s_data_sphere
{
	t_data_vec3						position;
	float							diameter;
	t_data_vec3						color;
};

struct								s_data_plane
{
	t_data_vec3						position;
	t_data_vec3						normal;
	t_data_vec3						color;
};

struct								s_data_cylinder
{
	t_data_vec3						position;
	t_data_vec3						normal;
	float							diameter;
	float							height;
	t_data_vec3						color;
};

struct								s_data_file
{
	t_dlst							*ambient_lights;
	t_dlst							*cameras;
	t_dlst							*lights;
	t_dlst							*spheres;
	t_dlst							*planes;
	t_dlst							*cylinders;
};

#endif /* !__DATA_FILE_H__ */