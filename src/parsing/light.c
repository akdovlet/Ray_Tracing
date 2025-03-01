#include "data_file.h"

void	*_create_light(char **array)
{
	t_data_light	*light;

	light = malloc(sizeof(t_data_light));
	if (!light)
		return (NULL);
	*light = (t_data_light){};
	light->position = _data_get_vec3(array[0]);
	light->ratio = atof(array[1]);
	light->color = vec3_clamp(_data_get_vec3(array[2]), 1.0, 0.0);
	return (light);
}

int	_pars_light(t_data_file *data, char **values)
{
	if (!data || !values || data->lights)
		return (1);
	if (ft_strslen(values) != 4)
		return (1);
	if (_check_vec3(values[1]) || _check_vec3(values[3]))
		return (1);
	if (_check_float(values[2]))
		return (1);
	data->lights = _dlst_push_back(data->lights, _create_light(values));
	if (!data->lights)
		return (1);
	return (0);
}

void	*_clear_light(t_data_light *light)
{
	if (!light)
		return (NULL);
	free(light);
	return (NULL);
}
