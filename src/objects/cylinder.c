/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by assistant         #+#    #+#             */
/*   Updated: 2025/06/05 07:05:09 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	calculate_cylinder_coefficients(t_ray ray, t_cylinder *cylinder,
		double coeffs[3])
{
	t_vec3	oc;
	t_vec3	d_parallel;
	t_vec3	oc_parallel;
	double	radius;

	oc = vec3_subtract(ray.origin, cylinder->center);
	d_parallel = vec3_multiply(cylinder->axis, vec3_dot(ray.direction,
				cylinder->axis));
	oc_parallel = vec3_multiply(cylinder->axis, vec3_dot(oc, cylinder->axis));
	radius = cylinder->diameter / 2;
	coeffs[0] = vec3_dot(vec3_subtract(ray.direction, d_parallel),
			vec3_subtract(ray.direction, d_parallel));
	coeffs[1] = 2 * vec3_dot(vec3_subtract(ray.direction, d_parallel),
			vec3_subtract(oc, oc_parallel));
	coeffs[2] = vec3_dot(vec3_subtract(oc, oc_parallel), vec3_subtract(oc,
				oc_parallel)) - radius * radius;
}

static bool	check_cylinder_height(t_vec3 point, t_cylinder *cylinder)
{
	t_vec3	to_point;
	double	projection;

	to_point = vec3_subtract(point, cylinder->center);
	projection = vec3_dot(to_point, cylinder->axis);
	return (projection >= 0 && projection <= cylinder->height);
}

static double	get_valid_t(double t1, double t2, t_ray ray, t_cylinder *cyl)
{
	t_vec3	p1;
	t_vec3	p2;
	bool	valid1;
	bool	valid2;

	if (t1 < EPSILON && t2 < EPSILON)
		return (-1);
	p1 = ray_at(ray, t1);
	p2 = ray_at(ray, t2);
	valid1 = (t1 > EPSILON) && check_cylinder_height(p1, cyl);
	valid2 = (t2 > EPSILON) && check_cylinder_height(p2, cyl);
	if (valid1 && valid2)
		return ((t1 < t2) ? t1 : t2);
	if (valid1)
		return (t1);
	if (valid2)
		return (t2);
	return (-1);
}

static t_vec3	get_cylinder_normal(t_vec3 point, t_cylinder *cylinder)
{
	t_vec3	to_point;
	t_vec3	projection;
	t_vec3	normal;

	to_point = vec3_subtract(point, cylinder->center);
	projection = vec3_multiply(cylinder->axis, vec3_dot(to_point,
				cylinder->axis));
	normal = vec3_subtract(to_point, projection);
	return (vec3_normalize(normal));
}

t_hit	intersect_cylinder(t_ray ray, t_cylinder *cylinder)
{
	t_hit	hit;
	double	coeffs[3];
	double	discriminant;
	double	t1;
	double	t2;
	double	t;

	hit = create_hit();
	calculate_cylinder_coefficients(ray, cylinder, coeffs);
	discriminant = coeffs[1] * coeffs[1] - 4 * coeffs[0] * coeffs[2];
	if (discriminant < 0)
		return (hit);
	t1 = (-coeffs[1] - sqrt(discriminant)) / (2 * coeffs[0]);
	t2 = (-coeffs[1] + sqrt(discriminant)) / (2 * coeffs[0]);
	t = get_valid_t(t1, t2, ray, cylinder);
	if (t < 0)
		return (hit);
	hit.hit = true;
	hit.distance = t;
	hit.point = ray_at(ray, t);
	hit.normal = get_cylinder_normal(hit.point, cylinder);
	hit.color = cylinder->color;
	return (hit);
}
