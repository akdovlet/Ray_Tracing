/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hadamard_product.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:51:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/03 18:56:36 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

inline t_tuple	color_hadamard(t_tuple c1, t_tuple c2)
{
	return ((t_tuple){
		c1.x * c2.x,
		c1.y * c2.y,
		c1.z * c2.z,
		0
	});
}
