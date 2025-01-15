/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_tocolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:26:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/15 14:31:38 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	tuple_tocolor(t_tuple tcolor)
{
	t_color	color;

	color.bytes[2] = fmin(round(tcolor.x * 255.0f), 255.0f);
	color.bytes[2] = fmax(round(color.bytes[2]), 0.0f);
	color.bytes[1]= fmin(round(tcolor.y * 255.0f), 255.0f);
	color.bytes[1] = fmax(round(color.bytes[1]), 0.0f);
	color.bytes[0] = fmin(round(tcolor.z * 255.0f), 255.0f);
	color.bytes[0] = fmax(round(color.bytes[0]), 0.0f);
	color.bytes[3] = 0;
	return (color.color);
}
