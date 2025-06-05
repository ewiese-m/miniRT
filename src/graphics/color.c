/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 18:12:38 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_color	create_color(int r, int g, int b)
{
	t_color	color;

	color.r = (r < 0) ? 0 : (r > 255) ? 255 : r;
	color.g = (g < 0) ? 0 : (g > 255) ? 255 : g;
	color.b = (b < 0) ? 0 : (b > 255) ? 255 : b;
	return (color);
}

int	color_to_int(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (color.r < 0) ? 0 : (color.r > 255) ? 255 : color.r;
	g = (color.g < 0) ? 0 : (color.g > 255) ? 255 : color.g;
	b = (color.b < 0) ? 0 : (color.b > 255) ? 255 : color.b;
	return ((r << 16) | (g << 8) | b);
}

t_color	int_to_color(int color)
{
	t_color	result;

	result.r = (color >> 16) & 0xFF;
	result.g = (color >> 8) & 0xFF;
	result.b = color & 0xFF;
	return (result);
}

t_color	color_multiply(t_color color, double factor)
{
	t_color	result;

	if (factor < 0)
		factor = 0;
	result.r = (int)(color.r * factor);
	result.g = (int)(color.g * factor);
	result.b = (int)(color.b * factor);
	result.r = (result.r > 255) ? 255 : result.r;
	result.g = (result.g > 255) ? 255 : result.g;
	result.b = (result.b > 255) ? 255 : result.b;
	return (result);
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color	result;

	result.r = c1.r + c2.r;
	result.g = c1.g + c2.g;
	result.b = c1.b + c2.b;
	result.r = (result.r > 255) ? 255 : result.r;
	result.g = (result.g > 255) ? 255 : result.g;
	result.b = (result.b > 255) ? 255 : result.b;
	return (result);
}

t_color	color_blend(t_color c1, t_color c2, double ratio)
{
	t_color	result;

	if (ratio < 0)
		ratio = 0;
	if (ratio > 1)
		ratio = 1;
	result.r = (int)(c1.r * (1.0 - ratio) + c2.r * ratio);
	result.g = (int)(c1.g * (1.0 - ratio) + c2.g * ratio);
	result.b = (int)(c1.b * (1.0 - ratio) + c2.b * ratio);
	return (result);
}

t_color	color_modulate(t_color c1, t_color c2)
{
	t_color	result;

	result.r = (c1.r * c2.r) / 255;
	result.g = (c1.g * c2.g) / 255;
	result.b = (c1.b * c2.b) / 255;
	return (result);
}

bool	color_equals(t_color c1, t_color c2)
{
	return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b);
}

t_color	color_clamp(t_color color)
{
	t_color	result;

	result.r = (color.r < 0) ? 0 : (color.r > 255) ? 255 : color.r;
	result.g = (color.g < 0) ? 0 : (color.g > 255) ? 255 : color.g;
	result.b = (color.b < 0) ? 0 : (color.b > 255) ? 255 : color.b;
	return (result);
}

double	color_luminance(t_color color)
{
	return ((0.299 * color.r + 0.587 * color.g + 0.114 * color.b) / 255.0);
}

t_color	color_desaturate(t_color color, double amount)
{
	double	gray;
	t_color	result;

	if (amount < 0)
		amount = 0;
	if (amount > 1)
		amount = 1;
	gray = color_luminance(color) * 255.0;
	result.r = (int)(color.r * (1.0 - amount) + gray * amount);
	result.g = (int)(color.g * (1.0 - amount) + gray * amount);
	result.b = (int)(color.b * (1.0 - amount) + gray * amount);
	return (color_clamp(result));
}

t_color	color_contrast(t_color color, double factor)
{
	t_color	result;
	double	f;

	f = (259.0 * (factor + 255.0)) / (255.0 * (259.0 - factor));
	result.r = (int)(f * (color.r - 128) + 128);
	result.g = (int)(f * (color.g - 128) + 128);
	result.b = (int)(f * (color.b - 128) + 128);
	return (color_clamp(result));
}
