/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:58:03 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/08 18:59:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "data_struct.h"

t_pattern	stripe_pattern(t_tuple c1, t_tuple c2);
t_tuple		stripe_at(t_pattern pattern, t_tuple point);

#endif
