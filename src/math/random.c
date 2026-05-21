/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:15:37 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/13 17:51:28 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

uint32_t	pcg_hash(uint32_t seed)
{
	uint32_t	state;
	uint32_t	word;

	state = seed * 747796485u + 2891336453u;
	word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
	return ((word >> 22u) ^ word);
}

double	random_float(uint32_t *seed)
{
	*seed = pcg_hash(*seed);
	return ((double)*seed / (double)UINT32_MAX);
}

double	random_range(uint32_t *seed, double min, double max)
{
	return (random_float(seed) * (max - min) + min);
}

t_tuple	random_unit_vec(uint32_t *seed)
{
	t_tuple	v;
	double	lensq;

	while (1)
	{
		v = (t_tuple){random_float(seed) * 2.0 - 1.0,
			random_float(seed) * 2.0 - 1.0,
			random_float(seed) * 2.0 - 1.0, 0};
		lensq = tuple_dot(v, v);
		if (lensq > 1e-8 && lensq <= 1.0)
			return (tuple_multiply(v, 1.0 / sqrt(lensq)));
	}
}

t_tuple	random_vec_range(uint32_t *seed, double min, double max)
{
	return ((t_tuple){random_range(seed, min, max), random_range(seed, min,
			max), random_range(seed, min, max), 1});
}
