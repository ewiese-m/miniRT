/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:40:43 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/16 12:19:53 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	init_mlx_connection(t_renderer *data)
{
	data->mlx->mlx = NULL;
	data->mlx->mlx_win = NULL;
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		mlx_error(data);
}

static void	get_screen_dimensions(t_renderer *data)
{
	mlx_get_screen_size(data->mlx->mlx, &data->mlx->screen_width,
		&data->mlx->screen_height);
	if (data->mlx->screen_width <= 0 || data->mlx->screen_height <= 0)
		mlx_error(data);
}

static void	create_window(t_renderer *data)
{
	data->mlx->win_width = WIDHT;
	data->mlx->win_height = HEIGHT;
	data->mlx->mlx_win = mlx_new_window(data->mlx->mlx, data->mlx->win_width,
			data->mlx->win_height, "miniRT <--> ewiese-m <--> chuynh");
	if (!data->mlx->mlx_win)
		mlx_error(data);
}

static void	create_image_buffer(t_renderer *data)
{
	data->mlx->img = mlx_new_image(data->mlx->mlx, data->mlx->win_width,
			data->mlx->win_height);
	if (!data->mlx->img)
		mlx_error(data);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp,
			&data->mlx->line_length, &data->mlx->endian);
}

void	init_window(t_renderer *data)
{
	init_mlx_connection(data);
	get_screen_dimensions(data);
	create_window(data);
	create_image_buffer(data);
}
