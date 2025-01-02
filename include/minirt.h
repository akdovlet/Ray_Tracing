/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:46 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/02 18:12:21 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "X11/keysym.h"
# include "mlx.h"
# include "libft.h"
#include "data_struct.h"

# define WIDTH 1000
# define HEIGHT 1000

# include "matrix.h"
# include "objects.h"
# include "mlx_utils.h"

void		put_pixel(t_img *img, unsigned int color, t_tuple t1);

void		ak_pixel_put(t_img *data, t_tuple t1, unsigned int color);


/* ray */

t_ray		ray_new(t_tuple origin, t_tuple direction);
t_tuple		position(t_ray ray, float factor);

#endif
