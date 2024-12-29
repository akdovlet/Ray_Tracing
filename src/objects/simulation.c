/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:01:46 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/29 10:09:03 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_projectile
{
	t_tuple	position;
	t_tuple	velocity;
}	t_proj;

typedef struct s_env
{
	t_tuple	gravity;
	t_tuple	wind;
}	t_env;

t_proj	tick(t_env env, t_proj proj)
{
	proj.position = tuple_add(proj.position, proj.velocity);
	proj.velocity = tuple_add(proj.velocity, env.gravity);
	proj.velocity = tuple_add(proj.velocity, env.wind);
	return (proj);
}

