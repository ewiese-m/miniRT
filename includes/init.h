/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:34:41 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:50:25 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

int			init_args(int argc, char **argv, char **envp);
void		init_data(t_renderer *data);
t_camera	*init_camera(void);
t_material	*init_material(void);
int			init_minirt(t_renderer *render);
void		init_scene(t_scene *scene);

#endif
