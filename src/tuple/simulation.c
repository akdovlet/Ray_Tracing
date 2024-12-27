/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:01:46 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/27 12:22:14 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_proj	tick(t_env env, t_proj proj)
{
	proj.position = tuple_add(proj.position, proj.velocity);
	proj.velocity = tuple_add(proj.velocity, env.gravity);
	proj.velocity = tuple_add(proj.velocity, env.wind);
	return (proj);
}
