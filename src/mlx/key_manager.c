/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/04 17:02:13 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_manager(int keysym, t_data *data)
{
	t_tuple	rightv;
	bool	moved;
	
	moved = false;
	rightv = tuple_cross(data->cam.to, data->cam.up);
	rightv.w = 0;
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx.mlx_ptr);
		return (1);
	}
	if (keysym == XK_w)
	{
		data->cam.from = tuple_add(data->cam.from, data->cam.to);
		data->cam.from.w = 1;
		moved = true;
	}
	else if (keysym == XK_s)
	{
		data->cam.from = tuple_substract(data->cam.from, data->cam.to);
		data->cam.from.w = 1;
		moved = true;
	}
	if (keysym == XK_a)
	{
		data->cam.from = tuple_add(data->cam.from, rightv);
		data->cam.from.w = 1;
		moved = true;
		
	}
	else if (keysym == XK_d)
	{
		data->cam.from = tuple_substract(data->cam.from, rightv);
		data->cam.from.w = 1;
		moved = true;
	}
	if (moved)
		render_and_move(data);
	return (0);
}

