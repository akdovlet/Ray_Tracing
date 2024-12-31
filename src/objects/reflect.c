/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:13:01 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/31 18:57:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuple.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	float	dot_product;
	t_tuple	reflection;

	dot_product = tuple_dot(in, normal);
	reflection = tuple_multiply(normal, 2);
	reflection = tuple_multiply(reflection, dot_product);
	reflection = tuple_substract(in, reflection);
	return (reflection);
	// return (tuple_multiply(tuple_multiply(tuple_substract(in, normal), 2), tuple_dot(in, normal)));
	
	// return (reflection);
}
