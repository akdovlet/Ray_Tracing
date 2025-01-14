/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/14 18:25:51 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_manager(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx.mlx_ptr);
		return (0);
	}
	if (keysym == XK_d)
		data->cam.from.x += 0.1;
	if (keysym == XK_a)
		data->cam.from.x -= 0.1;
	if (keysym == XK_w)
		data->cam.from.y += 0.1;
	if (keysym == XK_s)
		data->cam.from.y -= 0.1;
	render_and_move(data);
	return (0);
}
