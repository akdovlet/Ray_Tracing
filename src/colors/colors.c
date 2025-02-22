/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:43:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/14 19:35:08 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	black(void)
{
	return ((t_tuple){0.01, 0.01, 0.01, 0.01});
}

t_tuple	white(void)
{
	return ((t_tuple){1.0, 1.0, 1.0, 1.0});
}

t_tuple	red(void)
{
	return ((t_tuple){1.0, 0.0, 0.0, 0.0});
}

t_tuple	blue(void)
{
	return ((t_tuple){0.0, 0.0, 1.0, 0.0});
}

t_tuple	green(void)
{
	return ((t_tuple){0.0, 1.0, 0.0, 0.0});
}
