/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:56:26 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/04 17:02:51 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ak_atof(char *str, int *i)
{
	double	f;
	int		flip;

	flip = 1;
	if (str[*i] == '-' || str[*i] == '+')
		if (str[(*i)++] == '-')
			flip = -flip;
	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
	while (str[*i] && ft_isalnum(str[*i]))
}

void	add_vertice(void)
{
	
}

t_world	parse_obj(uint32_t fd)
{
	char	*buff;
	int		ignored;

	ignored = 0;
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (buff[0] != 'v')
			ignored++;
		else
			add_vertice();
	}
}
