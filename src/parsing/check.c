#include "data_file.h"

int	_check_line_empty(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
	}
	return (1);
}

int	_check_line_char(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!_is_up(line[i], "ACLspplcy-0123456789., \n\t"))
			return (1);
	}
	return (0);
}

int	_check_vec3(char *str)
{
	char	**array;

	array = ft_split(str, ',');
	if (!array)
		return (1);
	if (ft_strslen(array) != 3)
		return (_free_array(array), 1);
	_free_array(array);
	return (0);
}

int	_check_float(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!_is_up(str[i], "0123456789.-\n"))
			return (1);
	}
	return (0);
}

int	_check_rt_filename(char *rt_filename)
{
	int	len;

	if (!rt_filename)
		return (1);
	len = ft_strlen(rt_filename);
	if (rt_filename[len - 1] != 't' || rt_filename[len - 2] != 'r'
		|| rt_filename[len - 3] != '.')
		return (1);
	return (0);
}
