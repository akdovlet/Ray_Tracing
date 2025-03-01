#include "data_file.h"

void	*_create_camera(char **array)
{
	t_data_camera	*camera;

	camera = malloc(sizeof(t_data_camera));
	if (!camera)
		return (NULL);
	*camera = (t_data_camera){};
	camera->position = _data_get_vec3(array[1]);
	camera->normal = _data_get_vec3(array[2]);
	camera->fov = atof(array[3]);
	return (camera);
}

int	_pars_camera(t_data_file *data, char **values)
{
	if (!data || !values || data->cameras)
		return (1);
	if (ft_strslen(values) != 4)
		return (1);
	if (_check_vec3(values[1]) || _check_vec3(values[2]))
		return (1);
	if (_check_float(values[3]))
		return (1);
	data->cameras = _dlst_push_back(data->cameras, _create_camera(values));
	if (!data->cameras)
		return (1);
	return (0);
}

void	*_clear_camera(t_data_camera *camera)
{
	if (!camera)
		return (NULL);
	free(camera);
	return (NULL);
}
