/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:41:45 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/18 17:18:45 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_within_bounds(float x, float y)
{
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
		return (1);
	return (0);
}

void	ak_mlx_pixel_put(t_img *data, float dx, float dy, unsigned int color)
{
	char	*dst;
	int		x;
	int		y;

	if (!is_within_bounds(dx, dy))
		return ;
	x = (int)round(dx);
	y = (int)round(dy);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
