/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/22 17:07:38 by akdovlet         ###   ########.fr       */
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
		data->cam.from.x += 0.1;
	else if (keysym == XK_a)
		data->cam.from.x -= 0.1;
	else if (keysym == XK_w)
		data->cam.from.y += 0.1;
	else if (keysym == XK_s)
		data->cam.from.y -= 0.1;
	else
		return (0);
	render_and_move(data);
	return (0);
}
