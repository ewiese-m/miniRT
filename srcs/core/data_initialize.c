/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 07:46:43 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 15:39:29 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_scene(t_scene *scene)
{
	scene->camera = NULL;
	scene->ambient = NULL;
	scene->lights = NULL;
	scene->objects = NULL;
}

void	data_initialize(t_renderer *data)
{
	data->mlx = malloc(sizeof(t_mlx_context));
	if (!data->mlx)
		ft_exit("Error: malloc failed\n", 1);
	data->scene = malloc(sizeof(t_scene));
	if (!data->scene)
		ft_exit("Error: malloc failed\n", 1);
	init_scene(data->scene);
	data->pxl_rendered = 0;
}
