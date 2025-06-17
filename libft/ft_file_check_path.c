/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:24:41 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:56:14 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_file_check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_exit("Cannot open file\n", 1);
	if (read(fd, NULL, 0) == -1)
		ft_exit("Cannot read file\n", 1);
	close(fd);
}
