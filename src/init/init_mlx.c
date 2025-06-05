/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 07:08:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_image	*init_image(void *mlx_ptr)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->width = WINDOW_WIDTH;
	image->height = WINDOW_HEIGHT;
	image->img = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!image->img)
	{
		free(image);
		return (NULL);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	return (image);
}

static void	cleanup_partial_mlx(t_mlx *mlx)
{
	if (mlx->image)
	{
		if (mlx->image->img)
			mlx_destroy_image(mlx->mlx, mlx->image->img);
		free(mlx->image);
	}
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	free(mlx);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx = NULL;
	mlx->window = NULL;
	mlx->image = NULL;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		free(mlx);
		return (NULL);
	}
	mlx->window = mlx_new_window(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (!mlx->window)
	{
		cleanup_partial_mlx(mlx);
		return (NULL);
	}
	mlx->image = init_image(mlx->mlx);
	if (!mlx->image)
	{
		cleanup_partial_mlx(mlx);
		return (NULL);
	}
	return (mlx);
}
