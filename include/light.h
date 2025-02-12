/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 19:47:37 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/11 18:52:14 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"

t_light	point_light(v4 point, v4 intensity);
v4	shade_hit(t_world *world, t_comps *comps, int depth);
v4	lighting(t_material mat, t_light light, v4 eyev, 
v4 normalv, v4 point);
// v4	blinn_phong(t_material mat, t_light light, v4 eyev,
// v4 normalv, v4 point);
// v4	blinn_phong(t_material mat, t_light light, v4 overz, v4 eyev, v4 normalv, bool shadowed);
// v4	blinn_phong(t_material mat, t_light light, v4 overz, v4 eyev, v4 normalv, bool shadowed, t_shape shape);
v4	blinn_phong(t_light light, t_shape *shape, t_comps *c, bool shadowed);


