/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 07:08:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static double	get_plane_intersection(t_ray ray, t_plane *plane)
{
	double	denom;
	double	t;
	t_vec3	to_plane;

	denom = vec3_dot(ray.direction, plane->normal);
	if (fabs(denom) < EPSILON)
		return (-1);
	to_plane = vec3_subtract(plane->point, ray.origin);
	t = vec3_dot(to_plane, plane->normal) / denom;
	return (t);
}

static t_vec3	get_plane_normal(t_ray ray, t_plane *plane)
{
	double	dot_product;

	dot_product = vec3_dot(ray.direction, plane->normal);
	if (dot_product > 0)
		return (vec3_multiply(plane->normal, -1));
	return (plane->normal);
}

t_hit	intersect_plane(t_ray ray, t_plane *plane)
{
	t_hit	hit;
	double	t;

	hit = create_hit();
	t = get_plane_intersection(ray, plane);
	if (t < EPSILON)
		return (hit);
	hit.hit = true;
	hit.distance = t;
	hit.point = ray_at(ray, t);
	hit.normal = get_plane_normal(ray, plane);
	hit.color = plane->color;
	return (hit);
}

bool	is_on_plane(t_vec3 point, t_plane *plane)
{
	t_vec3	to_point;
	double	distance;

	to_point = vec3_subtract(point, plane->point);
	distance = fabs(vec3_dot(to_point, plane->normal));
	return (distance < EPSILON);
}

t_plane	*create_plane(t_vec3 point, t_vec3 normal, t_color color)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->point = point;
	plane->normal = vec3_normalize(normal);
	plane->color = color;
	return (plane);
}
