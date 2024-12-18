/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:15:30 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/17 18:00:11 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	tuple_new(float x, float y, float z, float w)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = w;
	return (new);
}

t_tuple	vector_new(float x, float y, float z)
{
	return (tuple_new(x, y, z, 0));
}

t_tuple	point_new(float x, float y, float z)
{
	return (tuple_new(x, y, z, 1));
}

