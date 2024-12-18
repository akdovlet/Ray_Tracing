/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:32 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/18 18:59:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mfour	matrix_four_by_four(t_tuple t1, t_tuple t2, t_tuple t3, t_tuple t4)
{
	t_mfour	new;

	new.t1 = t1;
	new.t2 = t2;
	new.t3 = t3;
	new.t4 = t4;
	return (new);
}

t_mthree	matrix_three_by_three(t_tuple t1, t_tuple t2, t_tuple t3)
{
	t_mthree	new;

	new.t1 = t1;
	new.t2 = t2;
	new.t3 = t3;
	return (new);
}

t_mtwo	matrix_two_by_two(t_tuple t1, t_tuple t2)
{
	t_mtwo	new;

	new.t1 = t1;
	new.t2 = t2;
	return (new);
}
