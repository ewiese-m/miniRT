/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:09:03 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:45 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_light(void *light)
{
	t_light	*tmp;

	tmp = (t_light *)light;
	free(tmp);
}

void	free_ambient(t_ambient *ambient)
{
	free(ambient);
}

void	free_hittable(void *hittable)
{
	t_hittable	*tmp;

	tmp = (t_hittable *)hittable;
	if (tmp->material)
		free(tmp->material);
	if (tmp->transform)
		free(tmp->transform);
	free(tmp);
}

void	free_camera(t_camera *camera)
{
	if (!camera)
		return ;
	if (camera->transform)
		free(camera->transform);
	free(camera);
}

void	free_scene(t_scene *scene)
{
	if (scene->ambient)
		free_ambient(scene->ambient);
	if (scene->lights)
		ft_lstclear(&scene->lights, free_light);
	if (scene->objects)
		ft_lstclear(&scene->objects, free_hittable);
	if (scene->camera)
		free_camera(scene->camera);
	free(scene);
}
