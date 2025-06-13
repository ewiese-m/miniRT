/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:13:33 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 00:26:53 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	*intersect_with_cylinder(t_hittable *cy, t_ray ray, double c, double d)
{
	double	*intersections;
	double	a;
	double	b;

	a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	b = 2 * (ray.origin.x * ray.direction.x + ray.origin.z * ray.direction.z);
	c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	d = pow(b, 2) - 4 * a * c;
	if (d < 0)
		return (NULL);
	intersections = malloc(sizeof(double) * 2);
	if (!intersections)
		return (NULL);
	intersections[0] = (-b - sqrt(d)) / (2 * a);
	intersections[1] = (-b + sqrt(d)) / (2 * a);
	a = ray.origin.y + intersections[0] * ray.direction.y;
	b = ray.origin.y + intersections[1] * ray.direction.y;
	if ((a < -cy->height / 2 || a > cy->height / 2) && (b < -cy->height / 2
			|| b > cy->height / 2))
		return (free(intersections), NULL);
	else if (a < -cy->height / 2 || a > cy->height / 2)
		intersections[0] = intersections[1];
	else if (b < -cy->height / 2 || b > cy->height / 2)
		intersections[1] = intersections[0];
	return (intersections);
}
