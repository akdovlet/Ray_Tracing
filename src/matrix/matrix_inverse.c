/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:00:05 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/27 13:19:29 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	inverse(t_matrix m, t_matrix *m2)
{
	int			i;
	int			j;
	float		deter;

	deter = determinant(m);
	fprintf(stderr, "deter is: %f\n", deter);
	if (!deter)
		return (1);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m2->raw[j][i] = cofactor(m, j, i) / deter;
			j++;
		}
		i++;
	}
	return (0);
}
