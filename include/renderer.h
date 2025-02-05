/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:27:51 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/04 21:54:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"

t_tuple		bounce_rays(t_world *world, t_ray ray);
t_tuple		random_unit_vec(void);
void		ray_for_pixel(t_camera *cam, t_ray *ray, double x, double y);
void		cache_ray(t_ray *ray, t_camera *cam);
void		render(t_camera cam, t_world world, t_img *img, t_mlx *mlx);
// void		path_tracing(t_ray *ray, t_camera cam, t_world world, 
// 			t_img *img, t_mlx *mlx, int frame_index, unsigned int *accumulation);
void		path_tracing(t_ray *ray, t_camera cam, t_world world,
		 	t_img *img, t_mlx *mlx, double frame_index,t_tuple *accumulation);
void		render_accumulation(t_camera cam, t_world world, t_img *img, t_mlx *mlx);
