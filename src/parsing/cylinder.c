#include "data_file.h"

void	*_create_cylinder(char **array)
{
	t_data_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_data_cylinder));
	if (!cylinder)
		return (NULL);
	*cylinder = (t_data_cylinder){};
	cylinder->position = _data_get_vec3(array[1]);
	cylinder->normal = _data_get_vec3(array[2]);
	cylinder->diameter = atof(array[3]);
	cylinder->height = atof(array[4]);
	cylinder->color = vec3_clamp(_data_get_vec3(array[5]), 1.0, 0.0);
	return (cylinder);
}

int	_pars_cylinder(t_data_file *data, char **values)
{
	if (!data || !values)
		return (1);
	if (ft_strslen(values) != 6)
		return (1);
	if (_check_vec3(values[1]) || _check_vec3(values[2])
		|| _check_vec3(values[5]))
		return (1);
	if (_check_float(values[3]) || _check_float(values[4]))
		return (1);
	data->cylinders = _dlst_push_back(data->cylinders,
			_create_cylinder(values));
	if (!data->cylinders)
		return (1);
	return (0);
}

void	*_clear_cylinder(t_data_cylinder *cylinder)
{
	if (!cylinder)
		return (NULL);
	free(cylinder);
	return (NULL);
}
