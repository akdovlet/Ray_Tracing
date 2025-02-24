/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/24 19:38:23 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_manager(int keysym, t_data *data)
{
	t_tuple	left;
	t_tuple	forward;
	t_tuple	up;
	
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
		data->cam.from = tuple_add(data->cam.from, tuple_multiply(forward, 5.0 * data->ts));
		data->moved = true;
	}
	else if (keysym == XK_s)
	{
		data->cam.from = tuple_substract(data->cam.from, tuple_multiply(forward, 5.0 * data->ts));
		data->moved = true;
	}
	if (keysym == XK_a)
	{
		data->cam.from = tuple_add(data->cam.from, tuple_multiply(left, 5.0 * data->ts));
		data->moved = true;
		
	}
	else if (keysym == XK_d)
	{
		data->cam.from = tuple_substract(data->cam.from, tuple_multiply(left, 5.0 * data->ts));
		data->moved = true;
	}
	if (keysym == XK_q)
	{
		data->cam.from = tuple_substract(data->cam.from, tuple_multiply(up, 5.0 * data->ts));
		data->moved = true;
		
	}
	else if (keysym == XK_e)
	{
		data->cam.from = tuple_add(data->cam.from, tuple_multiply(up, 5.0 * data->ts));
		data->moved = true;
	}
	if (keysym == XK_Left)
	{
		data->cam.to = tuple_add(data->cam.to, tuple_multiply(left, 5.0 * data->ts));
		data->moved = true;
		
	}
	else if (keysym == XK_Right)
	{
		data->cam.to = tuple_substract(data->cam.to, tuple_multiply(left, 5.0 * data->ts));
		data->moved = true;
	}
	if (keysym == XK_Up)
	{
		data->cam.to = tuple_add(data->cam.to, tuple_multiply(up, 5.0 * data->ts));
		data->moved = true;
		
	}
	else if (keysym == XK_Down)
	{
		data->cam.to = tuple_substract(data->cam.to, tuple_multiply(up, 5.0 * data->ts));
		data->moved = true;
	}
	camera_update_transform(&data->cam, data->cam.from,
			data->cam.to,
			data->cam.up);
	return (0);
}

