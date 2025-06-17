/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:34:06 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/16 12:27:03 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_matrix	*matrix_rotation_x(double angle)
{
	t_matrix	*m;

	m = matrix_identity();
	m->matrix[1][1] = cos(angle);
	m->matrix[1][2] = -sin(angle);
	m->matrix[2][1] = sin(angle);
	m->matrix[2][2] = cos(angle);
	return (m);
}

t_matrix	*matrix_rotation_y(double angle)
{
	t_matrix	*m;

	m = matrix_identity();
	m->matrix[0][0] = cos(angle);
	m->matrix[0][2] = sin(angle);
	m->matrix[2][0] = -sin(angle);
	m->matrix[2][2] = cos(angle);
	return (m);
}

t_matrix	*matrix_rotation_z(double angle)
{
	t_matrix	*m;

	m = matrix_identity();
	m->matrix[0][0] = cos(angle);
	m->matrix[0][1] = -sin(angle);
	m->matrix[1][0] = sin(angle);
	m->matrix[1][1] = cos(angle);
	return (m);
}
