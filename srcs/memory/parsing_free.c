/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:24:45 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 03:00:48 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	free_parse_camera(t_camera *camera, char **tab)
{
	free_camera(camera);
	if (tab)
		ft_free_2d_list(tab);
	ft_error("Invalid camera parameters");
}

void	free_parse_hittable(t_object *hittable, char **tab, int id)
{
	if (hittable)
		free_hittable(hittable);
	if (tab)
		ft_free_2d_list(tab);
	if (id == SPHERE)
		ft_error("Invalid sphere parameters");
	else if (id == CYLINDER)
		ft_error("Invalid cylinder parameters");
	else if (id == PLANE)
		ft_error("Invalid plane definition");
}

void	free_parse_light(t_light *light, char **tab)
{
	if (light)
		free(light);
	if (tab)
		ft_free_2d_list(tab);
	ft_error("Invalid light configuration");
}

void	free_parse_ambient(t_ambient_light *ambient, char **tab)
{
	if (ambient)
		free(ambient);
	if (tab)
		ft_free_2d_list(tab);
	ft_error("Invalid ambient light settings");
}
