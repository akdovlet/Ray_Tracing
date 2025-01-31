/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_tocolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:26:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/31 16:11:26 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	tuple_tocolor(t_tuple tcolor)
{
	t_color	color;
	double gamma;

	gamma = 1.0 / 2.2;
	if (tcolor.x > 0.0)
		tcolor.x = pow(tcolor.x, gamma);
	if (tcolor.y > 0.0)
		tcolor.y = pow(tcolor.y, gamma);
	if (tcolor.z > 0.0)
		tcolor.z = pow(tcolor.z, gamma);
	color.bytes[2] = fmin(round(tcolor.x * 255.0), 255.0);
	color.bytes[2] = fmax(round(color.bytes[2]), 0.0);
	color.bytes[1]= fmin(round(tcolor.y * 255.0), 255.0);
	color.bytes[1] = fmax(round(color.bytes[1]), 0.0);
	color.bytes[0] = fmin(round(tcolor.z * 255.0), 255.0);
	color.bytes[0] = fmax(round(color.bytes[0]), 0.0);
	color.bytes[3] = 0;
	return (color.color);
}
