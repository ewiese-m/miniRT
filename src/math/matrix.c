/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 18:05:34 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <math.h>

/**
 * Matrix operations for transformations in 3D space
 * Using 4x4 matrices for homogeneous coordinates
 */

typedef struct s_matrix4
{
	double	m[4][4];
}			t_matrix4;

t_matrix4	matrix4_identity(void)
{
	t_matrix4	mat;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				mat.m[i][j] = 1.0;
			else
				mat.m[i][j] = 0.0;
			j++;
		}
		i++;
	}
	return (mat);
}

t_matrix4	matrix4_multiply(t_matrix4 a, t_matrix4 b)
{
	t_matrix4	result;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.m[i][j] = 0.0;
			k = 0;
			while (k < 4)
			{
				result.m[i][j] += a.m[i][k] * b.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

t_vec3	matrix4_multiply_vec3(t_matrix4 mat, t_vec3 vec)
{
	t_vec3	result;
	double	w;

	result.x = mat.m[0][0] * vec.x + mat.m[0][1] * vec.y + mat.m[0][2] * vec.z
		+ mat.m[0][3];
	result.y = mat.m[1][0] * vec.x + mat.m[1][1] * vec.y + mat.m[1][2] * vec.z
		+ mat.m[1][3];
	result.z = mat.m[2][0] * vec.x + mat.m[2][1] * vec.y + mat.m[2][2] * vec.z
		+ mat.m[2][3];
	w = mat.m[3][0] * vec.x + mat.m[3][1] * vec.y + mat.m[3][2] * vec.z
		+ mat.m[3][3];
	if (fabs(w) > EPSILON)
	{
		result.x /= w;
		result.y /= w;
		result.z /= w;
	}
	return (result);
}

t_matrix4	matrix4_translate(double x, double y, double z)
{
	t_matrix4	mat;

	mat = matrix4_identity();
	mat.m[0][3] = x;
	mat.m[1][3] = y;
	mat.m[2][3] = z;
	return (mat);
}

t_matrix4	matrix4_scale(double x, double y, double z)
{
	t_matrix4	mat;

	mat = matrix4_identity();
	mat.m[0][0] = x;
	mat.m[1][1] = y;
	mat.m[2][2] = z;
	return (mat);
}

t_matrix4	matrix4_rotate_x(double angle)
{
	t_matrix4	mat;
	double		cos_a;
	double		sin_a;

	mat = matrix4_identity();
	cos_a = cos(angle);
	sin_a = sin(angle);
	mat.m[1][1] = cos_a;
	mat.m[1][2] = -sin_a;
	mat.m[2][1] = sin_a;
	mat.m[2][2] = cos_a;
	return (mat);
}

t_matrix4	matrix4_rotate_y(double angle)
{
	t_matrix4	mat;
	double		cos_a;
	double		sin_a;

	mat = matrix4_identity();
	cos_a = cos(angle);
	sin_a = sin(angle);
	mat.m[0][0] = cos_a;
	mat.m[0][2] = sin_a;
	mat.m[2][0] = -sin_a;
	mat.m[2][2] = cos_a;
	return (mat);
}

t_matrix4	matrix4_rotate_z(double angle)
{
	t_matrix4	mat;
	double		cos_a;
	double		sin_a;

	mat = matrix4_identity();
	cos_a = cos(angle);
	sin_a = sin(angle);
	mat.m[0][0] = cos_a;
	mat.m[0][1] = -sin_a;
	mat.m[1][0] = sin_a;
	mat.m[1][1] = cos_a;
	return (mat);
}

t_matrix4	matrix4_rotate_axis(t_vec3 axis, double angle)
{
	t_matrix4	mat;
	double		cos_a;
	double		sin_a;
	double		one_minus_cos;
	t_vec3		normalized_axis;

	normalized_axis = vec3_normalize(axis);
	cos_a = cos(angle);
	sin_a = sin(angle);
	one_minus_cos = 1.0 - cos_a;
	mat = matrix4_identity();
	mat.m[0][0] = cos_a + normalized_axis.x * normalized_axis.x * one_minus_cos;
	mat.m[0][1] = normalized_axis.x * normalized_axis.y * one_minus_cos
		- normalized_axis.z * sin_a;
	mat.m[0][2] = normalized_axis.x * normalized_axis.z * one_minus_cos
		+ normalized_axis.y * sin_a;
	mat.m[1][0] = normalized_axis.y * normalized_axis.x * one_minus_cos
		+ normalized_axis.z * sin_a;
	mat.m[1][1] = cos_a + normalized_axis.y * normalized_axis.y * one_minus_cos;
	mat.m[1][2] = normalized_axis.y * normalized_axis.z * one_minus_cos
		- normalized_axis.x * sin_a;
	mat.m[2][0] = normalized_axis.z * normalized_axis.x * one_minus_cos
		- normalized_axis.y * sin_a;
	mat.m[2][1] = normalized_axis.z * normalized_axis.y * one_minus_cos
		+ normalized_axis.x * sin_a;
	mat.m[2][2] = cos_a + normalized_axis.z * normalized_axis.z * one_minus_cos;
	return (mat);
}

double	matrix4_determinant(t_matrix4 mat)
{
	double	det;

	det = mat.m[0][0] * (mat.m[1][1] * (mat.m[2][2] * mat.m[3][3] - mat.m[2][3]
				* mat.m[3][2]) - mat.m[1][2] * (mat.m[2][1] * mat.m[3][3]
				- mat.m[2][3] * mat.m[3][1]) + mat.m[1][3] * (mat.m[2][1]
				* mat.m[3][2] - mat.m[2][2] * mat.m[3][1]));
	det -= mat.m[0][1] * (mat.m[1][0] * (mat.m[2][2] * mat.m[3][3] - mat.m[2][3]
				* mat.m[3][2]) - mat.m[1][2] * (mat.m[2][0] * mat.m[3][3]
				- mat.m[2][3] * mat.m[3][0]) + mat.m[1][3] * (mat.m[2][0]
				* mat.m[3][2] - mat.m[2][2] * mat.m[3][0]));
	det += mat.m[0][2] * (mat.m[1][0] * (mat.m[2][1] * mat.m[3][3] - mat.m[2][3]
				* mat.m[3][1]) - mat.m[1][1] * (mat.m[2][0] * mat.m[3][3]
				- mat.m[2][3] * mat.m[3][0]) + mat.m[1][3] * (mat.m[2][0]
				* mat.m[3][1] - mat.m[2][1] * mat.m[3][0]));
	det -= mat.m[0][3] * (mat.m[1][0] * (mat.m[2][1] * mat.m[3][2] - mat.m[2][2]
				* mat.m[3][1]) - mat.m[1][1] * (mat.m[2][0] * mat.m[3][2]
				- mat.m[2][2] * mat.m[3][0]) + mat.m[1][2] * (mat.m[2][0]
				* mat.m[3][1] - mat.m[2][1] * mat.m[3][0]));
	return (det);
}

t_matrix4	matrix4_transpose(t_matrix4 mat)
{
	t_matrix4	result;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.m[i][j] = mat.m[j][i];
			j++;
		}
		i++;
	}
	return (result);
}

t_matrix4	matrix4_look_at(t_vec3 eye, t_vec3 center, t_vec3 up)
{
	t_matrix4	mat;
	t_vec3		f;
	t_vec3		s;
	t_vec3		u;

	f = vec3_normalize(vec3_subtract(center, eye));
	s = vec3_normalize(vec3_cross(f, up));
	u = vec3_cross(s, f);
	mat = matrix4_identity();
	mat.m[0][0] = s.x;
	mat.m[1][0] = s.y;
	mat.m[2][0] = s.z;
	mat.m[0][1] = u.x;
	mat.m[1][1] = u.y;
	mat.m[2][1] = u.z;
	mat.m[0][2] = -f.x;
	mat.m[1][2] = -f.y;
	mat.m[2][2] = -f.z;
	mat.m[3][0] = -vec3_dot(s, eye);
	mat.m[3][1] = -vec3_dot(u, eye);
	mat.m[3][2] = vec3_dot(f, eye);
	return (mat);
}
