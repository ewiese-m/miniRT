/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:11:31 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:45 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_material	*material_init(void)
{
	t_material	*material;

	material = malloc(sizeof(t_material));
	if (!material)
		return (NULL);
	material->color = color_new(255, 255, 255);
	material->ambient = NULL;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200;
	return (material);
}
