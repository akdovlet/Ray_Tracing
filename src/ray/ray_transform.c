/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:12:29 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/30 12:13:46 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "matrix.h"

t_ray	ray_transform(t_ray ray, t_matrix m)
{
	return ((t_ray)
	{
		.direction = transform(ray.direction, m),
		.origin = transform(ray.origin, m)
	});
}
