/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/11 15:42:15 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	parse_ambient(t_scene *scene, char **tokens)
{
	if (scene->has_ambient)
		return (error_message(MSG_DUPLICATE_ELEM));
	if (!tokens[1] || !tokens[2])
		return (error_message("Invalid ambient light format"));
	scene->ambient.ratio = ft_atof(tokens[1]);
	if (!validate_range(scene->ambient.ratio, MIN_RATIO, MAX_RATIO))
		return (error_message(MSG_INVALID_RANGE));
	if (!parse_color(&scene->ambient.color, tokens[2]))
		return (false);
	if (!validate_color(&scene->ambient.color))
		return (error_message(MSG_INVALID_RANGE));
	scene->has_ambient = true;
	return (true);
}

static bool	parse_camera_orientation(t_camera *camera, char *str)
{
	if (!parse_vector(&camera->orientation, str))
		return (false);
	if (!validate_vector_range(&camera->orientation, -1.0, 1.0))
		return (error_message("Camera orientation must be normalized"));
	camera->orientation = vec3_normalize(camera->orientation);
	return (true);
}

static void	calculate_camera_vectors(t_camera *camera)
{
	t_vec3	world_up;

	world_up = vec3_new(0.0, 1.0, 0.0);
	camera->forward = vec3_normalize(camera->orientation);
	if (fabs(camera->forward.y) > 0.99)
		world_up = vec3_new(0.0, 0.0, 1.0);
	camera->right = vec3_normalize(vec3_cross(world_up, camera->forward));
	camera->up = vec3_normalize(vec3_cross(camera->forward, camera->right));
}

bool	parse_camera(t_scene *scene, char **tokens)
{
	if (scene->has_camera)
		return (error_message(MSG_DUPLICATE_ELEM));
	if (!tokens[1] || !tokens[2] || !tokens[3])
		return (error_message("Invalid camera format"));
	if (!parse_vector(&scene->camera.position, tokens[1]))
		return (false);
	if (!parse_camera_orientation(&scene->camera, tokens[2]))
		return (false);
	scene->camera.fov = ft_atof(tokens[3]);
	if (!validate_range(scene->camera.fov, MIN_FOV, MAX_FOV))
		return (error_message("Camera FOV out of range"));
	calculate_camera_vectors(&scene->camera);
	scene->has_camera = true;
	return (true);
}

bool	parse_light(t_scene *scene, char **tokens)
{
	if (scene->has_light)
		return (error_message(MSG_DUPLICATE_ELEM));
	if (!tokens[1] || !tokens[2])
		return (error_message("Invalid light format"));
	if (!parse_vector(&scene->light.position, tokens[1]))
		return (false);
	scene->light.brightness = ft_atof(tokens[2]);
	if (!validate_range(scene->light.brightness, MIN_RATIO, MAX_RATIO))
		return (error_message("Light brightness out of range"));
	scene->light.color.r = 255;
	scene->light.color.g = 255;
	scene->light.color.b = 255;
	scene->has_light = true;
	return (true);
}
