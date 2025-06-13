/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:42:21 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:38 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_matrix_copy(t_matrix *dst, t_matrix *src)
{
	int	i;
	int	j;

	i = 0;
	while (i < MATRIX)
	{
		j = 0;
		while (j < MATRIX)
		{
			dst->matrix[i][j] = src->matrix[i][j];
			j++;
		}
		i++;
	}
}

void	matrix_transform(t_matrix *matrix, t_matrix *transform)
{
	t_matrix	*tmp;

	tmp = matrix_mult(*matrix, *transform);
	ft_matrix_copy(matrix, tmp);
	free(tmp);
}
