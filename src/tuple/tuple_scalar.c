/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:14 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 19:51:02 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline v4	tuple_multiply(v4 a, double factor)
{
	return (a * factor);
}

inline v4	tuple_divide(v4 a, double divisor)
{
	return (a / divisor);
}

