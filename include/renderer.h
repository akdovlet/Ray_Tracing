/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:27:51 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/24 19:19:10 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"

t_tuple		bounce_rays(t_world *world, t_ray ray, uint32_t seed);
t_tuple		trace_rays(t_world *world, t_ray ray, uint32_t seed);
void		render(t_camera cam, t_world world, t_img *img, t_mlx *mlx);
// void		path_tracing(t_ray *ray, t_camera cam, t_world world, 
// 			t_img *img, t_mlx *mlx, int frame_index, unsigned int *accumulation);
void		path_tracing(t_ray *ray, t_camera cam, t_world world,
		 	t_img *img, t_mlx *mlx, double frame_index,t_tuple *accumulation);
int			render_accumulation(t_data *data);
