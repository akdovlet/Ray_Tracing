/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:37:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/15 20:39:58 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "data_struct.h"

t_ray		ray_new(t_tuple origin, t_tuple direction);
void		ray_for_pixel(t_camera *cam, t_ray *ray, double x, double y);
t_ray		ray_transform(t_ray ray, t_matrix m);
void		cache_ray(t_ray *ray, t_camera *cam);
void		ray_for_pixel(t_camera *cam, t_ray *ray, double x, double y);

#endif
