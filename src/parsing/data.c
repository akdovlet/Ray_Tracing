#include "data_file.h"

int	_open_rt_file(char *rt_filename)
{
	int	rt_fd;

	if (!rt_filename)
		return (-1);
	if (_check_rt_filename(rt_filename))
		return (printf("Invalid rt file\n"), -1);
	rt_fd = open(rt_filename, O_RDONLY);
	if (rt_fd == -1)
		return (perror("open"), -1);
	return (rt_fd);
}

t_data_vec3	_data_get_vec3(char *str)
{
	t_data_vec3	vec;
	char	**array;

	array = ft_split(str, ',');
	if (!array)
		return ((t_data_vec3){0, 0, 0});
	if (ft_strslen(array) != 3)
	{
		_free_array(array);
		return ((t_data_vec3){0, 0, 0});
	}
	vec.x = atof(array[0]);
	vec.y = atof(array[1]);
	vec.z = atof(array[2]);
	_free_array(array);
	return (vec);
}

int	_pars_data(t_data_file *data, char **values)
{
	if (!data || !values)
		return (1);
	if (!ft_strcmp(values[0], "A") && !_pars_ambient_light(data, values))
		return (0);
	else if (!ft_strcmp(values[0], "C") && !_pars_camera(data, values))
		return (0);
	else if (!ft_strcmp(values[0], "L") && !_pars_light(data, values))
		return (0);
	else if (!ft_strcmp(values[0], "sp") && !_pars_sphere(data, values))
		return (0);
	else if (!ft_strcmp(values[0], "pl") && !_pars_plane(data, values))
		return (0);
	else if (!ft_strcmp(values[0], "cy") && !_pars_cylinder(data, values))
		return (0);
	else if (!ft_strcmp(values[0], "\n") || !ft_strcmp(values[0], "\0"))
		return (0);
	return (1);
}

int	_get_data(t_data_file *data, int rt_fd)
{
	char	*line;
	char	*tmp;
	char	**values;

	if (!data || rt_fd < 0)
		return (1);
	tmp = NULL;
	values = NULL;
	line = get_next_line(rt_fd);
	if (!line)
		return (1);
	while (line)
	{
		if (_check_line_empty(line))
		{
			free(line);
			line = NULL;
			continue ;
		}
		if (_check_line_char(line))
			return (free(line), 1);
		tmp = ft_strtrim(line, " \t");
		free(line);
		line = NULL;
		values = ft_split(tmp, ' ');
		if (!values)
			return (free(tmp), 1);
		free(tmp);
		tmp = NULL;
		if (_pars_data(data, values))
			return (_free_array(values), 1);
		_free_array(values);
		line = get_next_line(rt_fd);
	}
	return (0);
}

int _check_data(t_data_file *data)
{
	if (!data)
		return (1);
	if (!data->ambient_lights || !data->cameras || !data->lights)
		return (1);
	return (0);
}

int	_data_set(t_data_file *data, char *rt_filename)
{
	int	rt_fd;

	if (!data || !rt_filename)
		return (1);
	*data = (t_data_file){};
	rt_fd = _open_rt_file(rt_filename);
	if (rt_fd < 0)
		return (1);
	if (_get_data(data, rt_fd))
		return (close(rt_fd), 1);
	close(rt_fd);
	if (_check_data(data))
		return (1);
	return (0);
}

void	_data_unset(t_data_file *data)
{
	if (!data)
		return ;
	data->ambient_lights = _dlst_clear(data->ambient_lights,
			(void *)_clear_ambient_light);
	data->cameras = _dlst_clear(data->cameras, (void *)_clear_camera);
	data->lights = _dlst_clear(data->lights, (void *)_clear_light);
	data->spheres = _dlst_clear(data->spheres, (void *)_clear_sphere);
	data->planes = _dlst_clear(data->planes, (void *)_clear_plane);
	data->cylinders = _dlst_clear(data->cylinders, (void *)_clear_cylinder);
}
