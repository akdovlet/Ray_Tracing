/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/30 11:53:29 by akdovlet         ###   ########.fr       */
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

// void simulation(t_img img, t_mlx mlx)
// {
// 	t_env	env;
// 	t_proj proj;
	
// 	fprintf(stderr, "Starting projectile simulation\n");

// 	proj.position = point_new(0, 0, 0),
// 	proj.velocity = tuple_multiply(tuple_normalize(vector_new(1, 1.8, 0)), 11.25);

// 	env.gravity = vector_new(0, -0.1, 0);
// 	env.wind = vector_new(-0.01, 0, 0);
// 	fprintf(stderr, "projectile position at start is: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n", proj.position.x, proj.position.y, proj.position.z, proj.position.w);
// 	while(1)
// 	{
// 		proj = tick(env, proj);
// 		ak_mlx_pixel_put(&img, proj.position.x, HEIGHT - proj.position.y, 0xFF0000);
// 		fprintf(stderr, "projectile position is: x: %.2f, y: %.2f, z: %.2f, w: %.2f\n", proj.position.x, proj.position.y, proj.position.z, proj.position.w);
// 		if (proj.position.y <= 0)
// 			break ;
// 		// usleep(10 * 1000);
// 	}
// 	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
// 	fprintf(stderr, "Finished simulation\n\n");	
// }

int main()
{
	t_img	img;
	t_mlx	mlx;
	init_mlx(&mlx, &img);
	mlx_key_hook(mlx.win_ptr, &key_manager, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);

	position_test();
	sphere_test();
	transform_test();
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);


	mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
}
