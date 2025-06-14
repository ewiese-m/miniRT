/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transforms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:29:51 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:24:18 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	calculate_rotations(t_vector vector, double *x_angle, double *z_angle)
{
	double	ratio;

	ratio = sqrt((vector.x * vector.x) + \
	(vector.y * vector.y));
	if (ratio < EPSILON)
		*z_angle = M_PI_2;
	else
		*z_angle = acos(vector.y / ratio);
	*x_angle = acos(ratio);
}

void	matrix_rotation(t_matrix *transform, t_vector vector)
{
	double		x_angle;
	double		z_angle;
	t_matrix	*rotate_z;
	t_matrix	*rotate_x;
	t_matrix	*result;

	calculate_rotations(vector, &x_angle, &z_angle);
	rotate_z = matrix_rotation_z(z_angle);
	rotate_x = matrix_rotation_x(x_angle);
	result = matrix_mult(*rotate_z, *rotate_x);
	matrix_transform(transform, result);
	free(result);
	free(rotate_z);
	free(rotate_x);
}

int	ft_parse_rotation(char *line, t_matrix *transform)
{
	char		**tab;
	t_vector	orientation;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || !ft_isfloat(tab[0])
		|| !ft_isfloat(tab[1]) || !ft_isfloat(tab[2]))
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_ROTATION);
		return (0);
	}
	orientation = vector_new(ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2]));
	if (tuple_mag(orientation) < 1 - EPSILON
		|| tuple_mag(orientation) > 1 + EPSILON)
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_ORIENTATION_NORMALIZED);
		return (0);
	}
	matrix_rotation(transform, orientation);
	ft_free_2d_list(tab);
	return (1);
}

int	ft_parse_scale(double scale_x, double scale_y, double scale_z,
	t_matrix *transform)
{
	t_matrix	*scale;

	scale = matrix_scale(scale_x, scale_y, scale_z);
	if (!scale)
	{
		ft_error(ERROR_MALLOC);
		return (0);
	}
	matrix_transform(transform, scale);
	free(scale);
	return (1);
}

int	ft_parse_translation(char *line, t_matrix *transform)
{
	char		**tab;
	t_matrix	*translation;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || !ft_isfloat(tab[0])
		|| !ft_isfloat(tab[1]) || !ft_isfloat(tab[2]))
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_CENTER);
		return (0);
	}
	translation = matrix_translation(ft_atof(tab[0]),
			ft_atof(tab[1]), ft_atof(tab[2]));
	if (!translation)
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_MALLOC);
		return (0);
	}
	matrix_transform(transform, translation);
	ft_free_2d_list(tab);
	free(translation);
	return (1);
}
