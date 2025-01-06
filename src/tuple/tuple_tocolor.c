/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_tocolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:26:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/06 18:26:13 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	tuple_tocolor(t_tuple tcolor)
{
	t_color	color;

	color.bytes[2] = fmin(roundf(tcolor.x * 255), 255);
	color.bytes[1]= fmin(roundf(tcolor.y * 255), 255);
	color.bytes[0] = fmin(roundf(tcolor.z * 255), 255);
	color.bytes[3] = 0;
	return (color.color);
}
