/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:41:45 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/09 12:46:43 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_within_bounds(double x, double y)
{
	if (x < WIDTH && y < HEIGHT && x > 0 && y > 0)
		return (1);
	return (0);
}

void	ak_mlx_pixel_put(t_img *data, int dx, int dy, uint32_t color)
{
	char	*dst;

	dst = data->addr + (dy * data->line_length + dx * (data->bits_per_pixel / 8));
	*(uint32_t *)dst = color;
}

void	ak_pixel_put(t_img *data, t_tuple t1, unsigned int color)
{
	ak_mlx_pixel_put(data, t1.x, t1.y, color);
}

void	put_pixel(t_img *img, unsigned int color, t_tuple t1)
{
	t_tuple center;
	
	center = (t_tuple){WIDTH / 2, HEIGHT / 2, 0, 1};
	ak_pixel_put(img, tuple_add(center, t1), color);
}
