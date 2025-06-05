/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 07:08:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_ray	create_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = vec3_normalize(direction);
	return (ray);
}

t_vec3	ray_at(t_ray ray, double t)
{
	return (vec3_add(ray.origin, vec3_multiply(ray.direction, t)));
}

t_hit	create_hit(void)
{
	t_hit	hit;

	hit.hit = false;
	hit.distance = MAX_DISTANCE;
	hit.point = vec3_new(0, 0, 0);
	hit.normal = vec3_new(0, 0, 0);
	hit.color.r = 0;
	hit.color.g = 0;
	hit.color.b = 0;
	hit.object = NULL;
	return (hit);
}

t_hit	trace_ray(t_scene *scene, t_ray ray)
{
	t_hit	closest_hit;
	t_hit	current_hit;
	t_list	*current;

	closest_hit = create_hit();
	current = scene->objects;
	while (current)
	{
		current_hit = find_intersection(ray, (t_object *)current->content);
		if (current_hit.hit && current_hit.distance < closest_hit.distance)
		{
			closest_hit = current_hit;
			closest_hit.object = (t_object *)current->content;
		}
		current = current->next;
	}
	return (closest_hit);
}

t_hit	find_intersection(t_ray ray, t_object *object)
{
	if (!object || !object->shape)
		return (create_hit());
	if (object->type == OBJ_SPHERE)
		return (intersect_sphere(ray, (t_sphere *)object->shape));
	else if (object->type == OBJ_PLANE)
		return (intersect_plane(ray, (t_plane *)object->shape));
	else if (object->type == OBJ_CYLINDER)
		return (intersect_cylinder(ray, (t_cylinder *)object->shape));
	return (create_hit());
}
