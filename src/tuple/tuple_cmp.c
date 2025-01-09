/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:48:59 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/09 18:34:54 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	float_equal(float a, float b)
{
	if (fabs(a - b) < __FLT_MIN__)
		return (0);
	return (1);
}

int	tuple_cmp(t_tuple a, t_tuple b)
{
	t_tuple tmp = a - b;
	
	return (1 
		&& fabs(tmp[0]) > __FLT_MIN__
		&& fabs(tmp[1]) > __FLT_MIN__
		&& fabs(tmp[2]) > __FLT_MIN__
		&& fabs(tmp[3]) > __FLT_MIN__
	);
}
