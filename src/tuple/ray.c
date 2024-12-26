/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:42:55 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/26 15:44:39 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	position(t_tuple point, t_tuple direction, float factor)
{
	return (tuple_add(point, tuple_multiply(direction, factor)));
}
