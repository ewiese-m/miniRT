/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:40:43 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 18:02:30 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	mlx_initialize_window(t_renderer *data)
{
	data->mlx->mlx = NULL;
	data->mlx->mlx_win = NULL;
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		mlx_error(data);
	mlx_get_screen_size(data->mlx->mlx,
		&data->mlx->screen_width, &data->mlx->screen_height);
	if (data->mlx->screen_width <= 0 || data->mlx->screen_height <= 0)
		mlx_error(data);
	data->mlx->win_width = WIDHT;
	data->mlx->win_height = HEIGHT;
	data->mlx->mlx_win = mlx_new_window(data->mlx->mlx, data->mlx->win_width,
			data->mlx->win_height, "miniRT");
	if (!data->mlx->mlx_win)
		mlx_error(data);
	data->mlx->img = mlx_new_image(data->mlx->mlx,
			data->mlx->win_width, data->mlx->win_height);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img,
			&data->mlx->bpp, &data->mlx->line_length,
			&data->mlx->endian);
	if (!data->mlx->img)
		mlx_error(data);
}
