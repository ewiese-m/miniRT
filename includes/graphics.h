/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:11:35 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:50:18 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

int		event_key(int keycode, void *data);
int		event_resize(t_renderer *data);

void	mlx_free(t_renderer *data);
void	mlx_exit(t_renderer *data, int status);
void	mlx_error(t_renderer *data);
int		mlx_hook_exit(t_renderer *data);
void	put_pixel(t_mlx_context *data, int x, int y, int color);
void	init_window(t_renderer *data);
void	mlx_hook_loop(t_renderer *data);
int		mlx_render_frame(t_renderer *data);

#endif
