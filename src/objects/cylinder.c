/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:00:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/30 12:09:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	cylinder_default(void)
{
	return ((t_shape){
		.coordinates = point_new(0, 0, 0),
		.id = new_id(),
		.local_interesct = &
	})
}
