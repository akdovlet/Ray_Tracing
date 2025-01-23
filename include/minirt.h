/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:46 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/23 14:29:05 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdbool.h>

# include "X11/keysym.h"
# include "mlx.h"
# include "libft.h"
# include "data_struct.h"
# include "tuple.h"
# include "matrix.h"
# include "objects.h"
# include "mlx_utils.h"
# include "pattern.h"

# define WIDTH 1920 / 2
# define HEIGHT 1080

t_ray		ray_new(t_tuple origin, t_tuple direction);
t_tuple		position(t_ray ray, double factor);
void		render(t_camera cam, t_world world, t_img *img, t_mlx *mlx);
t_ray		ray_for_pixel(t_camera cam, double x, double y);
bool		is_shadowed(t_world world, t_tuple point);
t_tuple		ring_at(t_pattern ring, t_tuple point);
t_tuple		gradient_at(t_pattern pattern, t_tuple point);
int			render_and_move(t_data *data);
int			key_manager(int keysym, t_data *data);
int			mouse_manager(int button, int x, int y, t_data *data);

int	render_loop(t_data *data, int depth);
t_material	glass_material(void);

#endif
