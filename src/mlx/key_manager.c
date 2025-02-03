/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/03 21:44:20 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_manager(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx.mlx_ptr);
		return (1);
	}
	else if (keysym == XK_d)
	{
		data->cam.roll += 1;		
	}
	else if (keysym == XK_a)
		data->cam.to = tuple_add(data->cam.to, vector_new(1, 0, 0));
	else if (keysym == XK_w)
		data->cam.from = tuple_divide(data->cam.from, 1.1);
	else if (keysym == XK_s)
		data->cam.from = tuple_multiply(data->cam.from, 1.1);
	else
		return (0);
		
	data->cam.to = matrix_multiply_tuple(rotate_z(radians(data->cam.roll)), data->cam.to);
	render_and_move(data);
	return (0);
}
