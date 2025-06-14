/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:37:39 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 03:06:19 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	mlx_free(t_renderer *data)
{
	if (data->mlx->img)
		mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	if (data->mlx->mlx_win)
		mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	if (data->mlx->mlx_win)
		mlx_destroy_display(data->mlx->mlx);
	if (data->mlx->mlx)
		free(data->mlx->mlx);
}

void	mlx_exit(t_renderer *data, int status)
{
	mlx_free(data);
	data_free(data);
	exit(status);
}

void	mlx_error(t_renderer *data)
{
	mlx_free(data);
	ft_exit("Error: Something went wrong with MiniLibX\n", 1);
}

int	mlx_hook_exit(t_renderer *data)
{
	mlx_free(data);
	data_free(data);
	exit(0);
}
