/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:54:17 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:45 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_minirt(t_minirt *minirt)
{
	if (!minirt->scene)
		return (0);
	minirt->scene->camera = NULL;
	minirt->scene->ambient = NULL;
	minirt->scene->lights = NULL;
	minirt->scene->objects = NULL;
	return (1);
}
