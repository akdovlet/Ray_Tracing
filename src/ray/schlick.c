/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schlick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:24:39 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/05 22:18:52 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	schlick(t_comps comps)
{
	double	cos_i;
	double	ratio;
	double	sin2_t;
	double	cos_t;
	double	n;

	cos_i = tuple_dot(comps.eyev, comps.normalv);
	if (comps.n1 > comps.n2)
	{
		ratio = comps.n1 / comps.n2;
		sin2_t = pow(ratio, 2.0) * (1.0 - pow(cos_i, 2.0));
		if (sin2_t > 1.0)
			return (1.0);
		cos_t = sqrt(1.0 - sin2_t);
		cos_i = cos_t; 		
	}
	n = pow((comps.n1 - comps.n2) / (comps.n1 + comps.n2), 2.0);
	return (n + (1.0 - n) * pow(1.0 - cos_i, 5));
}
