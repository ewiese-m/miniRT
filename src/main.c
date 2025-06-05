/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:53:28 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 06:46:08 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int	handle_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
	{
		cleanup_mlx(mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	handle_close(t_mlx *mlx)
{
	cleanup_mlx(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	setup_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->window, 2, 1L << 0, handle_keypress, mlx);
	mlx_hook(mlx->window, 17, 0, handle_close, mlx);
}

static void	run_minirt(char *filename)
{
	t_scene	*scene;
	t_mlx	*mlx;

	scene = parse_scene(filename);
	if (!scene)
		error_exit(MSG_PARSE_ERROR);
	if (!validate_scene(scene))
	{
		cleanup_scene(scene);
		error_exit(MSG_PARSE_ERROR);
	}
	mlx = init_mlx();
	if (!mlx)
	{
		cleanup_scene(scene);
		error_exit(MSG_MLX_ERROR);
	}
	render_scene(scene, mlx);
	display_image(mlx, mlx->image);
	setup_hooks(mlx);
	cleanup_scene(scene);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		usage_error();
	if (ft_strlen(argv[1]) < 4 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3,
			".rt", 3) != 0)
		error_exit(MSG_FILE_EXTENSION);
	run_minirt(argv[1]);
	return (0);
}
