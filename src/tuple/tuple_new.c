/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:15:30 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/03 18:44:08 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	tuple_new(double x, double y, double z, double w)
{
	return ((t_tuple){x, y, z, w});
}

inline t_tuple	vector_new(double x, double y, double z)
{
	return ((t_tuple){x, y, z, 0});
}

inline t_tuple	point_new(double x, double y, double z)
{
	return ((t_tuple){x, y, z, 1});
}
