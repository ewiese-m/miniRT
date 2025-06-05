/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 18:15:27 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	*create_window_safe(void *mlx_ptr, int width, int height,
		char *title)
{
	void	*window;

	if (!mlx_ptr || width <= 0 || height <= 0 || !title)
		return (NULL);
	window = mlx_new_window(mlx_ptr, width, height, title);
	if (!window)
		return (NULL);
	return (window);
}

void	*create_window(void *mlx_ptr, int width, int height, char *title)
{
	void	*window;

	window = create_window_safe(mlx_ptr, width, height, title);
	if (!window)
	{
		ft_putstr_fd("Error: Failed to create window\n", 2);
		return (NULL);
	}
	return (window);
}

void	destroy_window(void *mlx_ptr, void *window)
{
	if (mlx_ptr && window)
		mlx_destroy_window(mlx_ptr, window);
}

void	clear_window(void *mlx_ptr, void *window)
{
	if (mlx_ptr && window)
		mlx_clear_window(mlx_ptr, window);
}

void	set_window_title(void *mlx_ptr, void *window, char *title)
{
	(void)mlx_ptr;
	(void)window;
	(void)title;
	// MLX doesn't provide a function to change window title after creation
	// This is a placeholder for potential future implementations
}

void	put_pixel_to_window(void *mlx_ptr, void *window, int x, int y,
		int color)
{
	if (mlx_ptr && window && x >= 0 && y >= 0 && x < WINDOW_WIDTH
		&& y < WINDOW_HEIGHT)
		mlx_pixel_put(mlx_ptr, window, x, y, color);
}

void	put_string_to_window(void *mlx_ptr, void *window, int x, int y,
		int color, char *string)
{
	if (mlx_ptr && window && string && x >= 0 && y >= 0)
		mlx_string_put(mlx_ptr, window, x, y, color, string);
}

void	put_image_to_window(void *mlx_ptr, void *window, void *img, int x,
		int y)
{
	if (mlx_ptr && window && img)
		mlx_put_image_to_window(mlx_ptr, window, img, x, y);
}

bool	is_valid_window_coords(int x, int y)
{
	return (x >= 0 && y >= 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT);
}

void	update_window_display(t_mlx *mlx)
{
	if (!mlx || !mlx->mlx || !mlx->window || !mlx->image || !mlx->image->img)
		return ;
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->img, 0, 0);
}

int	get_window_width(void)
{
	return (WINDOW_WIDTH);
}

int	get_window_height(void)
{
	return (WINDOW_HEIGHT);
}

void	center_window_text(void *mlx_ptr, void *window, char *text, int y,
		int color)
{
	int	text_width;
	int	x;

	if (!mlx_ptr || !window || !text)
		return ;
	// Approximation: each character is about 6 pixels wide
	text_width = ft_strlen(text) * 6;
	x = (WINDOW_WIDTH - text_width) / 2;
	if (x < 0)
		x = 0;
	mlx_string_put(mlx_ptr, window, x, y, color, text);
}

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
}			t_rect;

void	draw_rectangle(void *mlx_ptr, void *window, t_rect rect, int color)
{
	int	x;
	int	y;

	if (!mlx_ptr || !window)
		return ;
	y = rect.y;
	while (y < rect.y + rect.height && y < WINDOW_HEIGHT)
	{
		x = rect.x;
		while (x < rect.x + rect.width && x < WINDOW_WIDTH)
		{
			if (is_valid_window_coords(x, y))
				mlx_pixel_put(mlx_ptr, window, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_line(void *mlx_ptr, void *window, t_point start, t_point end,
		int color)
{
	int		dx;
	int		dy;
	int		steps;
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
	int		i;

	if (!mlx_ptr || !window)
		return ;
	dx = end.x - start.x;
	dy = end.y - start.y;
	steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
	if (steps == 0)
	{
		if (is_valid_window_coords(start.x, start.y))
			mlx_pixel_put(mlx_ptr, window, start.x, start.y, color);
		return ;
	}
	x_inc = (float)dx / steps;
	y_inc = (float)dy / steps;
	x = start.x;
	y = start.y;
	i = 0;
	while (i <= steps)
	{
		if (is_valid_window_coords((int)x, (int)y))
			mlx_pixel_put(mlx_ptr, window, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

void	draw_circle(void *mlx_ptr, void *window, t_point center, int radius,
		int color)
{
	int	x;
	int	y;
	int	d;

	if (!mlx_ptr || !window || radius <= 0)
		return ;
	x = 0;
	y = radius;
	d = 3 - 2 * radius;
	while (y >= x)
	{
		// Draw 8 points for each octant
		if (is_valid_window_coords(center.x + x, center.y + y))
			mlx_pixel_put(mlx_ptr, window, center.x + x, center.y + y, color);
		if (is_valid_window_coords(center.x - x, center.y + y))
			mlx_pixel_put(mlx_ptr, window, center.x - x, center.y + y, color);
		if (is_valid_window_coords(center.x + x, center.y - y))
			mlx_pixel_put(mlx_ptr, window, center.x + x, center.y - y, color);
		if (is_valid_window_coords(center.x - x, center.y - y))
			mlx_pixel_put(mlx_ptr, window, center.x - x, center.y - y, color);
		if (is_valid_window_coords(center.x + y, center.y + x))
			mlx_pixel_put(mlx_ptr, window, center.x + y, center.y + x, color);
		if (is_valid_window_coords(center.x - y, center.y + x))
			mlx_pixel_put(mlx_ptr, window, center.x - y, center.y + x, color);
		if (is_valid_window_coords(center.x + y, center.y - x))
			mlx_pixel_put(mlx_ptr, window, center.x + y, center.y - x, color);
		if (is_valid_window_coords(center.x - y, center.y - x))
			mlx_pixel_put(mlx_ptr, window, center.x - y, center.y - x, color);
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
	}
}
