/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:31:23 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 18:32:08 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int	ft_parse_rt_file(t_scene *scene, char *file);
int	ft_parse_sphere(t_scene *scene, char *line);
int	ft_parse_plane(t_scene *scene, char *line);
int	ft_parse_cylinder(t_scene *scene, char *line);
int	ft_parse_camera(t_scene *scene, char *line);
int	ft_parse_light(t_scene *scene, char *line);
int	ft_parse_ambient(t_scene *scene, char *line);
int	ft_parse_color(char *line, t_color *color);
int	ft_parse_translation(char *line, t_matrix *transform);
int	ft_parse_rotation(char *line, t_matrix *transform);
int	ft_parse_scale(double x, double y, double z, t_matrix *matrix);
int	ft_parse_point(char *line, t_point *point);
int	ft_parse_vector(char *line, t_vector *vector);

#endif
