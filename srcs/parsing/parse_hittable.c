/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hittable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:51:55 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:28 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_hittable	*ft_init_hittable(int id)
{
	t_hittable	*hittable;

	hittable = malloc(sizeof(t_hittable));
	if (!hittable)
		return (NULL);
	hittable->type = id;
	hittable->transform = matrix_identity();
	if (!hittable->transform)
	{
		free_hittable(hittable);
		return (ft_error(ERROR_MALLOC), NULL);
	}
	hittable->material = material_init();
	if (!hittable->material)
	{
		free_hittable(hittable);
		return (ft_error(ERROR_MALLOC), NULL);
	}
	return (hittable);
}

int	ft_parse_sphere(t_scene *scene, char *line)
{
	t_hittable	*sphere;
	char		**tab;
	double		diameter;

	sphere = ft_init_hittable(SPHERE);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(sphere), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_hittable(sphere, tab, SPHERE), 0);
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

int	ft_parse_cylinder(t_scene *scene, char *line)
{
	t_hittable	*cylinder;
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

int	ft_parse_plane(t_scene *scene, char *line)
{
	t_hittable	*plane;
	char		**tab;

	plane = ft_init_hittable(PLANE);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(plane), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB),
			free_parse_hittable(plane, tab, PLANE), 0);
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
