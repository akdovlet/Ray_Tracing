/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:46 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/14 16:12:53 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdbool.h>
# include <float.h>
# include <string.h>
# include <time.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <X11/X.h>
# include <errno.h>

# include "random.h"
# include "X11/keysym.h"
# include "mlx.h"
# include "libft.h"
# include "data_struct.h"
# include "tuple.h"
# include "matrix.h"
# include "shapes.h"
# include "mlx_utils.h"
# include "pattern.h"
# include "colors.h"
# include "renderer.h"
# include "tuple.h"
# include "ray.h"
# include "parsing.h"

# define WIDTH 1920 / 2
# define HEIGHT 1080

t_tuple		position(t_ray ray, double factor);
void		render(t_camera cam, t_world world, t_img *img, t_mlx *mlx);
bool		is_shadowed(t_world *world, t_tuple point);
int			render_and_move(t_data *data);
int			key_manager(int keysym, t_data *data);
int			mouse_manager(int button, int x, int y, t_data *data);

#endif
