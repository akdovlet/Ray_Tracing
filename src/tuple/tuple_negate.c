/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_negate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:05:30 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/16 18:07:30 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	tuple_negate(t_tuple a)
{
	t_tuple	new;

	new.x = -a.x;
	new.y = -a.y;
	new.z = -a.z;
	new.w = -a.w;
	return (new);
}
