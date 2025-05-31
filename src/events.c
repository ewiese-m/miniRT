/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:25:39 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/05/31 16:38:29 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307) // ESC key
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	printf("Key pressed: %d\n", keycode);
	return (0);
}

// Mouse click handler
int	mouse_press(int button, int x, int y, t_data *data)
{
	// I dont need it for the moment, but for sure in the future.
	(void)data;
	printf("Mouse button %d clicked at (%d, %d)\n", button, x, y);
	return (0);
}

// Window close handler (red X button)
int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

/*
X11 Event Types:

2 = KeyPress
3 = KeyRelease
4 = ButtonPress (mouse)
5 = ButtonRelease (mouse)
6 = MotionNotify (mouse movement)
17 = DestroyNotify (window close)

Common Key Codes:

ESC: 65307
Space: 32
Enter: 65293
Arrow keys: Up 65362, Down 65364, Left 65361, Right 65363
WASD: W 119, A 97, S 115, D 100

Mouse Buttons:

Left click: 1
Middle click: 2
Right click: 3
 */
