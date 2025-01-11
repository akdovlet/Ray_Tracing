/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:46 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/08 18:59:19 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdbool.h>

#include "graphics.h"

# include "libft.h"
# include "data_struct.h"
# include "tuple.h"
# include "matrix.h"
# include "objects.h"
# include "pattern.h"

# define WIDTH 1000
# define HEIGHT 500

void        scene(t_camera* camera, t_world* world);

t_ray		ray_new(t_tuple origin, t_tuple direction);
t_tuple		position(t_ray ray, float factor);
void        render(t_camera* camera, t_world* world);
t_ray		ray_for_pixel(t_camera cam, float x, float y);
bool		is_shadowed(t_world world, t_tuple point);


#endif
