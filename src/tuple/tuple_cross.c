/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_cross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:36:01 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/17 17:46:24 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	tuple_cross(t_tuple a, t_tuple b)
{
	t_tuple	new;

	new.x = (a.y * b.z) - (a.z * b.y);
	new.y = (a.z * b.x) - (a.x * b.z);
	new.z = (a.x * b.y) - (a.y * b.x);
	return (new);
}
