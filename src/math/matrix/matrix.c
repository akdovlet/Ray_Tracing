/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/19 11:17:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_matrix	compose(size_t operation_count, t_matrix *ops)
{
	int			index;
	t_matrix	result;

	index = operation_count;
	result = identity();
	while (index)
	{
		result = multiply_matrix(result, ops[index]);
		index -= 1;
	}
	return (result);
}
