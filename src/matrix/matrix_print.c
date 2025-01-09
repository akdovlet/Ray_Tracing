/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:09:37 by akdovlet          #+#    #+#             */
/*   Updated: 2025/01/09 17:57:40 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	print_matrix(float m[4][4])
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < 4)
// 	{
// 		j = -1;
// 		while (++j < 4)
// 			fprintf(stderr, "%f\t", m[i][j]);
// 		fprintf(stderr, "\n");
// 	}
// }

void	print_matrix(float m[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			fprintf(stderr, "%f\t", m[i][j]);
		fprintf(stderr, "\n");
	}
}

