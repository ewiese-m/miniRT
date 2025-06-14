/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:59:12 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 18:01:23 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_sphere(t_scene *scene, char *line)
{
	t_object	*sphere;
	char		**tab;
	double		diameter;

	sphere = ft_init_hittable(SPHERE);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(sphere), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB), free_parse_hittable(sphere, tab,
				SPHERE), 0);
	if (!ft_parse_translation(tab[1], sphere->transform))
		return (free_parse_hittable(sphere, tab, SPHERE), 0);
	if (!ft_isfloat(tab[2]))
		return (free_parse_hittable(sphere, tab, SPHERE), 0);
	diameter = ft_atof(tab[2]);
	ft_parse_scale(diameter / 2, diameter / 2, diameter / 2, sphere->transform);
	if (!ft_parse_color(tab[3], &sphere->material->color))
		return (free_parse_hittable(sphere, tab, SPHERE), 0);
	ft_lstadd_back(&scene->objects, ft_lstnew(sphere));
	ft_free_2d_list(tab);
	return (1);
}
