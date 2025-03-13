/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:14 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 17:58:22 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_tuple	tuple_multiply(t_tuple a, double factor)
{
	return ((t_tuple){
		a.x * factor,
		a.y * factor,
		a.z * factor,
		a.w * factor
	});
}

inline t_tuple	tuple_divide(t_tuple a, double divisor)
{
	return ((t_tuple){
		a.x / divisor,
		a.y / divisor,
		a.z / divisor,
		a.w / divisor
	});
}
