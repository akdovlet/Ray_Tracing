/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:12:29 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/19 11:16:50 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "matrix.h"

t_ray	ray_transform(t_ray ray, t_matrix m)
{
	return ((t_ray){
		.direction = transform(m, ray.direction),
		.origin = transform(m, ray.origin)
	});
}
