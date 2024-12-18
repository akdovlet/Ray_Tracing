/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:57:57 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/18 17:06:36 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_manager(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		mlx_loop_end(mlx->mlx_ptr);
	return (0);
}
