/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_cofactor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:51:24 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:21:03 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

double	matrix_cofactor(t_matrix m, int row, int col)
{
	double		minor;

	minor = matrix_minor(m, row, col);
	if ((row + col) % 2 == 0)
		return (minor);
	else
		return (-minor);
}
