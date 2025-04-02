/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:46:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/04/02 22:08:06 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_light	point_light(t_tuple point, t_tuple intensity)
{
	return ((t_light){.position = point, .intensity = intensity});
}

t_tuple	diffuse_light(t_tuple lv, t_tuple nv, t_tuple e_color, double diff)
{
	double	light_dot_normal;
	t_tuple	diffuse;

	light_dot_normal = fmax(tuple_dot(lv, nv), 0.0);
	diffuse = tuple_multiply(tuple_multiply(e_color, diff), light_dot_normal);
	return (diffuse);
}

t_tuple	specular_light(t_tuple lv, t_comps *c, t_light *l, t_shape *shape)
{
	t_tuple	specular;
	t_tuple	halfway;
	double	reflect_dot_eye;
	double	factor;

	halfway = tuple_normalize(tuple_add(lv, tuple_normalize(c->eyev)));
	factor = pow(fmax(tuple_dot(c->normalv, halfway), 0.0),
			shape->matter.shininess);
	reflect_dot_eye = fmax(tuple_dot(reflect(tuple_negate(lv), c->normalv),
				c->eyev), 0.0);
	specular = tuple_multiply(l->intensity, shape->matter.specular);
	specular = tuple_multiply(specular, reflect_dot_eye);
	specular = tuple_multiply(specular, factor);
	return (specular);
}

t_tuple	effective_color(t_shape *shape, t_comps *comps, t_light *light)
{
	t_tuple	e_color;

	if (shape->matter.pattern.exists)
	{
		e_color = pattern_at_shape(&shape->matter.pattern, shape, comps->overz);
		e_color = color_hadamard(e_color, color_hadamard(shape->color,
					light->intensity));
	}
	else
		e_color = color_hadamard(shape->color, light->intensity);
	return (e_color);
}

t_tuple	blinn_phong(t_light light, t_shape *shape, t_comps *comps, bool shad)
{
	t_tuple	e_color;
	t_tuple	lightv;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;

	e_color = effective_color(shape, comps, &light);
	lightv = tuple_normalize(tuple_substract(light.position, comps->overz));
	ambient = tuple_multiply(e_color, shape->matter.ambient);
	if (shad)
		return (ambient);
	diffuse = diffuse_light(lightv, comps->normalv, e_color,
			shape->matter.diffuse);
	specular = specular_light(lightv, comps, &light, shape);
	return (tuple_add(tuple_add(diffuse, ambient), specular));
}
