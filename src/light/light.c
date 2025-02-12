/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:46:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/12 18:50:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_light	point_light(v4 point, v4 intensity)
{
	return ((t_light){
		.position = point,
		.intensity = intensity
	});
}

// v4	brdf(t_light light, t_shape *shape, t_comps *comps, bool shadowed)
// {
// 	v4	light;
// 	v4	contribution;
// 	v4	lightv;
// 	v4	ambient;
// 	v4 diffuse;
// 	v4	specular;
// 	v4 reflectv;
// 	v4 tmp;
// 	v4	halfway;
// 	double	reflect_dot_eye;
// 	double	light_dot_normal;
// 	double	factor;
	
// 	if (shape->matter.pattern.exists)
// 		contribution = pattern_at_shape(shape->matter.pattern, *shape, comps->overz);
// 	else
// 		contribution = color_hadamard(shape->matter.color, light.intensity);
// 	lightv = v4_normalize(tuple_substract(light.position, comps->overz));
// 	ambient = tuple_multiply(contribution, shape->matter.ambient);
// 	if (shadowed)
// 		return (ambient);
// 	light_dot_normal = fmax(tuple_dot(lightv, comps->normalv), 0.0);
// 	halfway = v4_normalize(tuple_add(lightv, v4_normalize(comps->eyev)));
// 	factor = pow(fmax(tuple_dot(comps->normalv, halfway), 0.0), shape->matter.shininess);
// 	tmp = tuple_multiply(contribution, shape->matter.diffuse);
// 	diffuse = tuple_multiply(tmp, light_dot_normal);
// 	reflectv = reflect(tuple_negate(lightv), comps->normalv);
// 	reflect_dot_eye = fmax(tuple_dot(reflectv, comps->eyev), 0.0);
// 	specular = tuple_multiply(light.intensity, shape->matter.specular);
// 	specular = tuple_multiply(specular, reflect_dot_eye);
// 	specular = tuple_multiply(specular, factor);
// 	return (tuple_add(tuple_add(diffuse, ambient), specular));
// }

v4	blinn_phong(t_light light, t_shape *shape, t_comps *comps, bool shadowed)
{
	v4	e_color;
	v4	lightv;
	v4	ambient;
	v4 diffuse;
	v4	specular;
	v4 reflectv;
	v4 tmp;
	v4	halfway;
	double	reflect_dot_eye;
	double	light_dot_normal;
	double	factor;
	
	if (shape->matter.pattern.exists)
	{
		e_color = pattern_at_shape(shape->matter.pattern, *shape, comps->overz);
		e_color *= shape->matter.color * light.intensity;
	}
	else
		e_color = shape->matter.color * light.intensity;
	lightv = v4_normalize(light.position - comps->overz);
	ambient = e_color * shape->matter.ambient;
	if (shadowed)
		return (ambient);
	light_dot_normal = fmax(tuple_dot(lightv, comps->normalv), 0.0);
	halfway = v4_normalize(lightv + v4_normalize(comps->eyev));
	factor = pow(fmax(tuple_dot(comps->normalv, halfway), 0.0), shape->matter.shininess);
	tmp = e_color * shape->matter.diffuse;
	diffuse = tmp * light_dot_normal;
	reflectv = reflect(-lightv, comps->normalv);
	reflect_dot_eye = fmax(tuple_dot(reflectv, comps->eyev), 0.0);
	specular = light.intensity * shape->matter.specular;
	specular = specular * reflect_dot_eye;
	specular = specular * factor;
	return (diffuse + ambient + specular);
}

v4	blinn_phong_old(t_material mat, t_light light, v4 overz, v4 eyev, v4 normalv, bool shadowed, t_shape shape)
{
	v4	e_color;
	v4	lightv;
	v4	ambient;
	v4 diffuse;
	v4	specular;
	v4 reflectv;
	v4 tmp;
	v4	halfway;
	double	reflect_dot_eye;
	double	light_dot_normal;
	double	factor;
	
	if (mat.pattern.exists)
	{
		e_color = pattern_at_shape(mat.pattern, shape, overz);
		e_color = color_hadamard(e_color, color_hadamard(mat.color, light.intensity));
	}
	else
		e_color = color_hadamard(mat.color, light.intensity);
	lightv = v4_normalize(tuple_substract(light.position, overz));
	ambient = tuple_multiply(e_color, mat.ambient);
	if (shadowed)
		return (ambient);
	light_dot_normal = fmax(tuple_dot(lightv, normalv), 0.0);
	halfway = v4_normalize(tuple_add(lightv, v4_normalize(eyev)));
	factor = pow(fmax(tuple_dot(normalv, halfway), 0.0), mat.shininess);
	tmp = tuple_multiply(e_color, mat.diffuse);
	diffuse = tuple_multiply(tmp, light_dot_normal);
	reflectv = reflect(tuple_negate(lightv), normalv);
	reflect_dot_eye = fmax(tuple_dot(reflectv, eyev), 0.0);
	if (reflect_dot_eye > 0)
	{
		specular = tuple_multiply(light.intensity, mat.specular);
		specular = tuple_multiply(specular, reflect_dot_eye);
		specular = tuple_multiply(specular, factor);
	}
	else
		specular = color_new(0, 0, 0);
	return (tuple_add(tuple_add(diffuse, ambient), specular));
}

v4	lighting(t_material mat, t_light light, v4 eyev, v4 normalv, v4 point)
{
	v4	e_color;
	v4	lightv;
	v4	ambient;
	v4 diffuse;
	v4	specular;
	v4 reflectv;

	double	reflect_dot_eye;
	double	light_dot_normal;
	double	factor;

	e_color = color_hadamard(mat.color, light.intensity);
	lightv = v4_normalize(tuple_substract(light.position, point));
	ambient = tuple_multiply(e_color, mat.ambient);
	light_dot_normal = tuple_dot(lightv, normalv);
	if (light_dot_normal < 0.0)
	{
		diffuse = color_new(0, 0, 0);
		specular = color_new(0, 0, 0);
	}
	else
	{
		diffuse = tuple_multiply(tuple_multiply(e_color, mat.diffuse), light_dot_normal);
		reflectv = reflect(tuple_negate(lightv), normalv);
		reflect_dot_eye = tuple_dot(reflectv, eyev);
		if (reflect_dot_eye <= 0.0)
			specular = color_new(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, mat.shininess);
			specular = tuple_multiply(tuple_multiply(light.intensity, mat.specular), factor);
		}
	}
	return (tuple_add(tuple_add(diffuse, ambient), specular));
}
