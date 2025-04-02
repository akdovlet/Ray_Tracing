/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:27:51 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 21:12:58 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"

t_tuple		bounce_rays(t_world *world, t_ray ray, uint32_t seed);
t_tuple		trace_rays(t_world *world, t_ray ray, uint32_t seed, int frame_index);
// void		path_tracing(t_ray *ray, t_camera cam, t_world world, 
// 			t_img *img, t_mlx *mlx, int frame_index, unsigned int *accumulation);
void		path_tracing(t_data *data);
int			render_accumulation(t_data *data);
int			ray_tracing(t_data *data);

