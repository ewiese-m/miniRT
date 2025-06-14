/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:19:53 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:03:48 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_color	color_add(t_color c1, t_color c2)
{
	t_color	color;

	color.r = c1.r + c2.r;
	color.g = c1.g + c2.g;
	color.b = c1.b + c2.b;
	return (color);
}

t_color	color_sub(t_color c1, t_color c2)
{
	t_color	color;

	color.r = c1.r - c2.r;
	color.g = c1.g - c2.g;
	color.b = c1.b - c2.b;
	return (color);
}

t_color	color_mult(t_color c1, t_color c2)
{
	t_color	color;

	color.r = c1.r * c2.r;
	color.g = c1.g * c2.g;
	color.b = c1.b * c2.b;
	return (color);
}

t_color	color_scalar(t_color c, double scalar)
{
	t_color	color;

	color.r = c.r * scalar;
	color.g = c.g * scalar;
	color.b = c.b * scalar;
	return (color);
}

int	color_to_int(t_color color)
{
	int		r;
	int		g;
	int		b;

	if (color.r > 1)
		color.r = 1;
	if (color.g > 1)
		color.g = 1;
	if (color.b > 1)
		color.b = 1;
	r = 255 * color.r;
	g = 255 * color.g;
	b = 255 * color.b;
	return (r << 16 | g << 8 | b);
}
