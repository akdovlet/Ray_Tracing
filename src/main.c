/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:21:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/19 19:03:36 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "test.h"
#include "tuple.h"
#include <X11/X.h>


// Boucle infinie pour la routine, qui calcul une frame seulemenet si 
/* si il y a un deplacement. Pareil pour le put image to window

les threads remplissent l'image, et une semaphore qui compte ou mutex
remet l'image a l'ecran seulement si il y a du changement


ou

toujours afficher une frame, quand il y a un changement, naturellement la 
frame sera differente */
int main()
{
	t_img	img;
	t_mlx	mlx;
	t_data data[8];
	t_ray	*ray_cache;
	pthread_t	threads[8];
	int			job_start;
	pthread_mutex_t	img_mutex;

	init_mlx(&mlx, &img);
	mlx_hook(mlx.win_ptr, 17, 0, mlx_loop_end, mlx.mlx_ptr);
	job_start = 0;
	ray_cache = malloc(sizeof(t_ray) * (HEIGHT * WIDTH));
	pthread_mutex_init(&img_mutex, NULL);
	for (size_t i = 0; i < 8; i++)
	{
		data[i] = scene_complex();
		if (i == 0)
			cache_ray(ray_cache, &data->cam);
		data[i].img = img;
		data[i].img_mutex = &img_mutex;
		data[i].mlx = mlx;
		data[i].cache = ray_cache;
		data[i].job_start = job_start;
		data[i].job_end = job_start + (HEIGHT / 8);
		pthread_create(&threads[i], NULL, &render_threads, &data[i]);
		job_start += (HEIGHT / 8);
	}
	mlx_mouse_hook(mlx.win_ptr, &mouse_manager, &data);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, &key_manager, &data);
	// mlx_key_hook(mlx.win_ptr, &key_manager, &data);
	render(data[0].cam, data[0].world, &img, &mlx);
	for(size_t i = 0; i < 8; i++)
	{
		pthread_join(threads[i], NULL);
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	// mlx_loop(mlx.mlx_ptr);
	mlx_clear(&mlx, &img);
	printf("AK out!\n");
	return (0);
}
