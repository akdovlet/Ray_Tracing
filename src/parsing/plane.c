#include "data_file.h"

void	*_create_plane(char **array)
{
	t_data_plane	*plane;

	plane = malloc(sizeof(t_data_plane));
	if (!plane)
		return (NULL);
	*plane = (t_data_plane){};
	plane->position = _data_get_vec3(array[1]);
	plane->normal = _data_get_vec3(array[2]);
	plane->color = vec3_clamp(_data_get_vec3(array[3]), 1.0, 0.0);
    return (plane);
}

int	_pars_plane(t_data_file *data, char **values)
{
	if (!data || !values)
		return (1);
	if (ft_strslen(values) != 4)
		return (1);
	if (_check_vec3(values[1]) || _check_vec3(values[2])
		|| _check_vec3(values[3]))
		return (1);
	data->planes = _dlst_push_back(data->planes, _create_plane(values));
	if (!data->planes)
		return (1);
	return (0);
}

void	*_clear_plane(t_data_plane *plane)
{
	if (!plane)
		return (NULL);
	free(plane);
	return (NULL);
}
