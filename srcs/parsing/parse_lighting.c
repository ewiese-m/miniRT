/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 22:05:20 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/15 11:42:47 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	parse_light(t_scene *scene, char *line)
{
	t_light	*light;
	char	**tab;

	if (scene->lights)
		return (ft_error("Multiple lights not allowed"), 0);
	light = malloc(sizeof(t_light));
	if (!light)
		return (ft_error(ERROR_MALLOC), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(light), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 4)
		return (ft_error(ERROR_WRONG_ARGS_NB), free_parse_light(light, tab), 0);
	if (!ft_parse_point(tab[1], &light->position))
		return (free_parse_light(light, tab), 0);
	if (!ft_isfloat(tab[2]))
		return (free_parse_light(light, tab), 0);
	light->brightness = ft_atof(tab[2]);
	if (!parse_color(tab[3], &light->color))
		return (free_parse_light(light, tab), 0);
	ft_lstadd_back(&scene->lights, ft_lstnew(light));
	ft_free_2d_list(tab);
	return (1);
}

int	parse_enviroment(t_scene *scene, char *line)
{
	t_ambient_light	*ambient;
	char			**tab;

	if (scene->ambient)
		return (ft_error("Multiple ambient lights not allowed"), 0);
	ambient = malloc(sizeof(t_ambient_light));
	if (!ambient)
		return (ft_error(ERROR_MALLOC), 0);
	tab = ft_split(line, ' ');
	if (!tab)
		return (free(ambient), ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3)
		return (ft_error(ERROR_WRONG_ARGS_NB), free_parse_ambient(ambient, tab),
			0);
	if (!ft_isfloat(tab[1]))
		return (free_parse_ambient(ambient, tab), 0);
	ambient->brightness = ft_atof(tab[1]);
	if (!parse_color(tab[2], &ambient->color))
		return (free_parse_ambient(ambient, tab), 0);
	ambient->color = scale_color(ambient->color, ambient->brightness);
	scene->ambient = ambient;
	ft_free_2d_list(tab);
	return (1);
}
