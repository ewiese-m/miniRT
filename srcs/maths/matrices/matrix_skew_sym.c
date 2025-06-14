/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_skew_sym.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:05:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:21:43 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_matrix	*matrix_skew_sym(t_vector axis)
{
	t_matrix	*res;

	res = matrix_identity();
	res->matrix[0][0] = 0;
	res->matrix[0][1] = -axis.z;
	res->matrix[0][2] = axis.y;
	res->matrix[1][0] = axis.z;
	res->matrix[1][1] = 0;
	res->matrix[1][2] = -axis.x;
	res->matrix[2][0] = -axis.y;
	res->matrix[2][1] = axis.x;
	res->matrix[2][2] = 0;
	return (res);
}
