/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_emission.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:32:37 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 17:15:42 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	get_emission(t_shape *obj)
{
	return (tuple_multiply(obj->matter.emission_color, \
		obj->matter.emission_power));
}
