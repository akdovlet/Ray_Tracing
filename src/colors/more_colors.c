/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:58:50 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 17:15:08 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	yellow(void)
{
	return ((t_tuple){1, 1, 0, 0});
}

t_tuple	brown(void)
{
	return ((t_tuple){1, 0.5, 0, 0});
}

t_tuple	cyan(void)
{
	return ((t_tuple){0, 1, 1, 0});
}

t_tuple	purple(void)
{
	return ((t_tuple){1, 0, 1, 0});
}
