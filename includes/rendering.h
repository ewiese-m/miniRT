/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:07:54 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:51:11 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

t_color	new_color(double r, double g, double b);

t_color	add_colors(t_color c1, t_color c2);
t_color	sub_colors(t_color c1, t_color c2);
t_color	mult_colors(t_color c1, t_color c2);
t_color	scale_color(t_color c, double scalar);
int		color_to_rgb(t_color color);

t_color	lighting(t_shading_data *lighting_info, bool shadowed);
bool	in_shadow(t_scene *scene, t_point point);
void	render(t_renderer *data);

#endif
