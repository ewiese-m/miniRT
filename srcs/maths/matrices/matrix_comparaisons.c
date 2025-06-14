/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_comparaisons.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:43:59 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:28 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	matrix_compare(t_matrix m1, t_matrix m2)
{
	int		i;
	int		j;

	i = 0;
	while (i < m1.size)
	{
		j = 0;
		while (j < m1.size)
		{
			if (m1.matrix[i][j] != m2.matrix[i][j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
