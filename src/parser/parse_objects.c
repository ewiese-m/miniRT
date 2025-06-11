/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/11 15:42:34 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	parse_sphere(t_scene *scene, char **tokens)
{
	t_sphere	*sphere;
	t_object	*object;

	if (!tokens[1] || !tokens[2] || !tokens[3])
		return (error_message("Invalid sphere format"));
	sphere = init_sphere();
	if (!sphere)
		return (error_message(MSG_MEMORY_ERROR));
	if (!parse_vector(&sphere->center, tokens[1])
		|| !parse_color(&sphere->color, tokens[3]))
	{
		free(sphere);
		return (false);
	}
	sphere->diameter = ft_atof(tokens[2]);
	if (sphere->diameter <= 0)
	{
		free(sphere);
		return (error_message("Sphere diameter must be positive"));
	}
	object = create_object(OBJ_SPHERE, sphere);
	if (!object)
		return (error_message(MSG_MEMORY_ERROR));
	add_object_to_scene(scene, object);
	return (true);
}

bool	parse_plane(t_scene *scene, char **tokens)
{
	t_plane		*plane;
	t_object	*object;

	if (!tokens[1] || !tokens[2] || !tokens[3])
		return (error_message("Invalid plane format"));
	plane = init_plane();
	if (!plane)
		return (error_message(MSG_MEMORY_ERROR));
	if (!parse_vector(&plane->point, tokens[1]) || !parse_vector(&plane->normal,
			tokens[2]) || !parse_color(&plane->color, tokens[3]))
	{
		free(plane);
		return (false);
	}
	if (!validate_vector_range(&plane->normal, -1.0, 1.0))
	{
		free(plane);
		return (error_message("Plane normal must be normalized"));
	}
	plane->normal = vec3_normalize(plane->normal);
	object = create_object(OBJ_PLANE, plane);
	if (!object)
		return (error_message(MSG_MEMORY_ERROR));
	add_object_to_scene(scene, object);
	return (true);
}

static bool	validate_cylinder_params(t_cylinder *cylinder)
{
	if (cylinder->diameter <= 0)
		return (error_message("Cylinder diameter must be positive"));
	if (cylinder->height <= 0)
		return (error_message("Cylinder height must be positive"));
	if (!validate_vector_range(&cylinder->axis, -1.0, 1.0))
		return (error_message("Cylinder axis must be normalized"));
	return (true);
}

bool	parse_cylinder(t_scene *scene, char **tokens)
{
	t_cylinder	*cylinder;
	t_object	*object;

	if (!tokens[1] || !tokens[2] || !tokens[3] || !tokens[4] || !tokens[5])
		return (error_message("Invalid cylinder format"));
	cylinder = init_cylinder();
	if (!cylinder)
		return (error_message(MSG_MEMORY_ERROR));
	if (!parse_vector(&cylinder->center, tokens[1])
		|| !parse_vector(&cylinder->axis, tokens[2])
		|| !parse_color(&cylinder->color, tokens[5]))
	{
		free(cylinder);
		return (false);
	}
	cylinder->diameter = ft_atof(tokens[3]);
	cylinder->height = ft_atof(tokens[4]);
	if (!validate_cylinder_params(cylinder))
	{
		free(cylinder);
		return (false);
	}
	cylinder->axis = vec3_normalize(cylinder->axis);
	object = create_object(OBJ_CYLINDER, cylinder);
	if (!object)
		return (error_message(MSG_MEMORY_ERROR));
	add_object_to_scene(scene, object);
	return (true);
}
