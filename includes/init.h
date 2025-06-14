/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:34:41 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 17:11:43 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

t_camera	*init_camera(void);
t_material	*init_material(void);
int			init_minirt(t_renderer *render);
void		init_scene(t_scene *scene);

#endif
