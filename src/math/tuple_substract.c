/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_substract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:14:49 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 17:58:34 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_tuple	tuple_substract(t_tuple a, t_tuple b)
{
	return ((t_tuple){
		.x = a.x - b.x,
		.y = a.y - b.y,
		.z = a.z - b.z,
		.w = a.w - b.w
	});
}
