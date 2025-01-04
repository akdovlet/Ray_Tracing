/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:46:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/04 10:45:12 by akdovlet         ###   ########.fr       */
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
	t_tuple tmp;
	t_tuple	halfway;
	float	reflect_dot_eye;
	float	light_dot_normal;
	float	factor;
	float	energy_conservation;

	e_color = color_hadamard(mat.color, light.intensity);
	lightv = tuple_normalize(tuple_substract(light.position, point));
	ambient = tuple_multiply(e_color, mat.ambient);
	light_dot_normal = tuple_dot(lightv, normalv);
	halfway = tuple_normalize(tuple_add(lightv, eyev));
	energy_conservation = (8.0 + 16.0) / (8.0 * M_PI);
	factor = powf(fmax(tuple_dot(normalv, halfway), 0.0), mat.shininess);
	factor = energy_conservation * factor;
	if (light_dot_normal < 0)
	{
		diffuse = color_new(0, 0, 0);
		specular = color_new(0, 0, 0);
	}
	else
	{
		tmp = tuple_multiply(e_color, mat.diffuse);
		diffuse = tuple_multiply(tmp, light_dot_normal);
		reflectv = reflect(tuple_negate(lightv), normalv);
		reflect_dot_eye = tuple_dot(reflectv, eyev);
		// printf("reflect_dot_eye is: %f\n", reflect_dot_eye);
		if (reflect_dot_eye <= 0.0f)
			specular = color_new(0, 0, 0);
		else
		{
			// printf("reflect.eye is: %f and mat.shininess is: %f\n", reflect_dot_eye, mat.shininess);
			// if (reflect_dot_eye >=1)
			// 	printf("factor is: %f\n", factor);
			specular = tuple_multiply(light.intensity, mat.specular);
			specular = tuple_multiply(specular, reflect_dot_eye);
			specular = tuple_multiply(specular, factor);
		}
	}
	return (tuple_add(tuple_add(diffuse, ambient), specular));
}
