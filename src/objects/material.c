/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:10:10 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/05 12:58:50 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_material	material(void)
{
	return ((t_material)
	{
		.pattern.exists = 0,
		.color = color_new(0.9, 0.9, 0.9),
		.ambient = 0.1,
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200,
		.roughness = 0.0,
		.metalic = 0.0,
		.reflective = 0.0,
		.transparency = 0.0,
		.refractive_index = 1.0,
		.emission_power = 0.0,
		.emission_color = black()
	});
}

t_material	emissive_material(void)
{
	return ((t_material)
	{
		.pattern.exists = 0,
		.color = color_new(0.8, 0.5, 0.2),
		.ambient = 0.1,
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200,
		.reflective = 0.0,
		.transparency = 0.0,
		.refractive_index = 1.0,
		.emission_power = 2.0,
		.emission_color = color_new(0.8, 0.5, 0.2)
	});
}
