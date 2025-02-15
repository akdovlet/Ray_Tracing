/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:15:37 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/15 20:29:06 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

uint32_t	pcg_hash(uint32_t seed)
{
	uint32_t	state;
	uint32_t	word;

	state = seed * 747796485u + 2891336453u;
	word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
	return (word >> 22u) ^ word;
}

double	random_float(uint32_t *seed)
{
	*seed = pcg_hash(*seed);
	return ((double)*seed / (double)UINT32_MAX);
}

t_tuple	random_unit_vec(uint32_t *seed)
{
	return ((t_tuple){
		(double)random_float(seed) * 2.0 - 1.0,
		(double)random_float(seed) * 2.0 - 1.0,
		(double)random_float(seed) * 2.0 - 1.0,
		0
	});
}
