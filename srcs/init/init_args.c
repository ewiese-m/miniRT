/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 01:10:42 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:52:53 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	init_args(int argc, char **argv, char **envp)
{
	ft_args_check(argc, argv, envp);
	ft_ext_file_check(argv[1], ".rt");
	ft_file_check_path(argv[1]);
	return (0);
}
