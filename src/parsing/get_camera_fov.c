/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_fov.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:48:46 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/18 18:03:16 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"
#include "parsing.h"

int	get_camera_fov(double *f, char *str, int *i, int line)
{
	char	*err;

	skip_whitespace(str, i);
	if (!is_valid(str[*i]))
		return (bad_syntax(line, str, 1));
	*f = ak_atof(str, i);
	if (*f > 180 || *f < 0.0)
	{
		err = "Error: line %d: value %f exceeds [0-180] range\n";
		return (ft_dprintf(2, err, line, *f), 1);		 
	}
	return (0);
}
