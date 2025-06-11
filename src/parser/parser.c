/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/11 15:44:09 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	is_empty_or_comment(char *line)
{
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	return (*line == '\0' || *line == '#');
}

static bool	parse_element_type(t_scene *scene, char **tokens)
{
	if (!tokens || !tokens[0])
		return (false);
	if (ft_strcmp(tokens[0], "A") == 0)
		return (parse_ambient(scene, tokens));
	else if (ft_strcmp(tokens[0], "C") == 0)
		return (parse_camera(scene, tokens));
	else if (ft_strcmp(tokens[0], "L") == 0)
		return (parse_light(scene, tokens));
	else if (ft_strcmp(tokens[0], "sp") == 0)
		return (parse_sphere(scene, tokens));
	else if (ft_strcmp(tokens[0], "pl") == 0)
		return (parse_plane(scene, tokens));
	else if (ft_strcmp(tokens[0], "cy") == 0)
		return (parse_cylinder(scene, tokens));
	return (error_message("Unknown element type"));
}

bool	parse_line(t_scene *scene, char *line)
{
	char	**tokens;
	bool	result;

	if (is_empty_or_comment(line))
		return (true);
	tokens = ft_split_whitespace(line);
	if (!tokens)
		return (error_message("Memory allocation failed"));
	result = parse_element_type(scene, tokens);
	ft_free_split(tokens);
	return (result);
}

static bool	read_scene_file(t_scene *scene, int fd)
{
	char	*line;
	bool	result;

	result = true;
	line = get_next_line(fd);
	while (line && result)
	{
		result = parse_line(scene, line);
		free(line);
		if (result)
			line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (result);
}

t_scene	*parse_scene(char *filename)
{
	t_scene	*scene;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error_message(MSG_FILE_NOT_FOUND);
		return (NULL);
	}
	scene = init_scene();
	if (!scene)
	{
		close(fd);
		error_message(MSG_MEMORY_ERROR);
		return (NULL);
	}
	if (!read_scene_file(scene, fd))
	{
		close(fd);
		cleanup_scene(scene);
		return (NULL);
	}
	close(fd);
	return (scene);
}
