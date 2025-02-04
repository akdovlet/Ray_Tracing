/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:28:04 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/04 14:40:49 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mouse_manager(int button, int x, int y, t_data *data)
{
	v2	mouse_pos;
	// v2	delta;

	mouse_pos[0] = x;
	mouse_pos[1] = y;
	// delta = (mouse_pos - data->cam.last_mouse_position) * 0.002;
	data->cam.last_mouse_position = mouse_pos;
	if (button != 1)
	{
		mlx_mouse_show(data->mlx.mlx_ptr, data->mlx.win_ptr);
		return (0);
	}
	mlx_mouse_hide(data->mlx.mlx_ptr, data->mlx.win_ptr);
	return (0);
}
