/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 07:17:07 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 03:02:00 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_line(t_scene *scene, char *line)
{
	if (line[0] == 'A' && line[1] == ' ')
		return (ft_parse_ambient(scene, line));
	else if (line[0] == 'C' && line[1] == ' ')
		return (ft_parse_camera(scene, line));
	else if (line[0] == 'L' && line[1] == ' ')
		return (ft_parse_light(scene, line));
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		return (ft_parse_sphere(scene, line));
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		return (ft_parse_plane(scene, line));
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		return (ft_parse_cylinder(scene, line));
	else if (line[0] == '\n' || line[0] == '\0')
		return (1);
	return (0);
}

void	ft_set_amblight(t_scene *scene)
{
	t_list	*tmp;

	tmp = scene->objects;
	while (tmp)
	{
		((t_object *)tmp->content)->material->ambient = scene->ambient;
		tmp = tmp->next;
	}
}

int	check_scene(t_scene *scene)
{
	if (!scene->camera)
		return (ft_error(ERROR_CAMERA_NOT_DEFINED), 0);
	if (!scene->ambient)
		return (ft_error(ERROR_AMBIENT_NOT_DEFINED), 0);
	if (!scene->objects)
		return (ft_error(ERROR_OBJECT_NOT_DEFINED), 0);
	if (!scene->lights)
		return (ft_error(ERROR_LIGHT_NOT_DEFINED), 0);
	return (1);
}

char	*ft_remove_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		i++;
	}
	return (line);
}

int	ft_parse_rt_file(t_scene *scene, char *file)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		ret = ft_parse_line(scene, ft_remove_newline(line));
		free(line);
		if (ret == 0)
			return (close(fd), 0);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (!check_scene(scene))
		return (0);
	ft_set_amblight(scene);
	return (1);
}
