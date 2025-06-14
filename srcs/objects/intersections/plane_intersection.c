/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:59:09 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/15 00:02:53 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

double	*intersect_with_plane(t_ray ray)
{
	double	*intersections;
	double	denominator;
	double	t;

	denominator = vector_dot(ray.direction, vector_new(0, 1, 0));
	if (fabs(denominator) < EPSILON)
		return (NULL);
	t = -ray.origin.y / denominator;
	if (t < 0)
		return (NULL);
	intersections = malloc(sizeof(double) * 2);
	if (!intersections)
		return (NULL);
	intersections[0] = t;
	intersections[1] = 0;
	return (intersections);
}
