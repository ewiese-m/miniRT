/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 18:17:59 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	validate_color(t_color *color)
{
	if (!color)
		return (false);
	return (color->r >= MIN_COLOR && color->r <= MAX_COLOR
		&& color->g >= MIN_COLOR && color->g <= MAX_COLOR
		&& color->b >= MIN_COLOR && color->b <= MAX_COLOR);
}

bool	validate_vector_range(t_vec3 *vec, double min, double max)
{
	if (!vec)
		return (false);
	return (vec->x >= min && vec->x <= max
		&& vec->y >= min && vec->y <= max
		&& vec->z >= min && vec->z <= max);
}

bool	validate_range(double value, double min, double max)
{
	return (value >= min && value <= max);
}

bool	validate_positive(double value)
{
	return (value > 0.0);
}

bool	validate_non_negative(double value)
{
	return (value >= 0.0);
}

bool	validate_normalized_vector(t_vec3 *vec)
{
	double	length;

	if (!vec)
		return (false);
	length = vec3_length(*vec);
	return (fabs(length - 1.0) < EPSILON);
}

bool	validate_fov(double fov)
{
	return (validate_range(fov, MIN_FOV, MAX_FOV));
}

bool	validate_ratio(double ratio)
{
	return (validate_range(ratio, MIN_RATIO, MAX_RATIO));
}

bool	validate_brightness(double brightness)
{
	return (validate_range(brightness, MIN_RATIO, MAX_RATIO));
}

bool	validate_diameter(double diameter)
{
	return (validate_positive(diameter));
}

bool	validate_height(double height)
{
	return (validate_positive(height));
}

bool	validate_scene_elements(t_scene *scene)
{
	if (!scene)
		return (false);
	if (!scene->has_ambient || !scene->has_camera || !scene->has_light)
	{
		error_message(MSG_MISSING_ELEM);
		return (false);
	}
	return (true);
}

bool	validate_ambient_light(t_ambient *ambient)
{
	if (!ambient)
		return (false);
	if (!validate_ratio(ambient->ratio))
	{
		error_message("Ambient light ratio must be between 0.0 and 1.0");
		return (false);
	}
	if (!validate_color(&ambient->color))
	{
		error_message("Ambient light color values must be between 0 and 255");
		return (false);
	}
	return (true);
}

bool	validate_camera(t_camera *camera)
{
	if (!camera)
		return (false);
	if (!validate_normalized_vector(&camera->orientation))
	{
		error_message("Camera orientation vector must be normalized");
		return (false);
	}
	if (!validate_fov(camera->fov))
	{
		error_message("Camera FOV must be between 0 and 180 degrees");
		return (false);
	}
	return (true);
}

bool	validate_light(t_light *light)
{
	if (!light)
		return (false);
	if (!validate_brightness(light->brightness))
	{
		error_message("Light brightness must be between 0.0 and 1.0");
		return (false);
	}
	if (!validate_color(&light->color))
	{
		error_message("Light color values must be between 0 and 255");
		return (false);
	}
	return (true);
}

bool	validate_sphere(t_sphere *sphere)
{
	if (!sphere)
		return (false);
	if (!validate_diameter(sphere->diameter))
	{
		error_message("Sphere diameter must be positive");
		return (false);
	}
	if (!validate_color(&sphere->color))
	{
		error_message("Sphere color values must be between 0 and 255");
		return (false);
	}
	return (true);
}

bool	validate_plane(t_plane *plane)
{
	if (!plane)
		return (false);
	if (!validate_normalized_vector(&plane->normal))
	{
		error_message("Plane normal vector must be normalized");
		return (false);
	}
	if (!validate_color(&plane->color))
	{
		error_message("Plane color values must be between 0 and 255");
		return (false);
	}
	return (true);
}

bool	validate_cylinder(t_cylinder *cylinder)
{
	if (!cylinder)
		return (false);
	if (!validate_normalized_vector(&cylinder->axis))
	{
		error_message("Cylinder axis vector must be normalized");
		return (false);
	}
	if (!validate_diameter(cylinder->diameter))
	{
		error_message("Cylinder diameter must be positive");
		return (false);
	}
	if (!validate_height(cylinder->height))
	{
		error_message("Cylinder height must be positive");
		return (false);
	}
	if (!validate_color(&cylinder->color))
	{
		error_message("Cylinder color values must be between 0 and 255");
		return (false);
	}
	return (true);
}

bool	validate_object(t_object *object)
{
	if (!object || !object->shape)
		return (false);
	if (object->type == OBJ_SPHERE)
		return (validate_sphere((t_sphere *)object->shape));
	else if (object->type == OBJ_PLANE)
		return (validate_plane((t_plane *)object->shape));
	else if (object->type == OBJ_CYLINDER)
		return (validate_cylinder((t_cylinder *)object->shape));
	else
	{
		error_message("Unknown object type");
		return (false);
	}
}

bool	validate_scene(t_scene *scene)
{
	t_list	*current;

	if (!scene)
		return (false);
	if (!validate_scene_elements(scene))
		return (false);
	if (!validate_ambient_light(&scene->ambient))
		return (false);
	if (!validate_camera(&scene->camera))
		return (false);
	if (!validate_light(&scene->light))
		return (false);
	current = scene->objects;
	while (current)
	{
		if (!validate_object((t_object *)current->content))
			return (false);
		current = current->next;
	}
	return (true);
}

bool	validate_file_format(char *filename)
{
	if (!filename)
		return (false);
	if (!ends_with(filename, ".rt"))
	{
		error_message(MSG_FILE_EXTENSION);
		return (false);
	}
	return (true);
}

bool	validate_coordinates(int x, int y)
{
	return (x >= 0 && y >= 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT);
}
