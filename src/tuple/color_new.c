/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:15:41 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/15 14:09:10 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	color_new(double red, double green, double blue)
{
	t_tuple	new;

	new.x = red;
	new.y = green;
	new.z = blue;
	new.w = 0;
	return (new);
}
