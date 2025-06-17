/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:00:52 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/16 14:02:56 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	validate_plane_args(char **tab)
{
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB), 0);
	return (1);
}

static int	parse_plane_transforms(t_object *plane, char **tab)
{
	if (!parse_position(tab[1], plane->transform))
		return (0);
	if (!ft_parse_rotation(tab[2], plane->transform))
		return (0);
	return (1);
}

static int	parse_plane_color(t_object *plane, char **tab)
{
	if (!parse_color(tab[3], &plane->material->color))
		return (0);
	return (1);
}

static void	add_plane_to_scene(t_scene *scene, t_object *plane)
{
	ft_lstadd_back(&scene->objects, ft_lstnew(plane));
}

int	parse_plane(t_scene *scene, char *line)
{
	t_object	*plane;
	char		**tab;

	plane = new_object(PLANE);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(plane), ft_error(ERROR_MALLOC), 0);
	if (!validate_plane_args(tab))
		return (free_parse_hittable(plane, tab, PLANE), 0);
	plane->id = PLANE;
	if (!parse_plane_transforms(plane, tab))
		return (free_parse_hittable(plane, tab, PLANE), 0);
	if (!parse_plane_color(plane, tab))
		return (free_parse_hittable(plane, tab, PLANE), 0);
	add_plane_to_scene(scene, plane);
	ft_free_2d_list(tab);
	return (1);
}
