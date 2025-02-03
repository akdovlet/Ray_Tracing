/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_tocolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:26:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/04 00:31:14 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	tuple_tocolor(t_tuple tcolor)
{
	t_color	color;
	double gamma;
	int		r;
	int		g;
	int		b;

	gamma = 1.0 / 2.2;
	if (tcolor.x > 0.0)
		tcolor.x = pow(tcolor.x, gamma);
	if (tcolor.y > 0.0)
		tcolor.y = pow(tcolor.y, gamma);
	if (tcolor.z > 0.0)
		tcolor.z = pow(tcolor.z, gamma);
	r = fmin(round(tcolor.x * 255.0), 255.0);
	r = fmax(r, 0.0);
	g = fmin(round(tcolor.y * 255.0), 255.0);
	g = fmax(g, 0.0);
	b = fmin(round(tcolor.z * 255.0), 255.0);
	b = fmax(b, 0.0);
	color.bytes[2] = r;
	color.bytes[1] = g;
	color.bytes[0] = b;
	color.bytes[3] = 0;
	return (color.color);
}
