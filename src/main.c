/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/31 17:42:59 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "test.h"

void	put_pixel(t_img *img, unsigned int color, t_tuple t1)
{
	t_tuple center;
	
	center = (t_tuple){WIDTH / 2, HEIGHT / 2, 0, 1};
	ak_pixel_put(img, tuple_add(center, t1), color);
}

int main()
{
	t_img	img;
	t_mlx	mlx;
	init_mlx(&mlx, &img);
	mlx_key_hook(mlx.win_ptr, &key_manager, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);

	// position_test();
	// sphere_test();
	// transform_test();
	// object_transform_test();
	draw_sphere(&img, &mlx);
	normal_at_test();
	transpose_test();
	reflect_test();
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);

	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
}
