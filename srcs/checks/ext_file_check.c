/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_file_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:08:10 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:08:16 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	ext_file_check(char *path)
{
	int		i_ext;
	int		i_path;
	char	*ext;

	i_ext = 0;
	i_path = ft_strlen(path) - 3;
	ext = ".rt";
	if (ft_strlen(path) <= 3 || path[i_path - 1] == '/')
		ft_exit("Error: File must be a .rt\n", 1);
	while (i_path != (int)ft_strlen(path))
	{
		if (path[i_path] != ext[i_ext])
			ft_exit("Error: File must be a .rt\n", 1);
		i_path++;
		i_ext++;
	}
}
