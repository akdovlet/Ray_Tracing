/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:58:03 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/10 20:30:36 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "data_struct.h"

t_pattern	stripe_pattern(t_tuple c1, t_tuple c2);
void		set_transform_pattern(t_pattern *pattern, t_matrix m);
t_tuple		pattern_at_shape(t_pattern pattern, t_shape shape, t_tuple world_point);
t_pattern	gradient_pattern(t_tuple c1, t_tuple c2);

#endif
