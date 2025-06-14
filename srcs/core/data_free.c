/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 07:46:01 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 03:06:19 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_intersection(void *content)
{
	t_intersection	*inter;

	inter = (t_intersection *)content;
	free(inter);
}

void	data_free(t_renderer *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->scene)
		free_scene(data->scene);
}
