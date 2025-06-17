/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:42:21 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/16 12:28:30 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	ft_matrix_copy(t_matrix *dst, t_matrix *src)
{
	int	i;
	int	j;

	i = 0;
	while (i < DIMENSION)
	{
		j = 0;
		while (j < DIMENSION)
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
