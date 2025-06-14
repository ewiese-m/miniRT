/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:30:53 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 18:02:29 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv, char **envp)
{
	t_renderer	minirt;

	args_check(argc, argv, envp);
	data_initialize(&minirt);
	if (!init_minirt(&minirt))
		return (data_free(&minirt), 0);
	if (!ft_parse_rt_file(minirt.scene, argv[1]))
	{
		data_free(&minirt);
		ft_error(ERROR_PARSING_FILE);
		return (0);
	}
	mlx_initialize_window(&minirt);
	mlx_hook_loop(&minirt);
	mlx_free(&minirt);
	data_free(&minirt);
	return (1);
}
