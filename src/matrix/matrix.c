/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:32 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/25 18:40:22 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrice compose(size_t operation_count, t_matrice* ops)
{
	int index;
	t_matrice result;

	index = operation_count - 1;
	result = ops[index];
	while(--index)
		result = multiply(result, ops[index]);
	return result;
}

t_tuple transform(t_tuple t1, t_matrice m)
{
	return matrix_multiply_tuple(m, t1);
}
