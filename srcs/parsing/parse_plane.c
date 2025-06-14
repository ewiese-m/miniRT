/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:00:52 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 18:01:06 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_plane(t_scene *scene, char *line)
{
	t_object	*plane;
	char		**tab;

	plane = ft_init_hittable(PLANE);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(plane), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB), free_parse_hittable(plane, tab,
				PLANE), 0);
	plane->id = PLANE;
	if (!ft_parse_translation(tab[1], plane->transform))
		return (free_parse_hittable(plane, tab, PLANE), 0);
	if (!ft_parse_rotation(tab[2], plane->transform))
		return (free_parse_hittable(plane, tab, PLANE), 0);
	if (!ft_parse_color(tab[3], &plane->material->color))
		return (free_parse_hittable(plane, tab, PLANE), 0);
	ft_lstadd_back(&scene->objects, ft_lstnew(plane));
	ft_free_2d_list(tab);
	return (1);
}
