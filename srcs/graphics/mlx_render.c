/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:00:18 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 03:06:19 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*get_percent(double percent)
{
	char	*str;
	char	*tmp;

	str = ft_itoa((int)percent);
	tmp = ft_strjoin(str, "%");
	free(str);
	return (tmp);
}

int	mlx_render_frame(t_renderer *data)
{
	char	*percent;

	render_scene(data);
	percent = get_percent((double)data->pxl_rendered * 100
			/ (data->mlx->win_width * data->mlx->win_height));
	if ((double)data->pxl_rendered * 100
		/ (data->mlx->win_width * data->mlx->win_height) != 100)
		mlx_string_put(data->mlx->mlx, data->mlx->mlx_win,
			50, 50, 0x00FFFFFF, percent);
	free(percent);
	return (0);
}
