/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:32 by akdovlet          #+#    #+#             */
/*   Updated: 2024/12/20 12:05:04 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//	frees a 4x4 float array
void	*matrix_free(float **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(matrix[i++]);
	free(matrix);
	return (NULL);
}

//	allocates a 4x4 float array
float	**matrix_init(int row, int column)
{
	float	**mfour;
	int		i;

	i = 0;
	mfour = malloc(sizeof(float *) * row);
	if (!mfour)
		return (NULL);
	while (i < row)
	{
		mfour[i] = malloc(sizeof(float) * column);
		if (!mfour[i])
			return (matrix_free(mfour, i));
		i++;
	}
	return (mfour);
}

/* allocates a 4x4 float array filled with tuple data*/
float	**matrix_four_by_four(t_tuple t1, t_tuple t2, t_tuple t3, t_tuple t4)
{
	float	**mfour;

	mfour = matrix_init(4, 4);
	if (!mfour)
		return (NULL);
	mfour[0][0] = t1.x;
	mfour[0][1] = t1.y;
	mfour[0][2] = t1.z;
	mfour[0][3] = t1.w;
	mfour[1][0] = t2.x;
	mfour[1][1] = t2.y;
	mfour[1][2] = t2.z;
	mfour[1][3] = t2.w;
	mfour[2][0] = t3.x;
	mfour[2][1] = t3.y;
	mfour[2][2] = t3.z;
	mfour[2][3] = t3.w;
	mfour[3][0] = t4.x;
	mfour[3][1] = t4.y;
	mfour[3][2] = t4.z;
	mfour[3][3] = t4.w;
	return (mfour);
}

float	**matrix_three_by_three(t_tuple t1, t_tuple t2, t_tuple t3)
{
	int		i;
	float	**mthree;

	i = 0;
	mthree = matrix_init(3, 3);
	if (!mthree)
		return (NULL);
	mthree[0][0] = t1.x;
	mthree[0][1] = t1.y;
	mthree[0][2] = t1.z;
	mthree[1][0] = t2.x;
	mthree[1][1] = t2.y;
	mthree[1][2] = t2.z;
	mthree[2][0] = t3.x;
	mthree[2][1] = t3.y;
	mthree[2][2] = t3.z;
	return (mthree);
}

float	**matrix_two_by_two(t_tuple t1, t_tuple t2)
{
	int		i;
	float	**mtwo;

	i = 0;
	mtwo = matrix_init(2, 2);
	if (!mtwo)
		return (NULL);
	mtwo[0][0] = t1.x;
	mtwo[0][1] = t1.y;
	mtwo[1][0] = t2.x;
	mtwo[1][1] = t2.y;
	return (mtwo);
}
