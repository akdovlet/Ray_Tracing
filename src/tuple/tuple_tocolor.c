/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_tocolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:26:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/13 18:50:23 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	tuple_tocolor(t_tuple tcolor)
{
	t_color	color;

	color.bytes[2] = fminf(roundf(tcolor.x * 255.0f), 255.0f);
	color.bytes[2] = fmaxf(roundf(color.bytes[2]), 0.0f);
	color.bytes[1]= fminf(roundf(tcolor.y * 255.0f), 255.0f);
	color.bytes[1] = fmaxf(roundf(color.bytes[1]), 0.0f);
	color.bytes[0] = fminf(roundf(tcolor.z * 255.0f), 255.0f);
	color.bytes[0] = fmaxf(roundf(color.bytes[0]), 0.0f);
	color.bytes[3] = 0;
	return (color.color);
}
