/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 22:44:39 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:28 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	*matrix_mult(t_matrix m1, t_matrix m2)
{
	int			i;
	int			j;
	t_matrix	*matrix_return;

	matrix_return = malloc(sizeof(t_matrix));
	if (!matrix_return)
		return (NULL);
	i = 0;
	while (i < MATRIX)
	{
		j = 0;
		while (j < MATRIX)
		{
			matrix_return->matrix[i][j] = m1.matrix[i][0] * m2.matrix[0][j]
				+ m1.matrix[i][1] * m2.matrix[1][j]
				+ m1.matrix[i][2] * m2.matrix[2][j]
				+ m1.matrix[i][3] * m2.matrix[3][j];
			j++;
		}
		i++;
	}
	matrix_return->size = m1.size;
	return (matrix_return);
}

t_tuple	matrix_tuple_mult(t_matrix m, t_tuple t)
{
	int		i;
	double	result[MATRIX];

	i = 0;
	while (i < MATRIX)
	{
		result[i] = m.matrix[i][0] * t.x
			+ m.matrix[i][1] * t.y
			+ m.matrix[i][2] * t.z
			+ m.matrix[i][3] * t.w;
		i++;
	}
	return (tuple_new(result[0], result[1], result[2], result[3]));
}
