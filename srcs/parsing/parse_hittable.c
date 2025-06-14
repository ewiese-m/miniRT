/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hittable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:51:55 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 18:01:40 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	*ft_init_hittable(int id)
{
	t_object	*hittable;

	hittable = malloc(sizeof(t_object));
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
