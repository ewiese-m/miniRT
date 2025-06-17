/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_material.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:11:31 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:53:13 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_material	*init_material(void)
{
	t_material	*material;

	material = malloc(sizeof(t_material));
	if (!material)
		return (NULL);
	material->color = new_color(255, 255, 255);
	material->ambient = NULL;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200;
	return (material);
}
