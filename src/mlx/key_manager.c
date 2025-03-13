/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 17:10:02 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	controller_forward(int keysym, t_data *data)
{
	if (keysym == XK_w)
	{
		data->cam.from = tuple_add(data->cam.from, data->cam.forward);
		data->moved = true;
	}
	else if (keysym == XK_s)
	{
		data->cam.from = tuple_substract(data->cam.from, data->cam.forward);
		data->moved = true;
	}
	return (0);
}

int	controller_side(int keysym, t_data *data)
{
	if (keysym == XK_a)
	{
		data->cam.from = tuple_add(data->cam.from, data->cam.left);
		data->moved = true;
	}
	else if (keysym == XK_d)
	{
		data->cam.from = tuple_substract(data->cam.from, data->cam.left);
		data->moved = true;
	}
	return (0);
}

int	controller_up_down(int keysym, t_data *data)
{
	if (keysym == XK_q)
	{
		data->cam.from = tuple_substract(data->cam.from, data->cam.true_up);
		data->moved = true;
	}
	else if (keysym == XK_e)
	{
		data->cam.from = tuple_add(data->cam.from, data->cam.true_up);
		data->moved = true;
	}
	return (0);
}

int	key_manager(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx.mlx_ptr);
		return (1);
	}
	controller_forward(keysym, data);
	controller_side(keysym, data);
	controller_up_down(keysym, data);
	return (0);
}
