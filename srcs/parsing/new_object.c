/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:51:55 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:55:15 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_object	*new_object(int id)
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
	hittable->material = init_material();
	if (!hittable->material)
	{
		free_hittable(hittable);
		return (ft_error(ERROR_MALLOC), NULL);
	}
	return (hittable);
}
