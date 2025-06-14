/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:33:22 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 18:33:39 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

t_color	color_new(double r, double g, double b);

t_color	color_add(t_color c1, t_color c2);
t_color	color_sub(t_color c1, t_color c2);
t_color	color_mult(t_color c1, t_color c2);
t_color	color_scalar(t_color c, double scalar);
int		color_to_int(t_color color);

t_color	lighting(t_shading_data *lighting_info, bool shadowed);
bool	is_shadowed(t_scene *scene, t_point point);
void	render_scene(t_renderer *data);

#endif
