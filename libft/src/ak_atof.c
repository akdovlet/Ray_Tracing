/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ak_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:00:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 12:54:24 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math.h"

double	divide_value(double f, int divisor)
{
	if (!divisor)
		return (f);
	divisor = pow(10, divisor);
	return (f / (double)divisor);
}

int	check_sign(char *str, int *i)
{
	int	flip;

	flip = 1;
	if (str[*i] == '-' || str[*i] == '+')
		if (str[(*i)++] == '-')
			flip = -flip;
	return (flip);
}

double	ak_atof(char *str, int *i)
{
	double	f;
	int		flip;
	int		divisor;

	divisor = 0;
	f = 0;
	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
	flip = check_sign(str, i);
	while (str[*i])
	{
		if ((!ft_isdigit(str[*i]) && str[*i] != '.') || f > INT_MAX)
			break ;
		if (divisor)
			divisor++;
		if (str[*i] == '.')
		{
			if (divisor || !ft_isdigit(str[(*i) + 1]))
				break ;
			(*i)++;
			divisor++;
		}
		f = f * 10 + str[(*i)++] - '0';
	}
	return (divide_value(f, divisor) * flip);
}
