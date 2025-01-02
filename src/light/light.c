/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:46:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/02 20:10:50 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_light	point_light(t_tuple point, t_tuple intensity)
{
	return ((t_light){
		.position = point,
		.intensity = intensity
	});
}

t_tuple	lighting(t_material mat, t_light light, t_tuple eyev, t_tuple normalv, t_tuple point)
{
	t_tuple	e_color;
	t_tuple	lightv;
	t_tuple	ambient;
	t_tuple diffuse;
	t_tuple	specular;
	t_tuple reflectv;
	float	reflect_dot_eye;
	float	light_dot_normal;
	float	factor;

	e_color = color_hadamard(mat.color, light.intensity);
	lightv = tuple_normalize(tuple_substract(light.position, point));
	ambient = tuple_multiply(e_color, mat.ambient);
	light_dot_normal = tuple_dot(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = color_new(0, 0, 0);
		specular = color_new(0, 0, 0);
	}
	else
	{
		diffuse = tuple_multiply(tuple_multiply(e_color, mat.diffuse), light_dot_normal);
		reflectv = reflect(tuple_negate(lightv), normalv);
		reflect_dot_eye = tuple_dot(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = color_new(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, mat.shininess);
			specular = tuple_multiply(light.intensity, mat.specular);
			specular = tuple_multiply(specular, factor);
		}
	}
	return (tuple_add(tuple_add(ambient, diffuse), specular));
	
}
