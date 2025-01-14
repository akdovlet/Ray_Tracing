/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/14 18:50:31 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "test.h"
#include "tuple.h"

int main()
{
	t_img	img;
	t_mlx	mlx;
	t_data data;

	init_mlx(&mlx, &img);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);

	// position_test();
	// sphere_test();
	// transform_test();
	// object_transform_test();
	// draw_sphere(&img, &mlx);
	// test_intersect_world();
	// test_light();
	// position_test();
	// normal_at_test();
	// transpose_test();
	// reflect_test();
	// test_color();
	// intersection_test();
	// test_pre_compute();
	// test_shading();
	// test_color_at();
	// test_view_transform();
	// test_camera();
	// test_ray_for_pixel();
	// test_render_world(&img, &mlx);
	data = test_scene(&img, &mlx);
	data.img = img;
	data.mlx = mlx;
	render(data.cam, data.world, &img, &mlx);
	mlx_key_hook(mlx.win_ptr, &key_manager, &data);
	mlx_mouse_hook(mlx.win_ptr, &mouse_manager, &data);
	// test_reflection();
	// test_is_shadowed();
	// test_shape_obj();
	// test_intersect_plane();
	// test_stripe_at();
	// mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);

	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
	printf("AK out!\n");
	return (0);
}
