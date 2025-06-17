/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:01:44 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:55:30 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ft_get_pixel_size(t_camera *camera)
{
	double		aspect_ratio;

	camera->half_view = tan(camera->fov * M_PI / 360);
	aspect_ratio = (double)WIDHT / (double)HEIGHT;
	if (aspect_ratio >= 1)
	{
		camera->half_width = camera->half_view;
		camera->half_height = camera->half_view / aspect_ratio;
	}
	else
	{
		camera->half_width = camera->half_view * aspect_ratio;
		camera->half_height = camera->half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / (double)WIDHT;
}

t_matrix	*ft_get_view_transform(t_point from, t_matrix *orientation)
{
	t_matrix	*result;
	t_matrix	*translation;

	translation = matrix_translation(-from.x, -from.y, -from.z);
	if (!translation)
	{
		free(orientation);
		return (NULL);
	}
	result = matrix_mult(*orientation, *translation);
	free(translation);
	free(orientation);
	return (result);
}

t_matrix	*view_transform(t_point from, t_vector direction)
{
	t_vector	forward;
	t_vector	left;
	t_vector	true_up;
	t_matrix	*orientation;
	double		**matrix_values;

	forward = direction;
	left = vector_cross(forward, vector_new(0, 1, 0));
	if (left.x == 0 && left.y == 0 && left.z == 0)
		left = vector_cross(forward, vector_new(0, 0, 1));
	true_up = vector_cross(left, forward);
	matrix_values = (double *[]){
		(double []){left.x, left.y, left.z, 0},
		(double []){true_up.x, true_up.y, true_up.z, 0},
		(double []){-forward.x, -forward.y, -forward.z, 0},
		(double []){0, 0, 0, 1}
	};
	orientation = matrix_new(matrix_values, 4);
	if (!orientation)
		return (NULL);
	return (ft_get_view_transform(from, orientation));
}

int	ft_parse_camera_transform(t_camera *camera, char **tab)
{
	t_point		*origin;
	t_vector	*direction;

	origin = malloc(sizeof(t_point));
	direction = malloc(sizeof(t_vector));
	if (!origin || !direction)
		return (0);
	if (!ft_parse_point(tab[1], origin))
	{
		free(origin);
		free(direction);
		return (0);
	}
	if (!ft_parse_vector(tab[2], direction))
	{
		free(origin);
		free(direction);
		return (0);
	}
	camera->transform = view_transform(*origin, *direction);
	free(origin);
	free(direction);
	return (1);
}

int	parse_camera(t_scene *scene, char *line)
{
	t_camera	*camera;
	char		**tab;

	if (scene->camera)
		return (ft_error("Multiple cameras not allowed"), 0);
	camera = init_camera();
	if (!camera)
		return (free_parse_camera(camera, NULL), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(camera), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_camera(camera, tab), 0);
	if (!ft_isfloat(tab[3]))
		return (free_parse_camera(camera, tab), 0);
	camera->fov = ft_atof(tab[3]);
	if (camera->fov <= 0 || camera->fov >= 180)
		return (ft_error(E_FOV), free_parse_camera(camera, tab), 0);
	if (!ft_parse_camera_transform(camera, tab))
		return (free_parse_camera(camera, tab), 0);
	scene->camera = camera;
	ft_get_pixel_size(camera);
	ft_free_2d_list(tab);
	return (1);
}
