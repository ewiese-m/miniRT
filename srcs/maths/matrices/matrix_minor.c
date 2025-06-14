/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_minor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:50:35 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:20:52 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

double	matrix_minor(t_matrix m, int row, int col)
{
	t_matrix	m2;

	m2 = matrix_submatrix(m, row, col);
	return (matrix_determinant(m2));
}
