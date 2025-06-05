/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 18:09:31 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_image	*create_image(t_mlx *mlx, int width, int height)
{
	t_image	*image;

	if (!mlx || !mlx->mlx || width <= 0 || height <= 0)
		return (NULL);
	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->width = width;
	image->height = height;
	image->img = mlx_new_image(mlx->mlx, width, height);
	if (!image->img)
	{
		free(image);
		return (NULL);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	if (!image->addr)
	{
		mlx_destroy_image(mlx->mlx, image->img);
		free(image);
		return (NULL);
	}
	return (image);
}

void	destroy_image(t_mlx *mlx, t_image *image)
{
	if (!image)
		return ;
	if (image->img && mlx && mlx->mlx)
		mlx_destroy_image(mlx->mlx, image->img);
	free(image);
}

t_image	*copy_image(t_mlx *mlx, t_image *src)
{
	t_image	*dst;
	int		x;
	int		y;
	int		pixel;

	if (!src || !mlx)
		return (NULL);
	dst = create_image(mlx, src->width, src->height);
	if (!dst)
		return (NULL);
	y = 0;
	while (y < src->height)
	{
		x = 0;
		while (x < src->width)
		{
			pixel = mlx_get_pixel(src, x, y);
			mlx_put_pixel(dst, x, y, pixel);
			x++;
		}
		y++;
	}
	return (dst);
}

void	resize_image(t_mlx *mlx, t_image **image, int new_width, int new_height)
{
	t_image	*new_image;
	t_image	*old_image;
	int		x;
	int		y;
	int		src_x;
	int		src_y;
	int		pixel;
	double	scale_x;
	double	scale_y;

	if (!image || !*image || !mlx)
		return ;
	old_image = *image;
	new_image = create_image(mlx, new_width, new_height);
	if (!new_image)
		return ;
	scale_x = (double)old_image->width / new_width;
	scale_y = (double)old_image->height / new_height;
	y = 0;
	while (y < new_height)
	{
		x = 0;
		while (x < new_width)
		{
			src_x = (int)(x * scale_x);
			src_y = (int)(y * scale_y);
			if (src_x < old_image->width && src_y < old_image->height)
			{
				pixel = mlx_get_pixel(old_image, src_x, src_y);
				mlx_put_pixel(new_image, x, y, pixel);
			}
			x++;
		}
		y++;
	}
	destroy_image(mlx, old_image);
	*image = new_image;
}

void	flip_image_horizontal(t_image *image)
{
	int	x;
	int	y;
	int	left_pixel;
	int	right_pixel;

	if (!image)
		return ;
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width / 2)
		{
			left_pixel = mlx_get_pixel(image, x, y);
			right_pixel = mlx_get_pixel(image, image->width - 1 - x, y);
			mlx_put_pixel(image, x, y, right_pixel);
			mlx_put_pixel(image, image->width - 1 - x, y, left_pixel);
			x++;
		}
		y++;
	}
}

void	flip_image_vertical(t_image *image)
{
	int	x;
	int	y;
	int	top_pixel;
	int	bottom_pixel;

	if (!image)
		return ;
	y = 0;
	while (y < image->height / 2)
	{
		x = 0;
		while (x < image->width)
		{
			top_pixel = mlx_get_pixel(image, x, y);
			bottom_pixel = mlx_get_pixel(image, x, image->height - 1 - y);
			mlx_put_pixel(image, x, y, bottom_pixel);
			mlx_put_pixel(image, x, image->height - 1 - y, top_pixel);
			x++;
		}
		y++;
	}
}

void	rotate_image_90(t_mlx *mlx, t_image **image)
{
	t_image	*rotated;
	t_image	*original;
	int		x;
	int		y;
	int		pixel;

	if (!image || !*image || !mlx)
		return ;
	original = *image;
	rotated = create_image(mlx, original->height, original->width);
	if (!rotated)
		return ;
	y = 0;
	while (y < original->height)
	{
		x = 0;
		while (x < original->width)
		{
			pixel = mlx_get_pixel(original, x, y);
			mlx_put_pixel(rotated, original->height - 1 - y, x, pixel);
			x++;
		}
		y++;
	}
	destroy_image(mlx, original);
	*image = rotated;
}

void	apply_brightness(t_image *image, double factor)
{
	int		x;
	int		y;
	int		pixel;
	t_color	color;
	t_color	new_color;

	if (!image || factor < 0)
		return ;
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			pixel = mlx_get_pixel(image, x, y);
			color = int_to_color(pixel);
			new_color.r = clamp_int((int)(color.r * factor), 0, 255);
			new_color.g = clamp_int((int)(color.g * factor), 0, 255);
			new_color.b = clamp_int((int)(color.b * factor), 0, 255);
			mlx_put_pixel(image, x, y, color_to_int(new_color));
			x++;
		}
		y++;
	}
}

void	apply_contrast(t_image *image, double factor)
{
	int		x;
	int		y;
	int		pixel;
	t_color	color;
	t_color	new_color;

	if (!image)
		return ;
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			pixel = mlx_get_pixel(image, x, y);
			color = int_to_color(pixel);
			new_color.r = clamp_int((int)(((color.r / 255.0 - 0.5) * factor
							+ 0.5) * 255), 0, 255);
			new_color.g = clamp_int((int)(((color.g / 255.0 - 0.5) * factor
							+ 0.5) * 255), 0, 255);
			new_color.b = clamp_int((int)(((color.b / 255.0 - 0.5) * factor
							+ 0.5) * 255), 0, 255);
			mlx_put_pixel(image, x, y, color_to_int(new_color));
			x++;
		}
		y++;
	}
}

void	apply_blur(t_mlx *mlx, t_image **image, int radius)
{
	t_image	*original;
	t_image	*blurred;
	int		x;
	int		y;
	int		offset_x;
	int		offset_y;
	int		samples;
	int		total_r;
	int		total_g;
	int		total_b;
	int		pixel;
	t_color	color;
	t_color	avg_color;
	int		sample_x;
	int		sample_y;

	if (!image || !*image || !mlx || radius <= 0)
		return ;
	original = *image;
	blurred = create_image(mlx, original->width, original->height);
	if (!blurred)
		return ;
	y = 0;
	while (y < original->height)
	{
		x = 0;
		while (x < original->width)
		{
			total_r = 0;
			total_g = 0;
			total_b = 0;
			samples = 0;
			offset_y = -radius;
			while (offset_y <= radius)
			{
				offset_x = -radius;
				while (offset_x <= radius)
				{
					sample_x = x + offset_x;
					sample_y = y + offset_y;
					if (sample_x >= 0 && sample_x < original->width
						&& sample_y >= 0 && sample_y < original->height)
					{
						pixel = mlx_get_pixel(original, sample_x, sample_y);
						color = int_to_color(pixel);
						total_r += color.r;
						total_g += color.g;
						total_b += color.b;
						samples++;
					}
					offset_x++;
				}
				offset_y++;
			}
			if (samples > 0)
			{
				avg_color.r = total_r / samples;
				avg_color.g = total_g / samples;
				avg_color.b = total_b / samples;
				mlx_put_pixel(blurred, x, y, color_to_int(avg_color));
			}
			x++;
		}
		y++;
	}
	destroy_image(mlx, original);
	*image = blurred;
}
