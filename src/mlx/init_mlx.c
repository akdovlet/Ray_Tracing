/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:32:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 20:14:40 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_mlx(t_mlx *mlx, t_img *img)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "minirt");
	if (!mlx->win_ptr)
		return (1);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!img->img_ptr)
		return (1);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (!img->addr)
		return (1);
	return (0);
}
