/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by assistant         #+#    #+#             */
/*   Updated: 2025/06/05 07:03:22 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static double	get_sphere_intersection(t_ray ray, t_sphere *sphere)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vec3_subtract(ray.origin, sphere->center);
	a = vec3_dot(ray.direction, ray.direction);
	b = 2.0 * vec3_dot(oc, ray.direction);
	c = vec3_dot(oc, oc) - (sphere->diameter / 2) * (sphere->diameter / 2);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	return ((-b - sqrt(discriminant)) / (2 * a));
}

static t_vec3	get_sphere_normal(t_vec3 point, t_sphere *sphere)
{
	return (vec3_normalize(vec3_subtract(point, sphere->center)));
}

t_hit	intersect_sphere(t_ray ray, t_sphere *sphere)
{
	t_hit	hit;
	double	t;

	hit = create_hit();
	t = get_sphere_intersection(ray, sphere);
	if (t < EPSILON)
		return (hit);
	hit.hit = true;
	hit.distance = t;
	hit.point = ray_at(ray, t);
	hit.normal = get_sphere_normal(hit.point, sphere);
	hit.color = sphere->color;
	return (hit);
}

bool	is_inside_sphere(t_vec3 point, t_sphere *sphere)
{
	t_vec3	to_center;
	double	distance_squared;
	double	radius_squared;

	to_center = vec3_subtract(point, sphere->center);
	distance_squared = vec3_dot(to_center, to_center);
	radius_squared = (sphere->diameter / 2) * (sphere->diameter / 2);
	return (distance_squared < radius_squared);
}

t_sphere	*create_sphere(t_vec3 center, double diameter, t_color color)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->diameter = diameter;
	sphere->color = color;
	return (sphere);
}
