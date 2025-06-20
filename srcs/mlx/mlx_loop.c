/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:02:08 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:14:36 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	mlx_hook_loop(t_minirt *data)
{
	mlx_hook(data->mlx->mlx_win, 2, 1L << 0,
		event_key, data);
	mlx_hook(data->mlx->mlx_win, 25, 1L << 18,
		event_resize, data);
	mlx_hook(data->mlx->mlx_win, 17, 1L << 17,
		mlx_hook_exit, data);
	mlx_loop_hook(data->mlx->mlx,
		mlx_render_frame, data);
	mlx_loop(data->mlx->mlx);
}
