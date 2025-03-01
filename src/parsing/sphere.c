#include "data_file.h"

void	*_create_sphere(char **array)
{
	t_data_sphere	*sphere;

	sphere = malloc(sizeof(t_data_sphere));
	if (!sphere)
		return (NULL);
	*sphere = (t_data_sphere){};
	sphere->position = _data_get_vec3(array[1]);
	sphere->diameter = atof(array[2]);
	sphere->color = vec3_clamp(_data_get_vec3(array[3]), 1.0, 0.0);
	return (sphere);
}

int	_pars_sphere(t_data_file *data, char **values)
{
	if (!data || !values)
		return (1);
	if (ft_strslen(values) != 4)
		return (1);
	if (_check_vec3(values[1]) || _check_vec3(values[3]))
		return (1);
	if (_check_float(values[2]))
		return (1);
	data->spheres = _dlst_push_back(data->spheres, _create_sphere(values));
	if (!data->spheres)
		return (1);
	return (0);
}

void	*_clear_sphere(t_data_sphere *sphere)
{
	if (!sphere)
		return (NULL);
	free(sphere);
	return (NULL);
}
