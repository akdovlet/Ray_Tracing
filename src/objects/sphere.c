/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:09:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/06 14:02:05 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	sphere(t_tuple point, float radius)
{
	t_object	new;

	new = (t_object){
		.coordinates = point,
		.radius = radius,
		.id = (uintptr_t) &new,
		.type = SPHERE,
		.transform = identity()
	};
	return (new);
}

t_object	sphere_default(void)
{
	t_object	new;

	new = (t_object){
		.coordinates = point_new(0, 0, 0),
		.radius = 1,
		.id = (uintptr_t) &new,
		.type = SPHERE,
		.transform = identity()
	};
	return (new);
}

void	set_transform(t_object *obj, t_matrix m)
{
	obj->transform = m;
}
