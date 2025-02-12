/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_tocolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:26:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:19:36 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	tuple_tocolor(v4 tcolor)
{
	t_color	color;
	double		r;
	double		g;
	double		b;

	if (tcolor[0] > 0.0)
		tcolor[0] = sqrt(tcolor[0]);
	if (tcolor[1] > 0.0)
		tcolor[1] = sqrt(tcolor[1]);
	if (tcolor[2] > 0.0)
		tcolor[2] = sqrt(tcolor[2]);
	r = fmin(round(tcolor[0] * 255.0), 255.0);
	r = fmax(r, 0.0);
	g = fmin(round(tcolor[1] * 255.0), 255.0);
	g = fmax(g, 0.0);
	b = fmin(round(tcolor[2] * 255.0), 255.0);
	b = fmax(b, 0.0);
	color.bytes[2] = r;
	color.bytes[1] = g;
	color.bytes[0] = b;
	color.bytes[3] = 0;
	return (color.color);
}
