/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:29:29 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/09 12:45:26 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

uint32_t	pixel_at(t_img *data, int dx, int dy)
{
	char	*dst;

	dst = data->addr + (dy * data->line_length + dx * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
