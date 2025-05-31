/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:57:15 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/05/31 16:32:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_data
{
	void	*mlx;
	void	*win;
}			t_data;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

typedef struct s_camera
{
	t_vec3	position;
	t_vec3	orientation;
	double	fov;
}			t_camera;

typedef struct s_light
{
	t_vec3	position;
	double	intensity;
	t_vec3	color;
}			t_light;

// Events Handler

int			key_press(int keycode, t_data *data);
int			mouse_press(int button, int x, int y, t_data *data);
int			close_window(t_data *data);

#endif
