/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 07:08:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	init_ambient(t_ambient *ambient)
{
	ambient->ratio = 0.0;
	ambient->color.r = 0;
	ambient->color.g = 0;
	ambient->color.b = 0;
}

static void	init_light(t_light *light)
{
	light->position.x = 0.0;
	light->position.y = 0.0;
	light->position.z = 0.0;
	light->brightness = 0.0;
	light->color.r = 255;
	light->color.g = 255;
	light->color.b = 255;
}

void	init_camera(t_camera *camera)
{
	camera->position.x = 0.0;
	camera->position.y = 0.0;
	camera->position.z = 0.0;
	camera->orientation.x = 0.0;
	camera->orientation.y = 0.0;
	camera->orientation.z = 1.0;
	camera->fov = 70.0;
	camera->up = vec3_new(0.0, 1.0, 0.0);
	camera->right = vec3_new(1.0, 0.0, 0.0);
	camera->forward = vec3_new(0.0, 0.0, 1.0);
}

t_scene	*init_scene(void)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	init_ambient(&scene->ambient);
	init_camera(&scene->camera);
	init_light(&scene->light);
	scene->objects = NULL;
	scene->has_ambient = false;
	scene->has_camera = false;
	scene->has_light = false;
	return (scene);
}
