/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:23:08 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:50:41 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

void	intersec_free(void *content);
void	free_hittable(void *hittable);
void	free_parse_camera(t_camera *camera, char **tab);
void	free_parse_hittable(t_object *hittable, char **tab, int id);
void	free_parse_light(t_light *light, char **tab);
void	free_parse_ambient(t_ambient_light *ambient, char **tab);
void	free_light(void *light);
void	free_ambient(t_ambient_light *ambient);
void	free_camera(t_camera *camera);
void	free_scene(t_scene *scene);
void	data_free(t_renderer *data);
void	intersec_free(void *content);

#endif
