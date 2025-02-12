/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:15:30 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 18:52:14 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

v4	tuple_new(double x, double y, double z, double w)
{
	return ((v4){x, y, z, w});
}

inline v4	vector_new(double x, double y, double z)
{
	return ((v4){x, y, z, 0});
}

inline v4	point_new(double x, double y, double z)
{
	return ((v4){x, y, z, 1});
}
