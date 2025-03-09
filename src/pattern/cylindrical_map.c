/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindrical_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:14:25 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/08 11:17:29 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec2f	cylindrical_map(t_tuple p)
{
	double	theta;
	double	raw_u;
	double	u;
	double	v;

	theta = atan2(p.x, p.z);
	raw_u = theta / (2.0 * M_PI);
	u = 1.0 - (raw_u + 0.5);
	v = fmod(p.y, 1.0);
	return ((t_vec2f){u, v});
}
