/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 18:11:32 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <math.h>

/**
 * Advanced vector mathematical operations for ray tracing
 */

t_vec3	vec3_reflect(t_vec3 incident, t_vec3 normal)
{
	t_vec3	reflection;
	double	dot_product;

	dot_product = vec3_dot(incident, normal);
	reflection = vec3_subtract(incident, vec3_multiply(normal, 2.0
				* dot_product));
	return (reflection);
}

t_vec3	vec3_refract(t_vec3 incident, t_vec3 normal, double eta)
{
	t_vec3	refracted;
	double	cos_i;
	double	sin_t2;
	double	cos_t;

	cos_i = -vec3_dot(incident, normal);
	sin_t2 = eta * eta * (1.0 - cos_i * cos_i);
	if (sin_t2 > 1.0)
		return (vec3_new(0, 0, 0)); // Total internal reflection
	cos_t = sqrt(1.0 - sin_t2);
	refracted = vec3_add(vec3_multiply(incident, eta), vec3_multiply(normal, eta
				* cos_i - cos_t));
	return (refracted);
}

double	vec3_distance(t_vec3 a, t_vec3 b)
{
	return (vec3_length(vec3_subtract(a, b)));
}

double	vec3_distance_squared(t_vec3 a, t_vec3 b)
{
	t_vec3	diff;

	diff = vec3_subtract(a, b);
	return (vec3_dot(diff, diff));
}

t_vec3	vec3_lerp(t_vec3 a, t_vec3 b, double t)
{
	return (vec3_add(vec3_multiply(a, 1.0 - t), vec3_multiply(b, t)));
}

t_vec3	vec3_project(t_vec3 a, t_vec3 b)
{
	double	dot_ab;
	double	dot_bb;

	dot_ab = vec3_dot(a, b);
	dot_bb = vec3_dot(b, b);
	if (dot_bb < EPSILON)
		return (vec3_new(0, 0, 0));
	return (vec3_multiply(b, dot_ab / dot_bb));
}

t_vec3	vec3_reject(t_vec3 a, t_vec3 b)
{
	return (vec3_subtract(a, vec3_project(a, b)));
}

bool	vec3_is_zero(t_vec3 v)
{
	return (fabs(v.x) < EPSILON && fabs(v.y) < EPSILON && fabs(v.z) < EPSILON);
}

bool	vec3_is_normalized(t_vec3 v)
{
	double	length_sq;

	length_sq = vec3_dot(v, v);
	return (fabs(length_sq - 1.0) < EPSILON);
}

bool	vec3_are_parallel(t_vec3 a, t_vec3 b)
{
	t_vec3	cross_product;

	cross_product = vec3_cross(a, b);
	return (vec3_is_zero(cross_product));
}

bool	vec3_are_perpendicular(t_vec3 a, t_vec3 b)
{
	return (fabs(vec3_dot(a, b)) < EPSILON);
}

double	vec3_angle(t_vec3 a, t_vec3 b)
{
	double	dot_product;
	double	length_a;
	double	length_b;
	double	cos_angle;

	length_a = vec3_length(a);
	length_b = vec3_length(b);
	if (length_a < EPSILON || length_b < EPSILON)
		return (0.0);
	dot_product = vec3_dot(a, b);
	cos_angle = dot_product / (length_a * length_b);
	// Clamp to avoid floating point errors
	if (cos_angle > 1.0)
		cos_angle = 1.0;
	if (cos_angle < -1.0)
		cos_angle = -1.0;
	return (acos(cos_angle));
}

t_vec3	vec3_clamp(t_vec3 v, double min_val, double max_val)
{
	t_vec3	result;

	result.x = fmax(min_val, fmin(max_val, v.x));
	result.y = fmax(min_val, fmin(max_val, v.y));
	result.z = fmax(min_val, fmin(max_val, v.z));
	return (result);
}

t_vec3	vec3_abs(t_vec3 v)
{
	return (vec3_new(fabs(v.x), fabs(v.y), fabs(v.z)));
}

t_vec3	vec3_min(t_vec3 a, t_vec3 b)
{
	return (vec3_new(fmin(a.x, b.x), fmin(a.y, b.y), fmin(a.z, b.z)));
}

t_vec3	vec3_max(t_vec3 a, t_vec3 b)
{
	return (vec3_new(fmax(a.x, b.x), fmax(a.y, b.y), fmax(a.z, b.z)));
}
