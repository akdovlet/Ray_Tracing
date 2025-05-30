/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:49:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/28 22:11:42 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_extension(char *str, int len)
{
	if (str[len--] == 't' && str[len--] == 'r' && str[len] == '.')
		return (0);
	return (1);
}

int	check_file(char *str)
{
	int	len;
	int	fd;

	len = ft_strlen(str);
	if (len < 4 || check_extension(str, len - 1))
	{
		ft_dprintf(2, "Error: wrong file format: `%s'\n", str);
		return (-1);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_dprintf(2, "Error: %s: `%s'\n", strerror(errno), str);
	return (fd);
}

int	check_flag(char *str)
{
	if (!str || ft_strlen(str) < 2)
		return (RAY);
	if (str[0] == '-' && str[1] == 'p' && !str[2])
		return (PATH);
	return (RAY);
}
