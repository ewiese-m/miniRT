/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 18:06:11 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include <math.h>

/**
 * Mathematical utility functions for ray tracing and 3D graphics
 */

double	degrees_to_radians(double degrees)
{
	return (degrees * PI / 180.0);
}

double	radians_to_degrees(double radians)
{
	return (radians * 180.0 / PI);
}

double	clamp(double value, double min_val, double max_val)
{
	if (value < min_val)
		return (min_val);
	if (value > max_val)
		return (max_val);
	return (value);
}

int	clamp_int(int value, int min_val, int max_val)
{
	if (value < min_val)
		return (min_val);
	if (value > max_val)
		return (max_val);
	return (value);
}

double	lerp(double a, double b, double t)
{
	return (a + t * (b - a));
}

double	smoothstep(double edge0, double edge1, double x)
{
	double	t;

	t = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
	return (t * t * (3.0 - 2.0 * t));
}

bool	solve_quadratic(double a, double b, double c, double *t0, double *t1)
{
	double	discriminant;
	double	sqrt_discriminant;
	double	temp;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	sqrt_discriminant = sqrt(discriminant);
	*t0 = (-b - sqrt_discriminant) / (2 * a);
	*t1 = (-b + sqrt_discriminant) / (2 * a);
	if (*t0 > *t1)
	{
		temp = *t0;
		*t0 = *t1;
		*t1 = temp;
	}
	return (true);
}

double	fast_sqrt(double x)
{
	if (x < 0)
		return (0);
	if (x < EPSILON)
		return (0);
	return (sqrt(x));
}

double	fast_inv_sqrt(double x)
{
	if (x < EPSILON)
		return (0);
	return (1.0 / sqrt(x));
}

bool	is_power_of_two(int n)
{
	return (n > 0 && (n & (n - 1)) == 0);
}

int	next_power_of_two(int n)
{
	int	power;

	if (n <= 0)
		return (1);
	power = 1;
	while (power < n)
		power <<= 1;
	return (power);
}

double	fmod_positive(double x, double y)
{
	double	result;

	result = fmod(x, y);
	if (result < 0)
		result += y;
	return (result);
}

bool	approximately_equal(double a, double b, double epsilon)
{
	return (fabs(a - b) < epsilon);
}

bool	is_zero(double value)
{
	return (fabs(value) < EPSILON);
}

double	sign(double value)
{
	if (value > EPSILON)
		return (1.0);
	if (value < -EPSILON)
		return (-1.0);
	return (0.0);
}

double	step(double edge, double x)
{
	return (x < edge ? 0.0 : 1.0);
}

double	pulse(double edge0, double edge1, double x)
{
	return (step(edge0, x) - step(edge1, x));
}

double	safe_divide(double numerator, double denominator)
{
	if (fabs(denominator) < EPSILON)
		return (0.0);
	return (numerator / denominator);
}

double	safe_acos(double x)
{
	if (x < -1.0)
		return (PI);
	if (x > 1.0)
		return (0.0);
	return (acos(x));
}

double	safe_asin(double x)
{
	if (x < -1.0)
		return (-PI / 2.0);
	if (x > 1.0)
		return (PI / 2.0);
	return (asin(x));
}

double	wrap_angle(double angle)
{
	while (angle > PI)
		angle -= 2.0 * PI;
	while (angle < -PI)
		angle += 2.0 * PI;
	return (angle);
}

double	random_double(void)
{
	return ((double)rand() / (double)RAND_MAX);
}

double	random_double_range(double min_val, double max_val)
{
	return (min_val + (max_val - min_val) * random_double());
}

int	random_int_range(int min_val, int max_val)
{
	return (min_val + rand() % (max_val - min_val + 1));
}

double	bias(double t, double bias_value)
{
	return (pow(t, log(bias_value) / log(0.5)));
}

double	gain(double t, double gain_value)
{
	if (t < 0.5)
		return (bias(2.0 * t, 1.0 - gain_value) / 2.0);
	else
		return (1.0 - bias(2.0 - 2.0 * t, 1.0 - gain_value) / 2.0);
}

bool	in_range(double value, double min_val, double max_val)
{
	return (value >= min_val && value <= max_val);
}

double	map_range(double value, double in_min, double in_max, double out_min,
		double out_max)
{
	return (out_min + (value - in_min) * (out_max - out_min) / (in_max
			- in_min));
}
