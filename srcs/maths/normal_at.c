/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:24:12 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/15 00:04:49 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static t_vector	object_normal_at(t_object *obj, t_tuple object_point)
{
	t_vector	normal;

	if (obj->type == SPHERE)
		normal = vector_sub(object_point, point_new(0, 0, 0));
	else if (obj->type == CYLINDER)
	{
		if (object_point.y >= obj->height / 2 - EPSILON)
			normal = vector_new(0, 1, 0);
		else if (object_point.y <= -obj->height / 2 + EPSILON)
			normal = vector_new(0, -1, 0);
		else
			normal = vector_new(object_point.x, 0, object_point.z);
	}
	else if (obj->type == PLANE)
		normal = vector_new(0, 1, 0);
	return (vector_norm(normal));
}

t_vector	normal_at(t_object *obj, t_point world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix	transpose;

	object_point = vector_transform(world_point,
			matrix_inverse(*obj->transform));
	object_normal = object_normal_at(obj, object_point);
	transpose = matrix_transpose(matrix_inverse(*obj->transform));
	world_normal = vector_transform(object_normal, transpose);
	return (vector_norm(world_normal));
}
