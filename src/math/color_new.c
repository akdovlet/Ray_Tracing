/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:15:41 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/03 18:55:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_tuple	color_new(double red, double green, double blue)
{
	return ((t_tuple){red, green, blue, 0});
}
