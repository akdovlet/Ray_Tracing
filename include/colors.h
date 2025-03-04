/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:45:25 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/15 20:32:57 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "data_struct.h"

t_tuple	black(void);
t_tuple	white(void);
t_tuple	red(void);
t_tuple	blue(void);
t_tuple	green(void);

t_tuple	get_emission(t_shape *obj);

#endif
