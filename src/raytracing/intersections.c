/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 07:08:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_hit	find_closest_hit(t_scene *scene, t_ray ray)
{
	t_hit		closest_hit;
	t_hit		current_hit;
	t_list		*current;
	t_object	*object;

	closest_hit = create_hit();
	current = scene->objects;
	while (current)
	{
		object = (t_object *)current->content;
		if (object && object->shape)
		{
			current_hit = find_intersection(ray, object);
			if (current_hit.hit && current_hit.distance > EPSILON
				&& current_hit.distance < closest_hit.distance)
			{
				closest_hit = current_hit;
				closest_hit.object = object;
			}
		}
		current = current->next;
	}
	return (closest_hit);
}

static bool	solve_quadratic(double a, double b, double c, double *t)
{
	double	discriminant;
	double	sqrt_discriminant;
	double	t1;
	double	t2;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	sqrt_discriminant = sqrt(discriminant);
	t1 = (-b - sqrt_discriminant) / (2 * a);
	t2 = (-b + sqrt_discriminant) / (2 * a);
	if (t1 > EPSILON)
		*t = t1;
	else if (t2 > EPSILON)
		*t = t2;
	else
		return (false);
	return (true);
}

bool	quadratic_intersection(t_vec3 oc, t_vec3 dir, double radius, double *t)
{
	double	a;
	double	b;
	double	c;

	a = vec3_dot(dir, dir);
	b = 2.0 * vec3_dot(oc, dir);
	c = vec3_dot(oc, oc) - radius * radius;
	return (solve_quadratic(a, b, c, t));
}

t_hit	create_hit_info(double t, t_ray ray, t_vec3 normal, t_color color)
{
	t_hit	hit;

	hit.hit = true;
	hit.distance = t;
	hit.point = ray_at(ray, t);
	hit.normal = vec3_normalize(normal);
	hit.color = color;
	hit.object = NULL;
	return (hit);
}

bool	is_point_in_cylinder_bounds(t_vec3 point, t_cylinder *cylinder)
{
	t_vec3	to_point;
	double	height_projection;

	to_point = vec3_subtract(point, cylinder->center);
	height_projection = vec3_dot(to_point, cylinder->axis);
	return (height_projection >= 0 && height_projection <= cylinder->height);
}
