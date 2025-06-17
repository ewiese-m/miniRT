/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:31:23 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/15 11:42:47 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_object	*new_object(int id);
int			ft_parse_rt_file(t_scene *scene, char *file);
int			parse_sphere(t_scene *scene, char *line);
int			parse_plane(t_scene *scene, char *line);
int			parse_cylinder(t_scene *scene, char *line);
int			parse_camera(t_scene *scene, char *line);
int			parse_light(t_scene *scene, char *line);
int			parse_enviroment(t_scene *scene, char *line);
int			parse_color(char *line, t_color *color);
int			parse_position(char *line, t_matrix *transform);
int			ft_parse_rotation(char *line, t_matrix *transform);
int			ft_parse_scale(double x, double y, double z, t_matrix *matrix);
int			ft_parse_point(char *line, t_point *point);
int			ft_parse_vector(char *line, t_vector *vector);

#endif
