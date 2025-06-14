/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:04:37 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/15 00:03:41 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

double	*get_intersections(double a, double b, double discriminant)
{
	double		*intersections;

	intersections = malloc(sizeof(double) * 2);
	if (!intersections)
		return (NULL);
	intersections[0] = (-b - sqrt(discriminant)) / (2 * a);
	intersections[1] = (-b + sqrt(discriminant)) / (2 * a);
	return (intersections);
}

double	*intersect_with_sphere(t_ray ray)
{
	double		a;
	double		b;
	double		c;
	t_tuple		sphere_to_ray;
	double		discriminant;

	sphere_to_ray = vector_sub(ray.origin, point_new(0, 0, 0));
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(ray.direction, sphere_to_ray);
	c = vector_dot(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = 0;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return (NULL);
	return (get_intersections(a, b, discriminant));
}
