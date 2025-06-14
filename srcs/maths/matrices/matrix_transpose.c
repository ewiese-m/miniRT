/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:44:43 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:21:43 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_matrix	matrix_transpose(t_matrix m)
{
	int			i;
	int			j;
	t_matrix	m2;

	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			m2.matrix[i][j] = m.matrix[j][i];
			j++;
		}
		i++;
	}
	m2.size = m.size;
	m2.matrix[3][0] = 0;
	m2.matrix[3][1] = 0;
	m2.matrix[3][2] = 0;
	m2.matrix[3][3] = 1;
	return (m2);
}
