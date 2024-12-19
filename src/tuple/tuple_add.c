/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:57:20 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/19 15:24:27 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	tuple_add(t_tuple a, t_tuple b)
{
	t_tuple	new;

	new.x = a.x + b.x;
	new.y = a.y + b.y;
	new.z = a.z + b.z;
	new.w = a.w + b.w;
	return (new);
}
