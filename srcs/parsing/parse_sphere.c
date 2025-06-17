/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:59:12 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:55:55 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	validate_sphere_args(char **tab)
{
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB), 0);
	if (!ft_isfloat(tab[2]))
		return (0);
	return (1);
}

static int	parse_sphere_position(t_object *sphere, char **tab)
{
	if (!parse_position(tab[1], sphere->transform))
		return (0);
	return (1);
}

static void	set_sphere_dimensions(t_object *sphere, char **tab)
{
	double	diameter;
	double	radius;

	diameter = ft_atof(tab[2]);
	radius = diameter / 2;
	ft_parse_scale(radius, radius, radius, sphere->transform);
}

static int	parse_sphere_color(t_object *sphere, char **tab)
{
	if (!parse_color(tab[3], &sphere->material->color))
		return (0);
	return (1);
}

int	parse_sphere(t_scene *scene, char *line)
{
	t_object	*sphere;
	char		**tab;

	sphere = new_object(SPHERE);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(sphere), ft_error(ERROR_MALLOC), 0);
	if (!validate_sphere_args(tab))
		return (free_parse_hittable(sphere, tab, SPHERE), 0);
	if (!parse_sphere_position(sphere, tab))
		return (free_parse_hittable(sphere, tab, SPHERE), 0);
	set_sphere_dimensions(sphere, tab);
	if (!parse_sphere_color(sphere, tab))
		return (free_parse_hittable(sphere, tab, SPHERE), 0);
	ft_lstadd_back(&scene->objects, ft_lstnew(sphere));
	ft_free_2d_list(tab);
	return (1);
}
