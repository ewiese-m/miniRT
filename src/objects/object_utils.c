/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 07:08:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	free_object(t_object *object)
{
	if (!object)
		return ;
	if (object->shape)
		free(object->shape);
	free(object);
}

void	free_objects(t_list *objects)
{
	t_list		*current;
	t_list		*next;
	t_object	*object;

	current = objects;
	while (current)
	{
		next = current->next;
		object = (t_object *)current->content;
		free_object(object);
		free(current);
		current = next;
	}
}

t_color	get_object_color(t_object *object)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_color		default_color;

	default_color.r = 255;
	default_color.g = 255;
	default_color.b = 255;
	if (!object || !object->shape)
		return (default_color);
	if (object->type == OBJ_SPHERE)
	{
		sphere = (t_sphere *)object->shape;
		return (sphere->color);
	}
	else if (object->type == OBJ_PLANE)
	{
		plane = (t_plane *)object->shape;
		return (plane->color);
	}
	else if (object->type == OBJ_CYLINDER)
	{
		cylinder = (t_cylinder *)object->shape;
		return (cylinder->color);
	}
	return (default_color);
}

t_vec3	get_object_position(t_object *object)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_vec3		default_pos;

	default_pos = vec3_new(0, 0, 0);
	if (!object || !object->shape)
		return (default_pos);
	if (object->type == OBJ_SPHERE)
	{
		sphere = (t_sphere *)object->shape;
		return (sphere->center);
	}
	else if (object->type == OBJ_PLANE)
	{
		plane = (t_plane *)object->shape;
		return (plane->point);
	}
	else if (object->type == OBJ_CYLINDER)
	{
		cylinder = (t_cylinder *)object->shape;
		return (cylinder->center);
	}
	return (default_pos);
}

int	count_objects(t_list *objects)
{
	int		count;
	t_list	*current;

	count = 0;
	current = objects;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
