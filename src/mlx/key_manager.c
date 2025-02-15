/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/15 18:19:25 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_manager(int keysym, t_data *data)
{
	t_tuple	left;
	t_tuple	forward;
	t_tuple	up;
	bool	moved;
	
	moved = false;
	forward = tuple_normalize(tuple_substract(data->cam.to, data->cam.from));
	left = tuple_cross(forward, tuple_normalize(data->cam.up));
	up = tuple_cross(left, forward);
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx.mlx_ptr);
		return (1);
	}
	if (keysym == XK_w)
	{
		data->cam.from = tuple_add(data->cam.from, forward);
		data->cam.from.w = 1;
		moved = true;
	}
	else if (keysym == XK_s)
	{
		data->cam.from = tuple_substract(data->cam.from, forward);
		data->cam.from.w = 1;
		moved = true;
	}
	if (keysym == XK_a)
	{
		data->cam.from = tuple_add(data->cam.from, left);
		data->cam.from.w = 1;
		moved = true;
		
	}
	else if (keysym == XK_d)
	{
		data->cam.from = tuple_substract(data->cam.from, left);
		data->cam.from.w = 1;
		moved = true;
	}
	if (keysym == XK_q)
	{
		data->cam.from = tuple_substract(data->cam.from, up);
		data->cam.from.w = 1;
		moved = true;
		
	}
	else if (keysym == XK_e)
	{
		data->cam.from = tuple_add(data->cam.from, up);
		data->cam.from.w = 1;
		moved = true;
	}
	if (keysym == XK_Left)
	{
		data->cam.to = tuple_add(data->cam.to, left);
		data->cam.to.w = 1;
		moved = true;
		
	}
	else if (keysym == XK_Right)
	{
		data->cam.to = tuple_substract(data->cam.to, left);
		data->cam.to.w = 1;
		moved = true;
	}
	if (keysym == XK_Up)
	{
		data->cam.to = tuple_add(data->cam.to, up);
		data->cam.to.w = 1;
		moved = true;
		
	}
	else if (keysym == XK_Down)
	{
		data->cam.to = tuple_substract(data->cam.to, up);
		data->cam.to.w = 1;
		moved = true;
	}
	if (moved)
		render_and_move(data);
	return (0);
}

