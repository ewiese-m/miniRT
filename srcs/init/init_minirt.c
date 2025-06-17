/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:54:17 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:53:18 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	init_minirt(t_renderer *render)
{
	if (!render->scene)
		return (0);
	render->scene->camera = NULL;
	render->scene->ambient = NULL;
	render->scene->lights = NULL;
	render->scene->objects = NULL;
	return (1);
}
