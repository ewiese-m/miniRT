/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:37:48 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:28 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	matrix_invertible(t_matrix m)
{
	return (matrix_determinant(m) != 0);
}

t_matrix	matrix_inverse(t_matrix m)
{
	int			row;
	int			col;
	double		det;
	t_matrix	m2;

	if (!matrix_invertible(m))
		return (m);
	det = matrix_determinant(m);
	row = 0;
	while (row < m.size)
	{
		col = 0;
		while (col < m.size)
		{
			m2.matrix[col][row] = matrix_cofactor(m, row, col) / det;
			col++;
		}
		row++;
	}
	m2.size = m.size;
	return (m2);
}
