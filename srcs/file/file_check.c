/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:24:41 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:14:36 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	file_check_ext(char *path)
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

void	file_check_path(char *path)
{
	int		fd;

	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
		ft_exit("Error: Path is a directory\n", 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_exit("Error: Can't open file\n", 1);
	if (read(fd, NULL, 0) == -1)
		ft_exit("Error: Can't read file\n", 1);
	close(fd);
}
