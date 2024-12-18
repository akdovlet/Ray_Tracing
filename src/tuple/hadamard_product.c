/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hadamard_product.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:51:36 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/18 09:53:46 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	color_hadamard(t_tuple c1, t_tuple c2)
{
	t_tuple new;

	new.x = c1.x * c2.x;
	new.y = c1.y * c2.y;
	new.z = c1.z * c2.z;
	return (new);
}
