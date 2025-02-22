/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_cross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:36:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/03 18:54:23 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_tuple	tuple_cross(t_tuple a, t_tuple b)
{
	return ((t_tuple){
					.x = (a.y * b.z) - (a.z * b.y),
					.y = (a.z * b.x) - (a.x * b.z),
					.z = (a.x * b.y) - (a.y * b.x)
	});
}
