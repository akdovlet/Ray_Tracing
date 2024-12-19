/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:33:23 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/19 12:02:03 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	matrix_cmp_4(t_mfour m1, t_mfour m2)
{
	if (tuple_cmp(m1.t1, m2.t1))
		return (1);
	if (tuple_cmp(m1.t2, m2.t2))
		return (1);
	if (tuple_cmp(m1.t3, m2.t3))
		return (1);
	if (tuple_cmp(m1.t4, m2.t4))
		return (1);
	return (0);
}
