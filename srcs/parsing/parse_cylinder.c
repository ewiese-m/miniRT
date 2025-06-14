/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:54:54 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:24:18 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	ft_parse_cylinder(t_scene *scene, char *line)
{
	t_object	*cylinder;
	char		**tab;

	cylinder = ft_init_hittable(CYLINDER);
	tab = ft_split(line, ' ');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 6)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_hittable(cylinder, tab, CYLINDER), 0);
	if (!ft_parse_translation(tab[1], cylinder->transform))
		return (free_parse_hittable(cylinder, tab, CYLINDER), 0);
	if (!ft_parse_rotation(tab[2], cylinder->transform))
		return (free_parse_hittable(cylinder, tab, CYLINDER), 0);
	if (!ft_isfloat(tab[3]) || !ft_isfloat(tab[4]))
		return (free_parse_hittable(cylinder, tab, CYLINDER), 0);
	ft_parse_scale(ft_atof(tab[3]) / 2,
		1, ft_atof(tab[3]) / 2, cylinder->transform);
	cylinder->radius = ft_atof(tab[3]) / 2;
	cylinder->height = ft_atof(tab[4]);
	if (!ft_parse_color(tab[5], &cylinder->material->color))
		return (free_parse_hittable(cylinder, tab, CYLINDER), 0);
	ft_lstadd_back(&scene->objects, ft_lstnew(cylinder));
	return (ft_free_2d_list(tab), 1);
}
