/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:27:51 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/14 14:25:57 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"

v4		bounce_rays(t_world *world, t_ray ray, uint32_t seed);
v4		random_unit_vec(uint32_t seed);
void		ray_for_pixel(t_camera *cam, t_ray *ray, double x, double y);
void		cache_ray(t_ray *ray, t_camera *cam);
void		render(t_camera cam, t_world world, t_img *img, t_mlx *mlx);
// void		path_tracing(t_ray *ray, t_camera cam, t_world world, 
// 			t_img *img, t_mlx *mlx, int frame_index, unsigned int *accumulation);
void		path_tracing(t_ray *ray, t_camera cam, t_world world,
		 	t_img *img, t_mlx *mlx, double frame_index, v4 *accumulation);
void		render_accumulation(t_camera cam, t_world world, t_img *img, t_mlx *mlx);
