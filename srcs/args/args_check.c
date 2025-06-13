/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:14:01 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:14:36 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	args_check(int argc, char **argv, char **envp)
{
	if (!envp[0])
		ft_exit("Error: No environment\n", 1);
	if (argc != 2)
		ft_exit("Error: Wrong number of arguments\n", 1);
	if (argv[1][0] == '0')
		return (0);
	file_check_ext(argv[1]);
	file_check_path(argv[1]);
	return (0);
}
