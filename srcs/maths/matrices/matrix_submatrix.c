/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:48:47 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:20:30 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_matrix	matrix_submatrix(t_matrix m, int row, int col)
{
	int			i;
	int			j;
	t_matrix	m2;

	i = 0;
	m2.size = m.size - 1;
	while (i < m2.size)
	{
		j = 0;
		while (j < m2.size)
		{
			m2.matrix[i][j] = m.matrix[i + (i >= row)][j + (j >= col)];
			j++;
		}
		i++;
	}
	return (m2);
}
