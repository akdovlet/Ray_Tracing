/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:12:29 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 18:10:19 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "matrix.h"

t_ray	ray_transform(t_ray ray, t_matrix m)
{
	return ((t_ray){
		.direction = transform(ray.direction, m),
		.origin = transform(ray.origin, m)
	});
}
