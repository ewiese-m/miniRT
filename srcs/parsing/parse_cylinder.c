/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:54:54 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 12:51:48 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	validate_cylinder_args(char **tab)
{
	if (ft_tablen(tab) != 6)
		return (ft_error(ERROR_WRONG_ARGS_NB), 0);
	if (!ft_isfloat(tab[3]) || !ft_isfloat(tab[4]))
		return (0);
	return (1);
}

static int	parse_cylinder_transforms(t_object *cylinder, char **tab)
{
	if (!parse_position(tab[1], cylinder->transform))
		return (0);
	if (!ft_parse_rotation(tab[2], cylinder->transform))
		return (0);
	return (1);
}

static void	set_cylinder_dimensions(t_object *cylinder, char **tab)
{
	double	radius;

	radius = ft_atof(tab[3]) / 2;
	ft_parse_scale(radius, 1, radius, cylinder->transform);
	cylinder->radius = radius;
	cylinder->height = ft_atof(tab[4]);
}

static int	parse_cylinder_color(t_object *cylinder, char **tab)
{
	if (!parse_color(tab[5], &cylinder->material->color))
		return (0);
	return (1);
}

int	parse_cylinder(t_scene *scene, char *line)
{
	t_object	*cylinder;
	char		**tab;

	cylinder = new_object(CYLINDER);
	tab = ft_split(line, ' ');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (!validate_cylinder_args(tab))
		return (free_parse_hittable(cylinder, tab, CYLINDER), 0);
	if (!parse_cylinder_transforms(cylinder, tab))
		return (free_parse_hittable(cylinder, tab, CYLINDER), 0);
	set_cylinder_dimensions(cylinder, tab);
	if (!parse_cylinder_color(cylinder, tab))
		return (free_parse_hittable(cylinder, tab, CYLINDER), 0);
	ft_lstadd_back(&scene->objects, ft_lstnew(cylinder));
	return (ft_free_2d_list(tab), 1);
}
