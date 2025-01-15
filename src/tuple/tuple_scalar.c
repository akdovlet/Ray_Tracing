/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:14 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/15 14:09:10 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	tuple_multiply(t_tuple a, double factor)
{
	t_tuple	new;

	new.x = a.x * factor;
	new.y = a.y * factor;
	new.z = a.z * factor;
	new.w = a.w * factor;
	return (new);
}

t_tuple	tuple_divide(t_tuple a, double divisor)
{
	t_tuple	new;

	new.x = a.x / divisor;
	new.y = a.y / divisor;
	new.z = a.z / divisor;
	new.w = a.w / divisor;
	return (new);
}
