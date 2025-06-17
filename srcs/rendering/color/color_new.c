/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:18:19 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/15 11:32:43 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_color	new_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = b;
	color.b = g;
	return (color);
}
