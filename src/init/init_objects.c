/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 07:08:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_sphere	*init_sphere(void)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center.x = 0.0;
	sphere->center.y = 0.0;
	sphere->center.z = 0.0;
	sphere->diameter = 1.0;
	sphere->color.r = 255;
	sphere->color.g = 255;
	sphere->color.b = 255;
	return (sphere);
}

t_plane	*init_plane(void)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->point.x = 0.0;
	plane->point.y = 0.0;
	plane->point.z = 0.0;
	plane->normal.x = 0.0;
	plane->normal.y = 1.0;
	plane->normal.z = 0.0;
	plane->color.r = 255;
	plane->color.g = 255;
	plane->color.b = 255;
	return (plane);
}

t_cylinder	*init_cylinder(void)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (NULL);
	cylinder->center.x = 0.0;
	cylinder->center.y = 0.0;
	cylinder->center.z = 0.0;
	cylinder->axis.x = 0.0;
	cylinder->axis.y = 1.0;
	cylinder->axis.z = 0.0;
	cylinder->diameter = 1.0;
	cylinder->height = 1.0;
	cylinder->color.r = 255;
	cylinder->color.g = 255;
	cylinder->color.b = 255;
	return (cylinder);
}

t_object	*create_object(int type, void *shape)
{
	t_object	*object;

	if (!shape)
		return (NULL);
	object = malloc(sizeof(t_object));
	if (!object)
	{
		free(shape);
		return (NULL);
	}
	object->type = type;
	object->shape = shape;
	return (object);
}

void	add_object_to_scene(t_scene *scene, t_object *object)
{
	t_list	*new_node;

	if (!scene || !object)
		return ;
	new_node = ft_lstnew(object);
	if (!new_node)
	{
		free(object->shape);
		free(object);
		return ;
	}
	ft_lstadd_back(&scene->objects, new_node);
}
