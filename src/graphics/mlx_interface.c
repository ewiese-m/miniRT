/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 18:09:20 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	mlx_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (!img || !img->addr)
		return ;
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mlx_get_pixel(t_image *img, int x, int y)
{
	char	*src;

	if (!img || !img->addr)
		return (0);
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	src = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)src);
}

void	display_image(t_mlx *mlx, t_image *img)
{
	if (!mlx || !mlx->mlx || !mlx->window || !img || !img->img)
		return ;
	mlx_put_image_to_window(mlx->mlx, mlx->window, img->img, 0, 0);
}

void	clear_image(t_image *img, int color)
{
	int	x;
	int	y;

	if (!img)
		return ;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_line(t_image *img, t_vec3 start, t_vec3 end, int color)
{
	t_vec3	delta;
	t_vec3	current;
	int		steps;
	int		i;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	steps = (int)fmax(fabs(delta.x), fabs(delta.y));
	if (steps == 0)
	{
		mlx_put_pixel(img, (int)start.x, (int)start.y, color);
		return ;
	}
	delta.x /= steps;
	delta.y /= steps;
	current = start;
	i = 0;
	while (i <= steps)
	{
		mlx_put_pixel(img, (int)current.x, (int)current.y, color);
		current.x += delta.x;
		current.y += delta.y;
		i++;
	}
}

void	draw_circle(t_image *img, int center_x, int center_y, int radius,
		int color)
{
	int	x;
	int	y;
	int	distance_squared;
	int	radius_squared;

	radius_squared = radius * radius;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			distance_squared = x * x + y * y;
			if (distance_squared <= radius_squared)
				mlx_put_pixel(img, center_x + x, center_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_rectangle(t_image *img, int x, int y, int width, int height,
		int color)
{
	int	i;
	int	j;
	int	end_x;
	int	end_y;

	end_x = x + width;
	end_y = y + height;
	j = y;
	while (j < end_y)
	{
		i = x;
		while (i < end_x)
		{
			mlx_put_pixel(img, i, j, color);
			i++;
		}
		j++;
	}
}

void	draw_gradient(t_image *img, t_color start_color, t_color end_color,
		bool horizontal)
{
	int		x;
	int		y;
	double	factor;
	t_color	current_color;
	int		max_val;

	if (horizontal)
		max_val = img->width;
	else
		max_val = img->height;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			if (horizontal)
				factor = (double)x / (double)(img->width - 1);
			else
				factor = (double)y / (double)(img->height - 1);
			current_color.r = (int)(start_color.r + factor * (end_color.r
						- start_color.r));
			current_color.g = (int)(start_color.g + factor * (end_color.g
						- start_color.g));
			current_color.b = (int)(start_color.b + factor * (end_color.b
						- start_color.b));
			mlx_put_pixel(img, x, y, color_to_int(current_color));
			x++;
		}
		y++;
	}
}

void	apply_gamma_correction(t_image *img, double gamma)
{
	int		x;
	int		y;
	int		pixel;
	t_color	color;
	t_color	corrected;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel = mlx_get_pixel(img, x, y);
			color = int_to_color(pixel);
			corrected.r = (int)(255.0 * pow(color.r / 255.0, 1.0 / gamma));
			corrected.g = (int)(255.0 * pow(color.g / 255.0, 1.0 / gamma));
			corrected.b = (int)(255.0 * pow(color.b / 255.0, 1.0 / gamma));
			corrected.r = clamp_int(corrected.r, 0, 255);
			corrected.g = clamp_int(corrected.g, 0, 255);
			corrected.b = clamp_int(corrected.b, 0, 255);
			mlx_put_pixel(img, x, y, color_to_int(corrected));
			x++;
		}
		y++;
	}
}

void	save_image_ppm(t_image *img, const char *filename)
{
	int		fd;
	int		x;
	int		y;
	int		pixel;
	t_color	color;
	char	*header;
	char	*line;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	header = "P3\n";
	write(fd, header, ft_strlen(header));
	line = ft_itoa(img->width);
	write(fd, line, ft_strlen(line));
	free(line);
	write(fd, " ", 1);
	line = ft_itoa(img->height);
	write(fd, line, ft_strlen(line));
	free(line);
	write(fd, "\n255\n", 5);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel = mlx_get_pixel(img, x, y);
			color = int_to_color(pixel);
			line = ft_itoa(color.r);
			write(fd, line, ft_strlen(line));
			free(line);
			write(fd, " ", 1);
			line = ft_itoa(color.g);
			write(fd, line, ft_strlen(line));
			free(line);
			write(fd, " ", 1);
			line = ft_itoa(color.b);
			write(fd, line, ft_strlen(line));
			free(line);
			if (x < img->width - 1)
				write(fd, " ", 1);
			x++;
		}
		write(fd, "\n", 1);
		y++;
	}
	close(fd);
}
