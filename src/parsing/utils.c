#include "data_file.h"

void	_print_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		printf("%s\n", array[i]);
}

void	_free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	ft_strslen(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		(void)i;
	return (i);
}

int	_is_up(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}
