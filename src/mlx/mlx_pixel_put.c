/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:41:45 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 17:11:11 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ak_mlx_pixel_put(t_img *data, int dx, int dy, uint32_t color)
{
	char	*dst;

	dst = data->addr + (dy * data->line_length + dx * \
			(data->bits_per_pixel / 8));
	*(uint32_t *)dst = color;
}
