/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:21:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/03/09 16:29:45 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_H
# define RANDOM_H

#include "data_struct.h"
#include <stdint.h>

uint32_t	pcg_hash(uint32_t seed);
double		random_float(uint32_t *seed);
t_tuple		random_unit_vec(uint32_t *seed);
double		random_range(uint32_t *seed, double min, double max);

#endif
