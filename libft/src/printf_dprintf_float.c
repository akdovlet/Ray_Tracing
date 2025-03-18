/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dprintf_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:18:51 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 13:21:21 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	count_zeros(double f)
{
	int	zero_counter;

	zero_counter = 0;
	while (f < 1 && zero_counter < 6)
	{
		zero_counter++;
		f *= 10;
	}
	return (zero_counter);
}

int	float_formatting(double f, t_print *data)
{
	double	n;
	int		i;
	int		wrote;
	int		zero_counter;
	char	*str;

	wrote = 0;
	i = 0;
	zero_counter = count_zeros(f);
	while (--zero_counter)
		wrote += char_tobuffer('0', data);
	if (zero_counter < 6)
	{
		n = f * 100000;
		str = ft_itoa(n);
		if (!str)
			return (0);
		while (wrote < 6 && str[i])
			wrote += char_tobuffer(str[i++], data);
		free(str);
	}
	return (wrote);
}

int	float_tobuffer(double f, t_print *data)
{
	char	*i_to_str;
	double	floating;
	int		integer_part;
	int		wrote;

	integer_part = f;
	i_to_str = ft_itoa(integer_part);
	if (!i_to_str)
		return (0);
	wrote = string_tobuffer(i_to_str, data);
	free(i_to_str);
	floating = f - (double)integer_part;
	if (floating < 0)
		floating = -floating;
	wrote += char_tobuffer('.', data);
	wrote += float_formatting(floating, data);
	return (wrote);
}
