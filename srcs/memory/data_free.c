/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 07:46:01 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:54:28 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	intersec_free(void *content)
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
