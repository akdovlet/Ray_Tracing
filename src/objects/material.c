/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:10:10 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/04 14:38:28 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_material	material(void)
{
	return ((t_material)
	{
		.color = color_new(1, 1, 1),
		.ambient = 0.1,
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200
	});
}
