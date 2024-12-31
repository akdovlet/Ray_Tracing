/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:45:49 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/31 18:50:24 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	tuple_normalize(t_tuple a)
{
	t_tuple	new;
	float	magnitude;

	magnitude = tuple_magnitude(a);
	new.x = a.x / magnitude;
	new.y = a.y / magnitude;
	new.z = a.z / magnitude;
	new.w = a.w / magnitude;
	return (new);
}
