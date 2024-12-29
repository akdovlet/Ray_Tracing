/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:23:06 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/29 10:23:30 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include "data_struct.h"

t_tuple		color_new(float red, float green, float blue);
t_tuple		color_hadamard(t_tuple c1, t_tuple c2);

#endif
