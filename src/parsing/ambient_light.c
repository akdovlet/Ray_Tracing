#include "data_file.h"

void	*_create_ambient_light(char **array)
{
	t_data_ambient_light	*ambient_light;

	ambient_light = malloc(sizeof(t_data_ambient_light));
	if (!ambient_light)
		return (NULL);
	*ambient_light = (t_data_ambient_light){};
	ambient_light->ratio = atof(array[1]);
	ambient_light->color = _data_get_vec3(array[2]);
	return (ambient_light);
}

int	_pars_ambient_light(t_data_file *data, char **values)
{
	if (!data || !values || data->ambient_lights)
		return (1);
	if (ft_strslen(values) != 3)
		return (1);
	if (_check_float(values[1]) || _check_vec3(values[2]))
		return (1);
	data->ambient_lights = _dlst_push_back(data->ambient_lights,
			_create_ambient_light(values));
	if (!data->ambient_lights)
		return (1);
	return (0);
}

void	*_clear_ambient_light(t_data_ambient_light *ambient_light)
{
	if (!ambient_light)
		return (NULL);
	free(ambient_light);
	return (NULL);
}
