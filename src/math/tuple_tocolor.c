/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_tocolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:26:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/03 10:54:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	tuple_tocolor(t_tuple tcolor)
{
	t_color	color;

	if (tcolor.x > 0.0)
		tcolor.x = sqrt(tcolor.x);
	if (tcolor.y > 0.0)
		tcolor.y = sqrt(tcolor.y);
	if (tcolor.z > 0.0)
		tcolor.z = sqrt(tcolor.z);
	color.bytes[2] = fmin(round(tcolor.x * 255.0), 255.0);
	color.bytes[1] = fmin(round(tcolor.y * 255.0), 255.0);
	color.bytes[0] = fmin(round(tcolor.z * 255.0), 255.0);
	color.bytes[3] = 255;
	return (color.color);
}
