/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 07:08:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	validate_light_brightness(double brightness)
{
	if (brightness < MIN_RATIO || brightness > MAX_RATIO)
		return (error_message("Light brightness must be between 0.0 and 1.0"));
	return (true);
}

bool	parse_light_position(t_light *light, char *str)
{
	if (!parse_vector(&light->position, str))
		return (error_message("Invalid light position format"));
	return (true);
}

bool	parse_light_brightness(t_light *light, char *str)
{
	light->brightness = ft_atof(str);
	if (!validate_light_brightness(light->brightness))
		return (false);
	return (true);
}

bool	parse_light_color(t_light *light, char *str)
{
	if (!str)
	{
		light->color.r = 255;
		light->color.g = 255;
		light->color.b = 255;
		return (true);
	}
	if (!parse_color(&light->color, str))
		return (error_message("Invalid light color format"));
	if (!validate_color(&light->color))
		return (false);
	return (true);
}

bool	validate_ambient_ratio(double ratio)
{
	if (ratio < MIN_RATIO || ratio > MAX_RATIO)
		return (error_message("Ambient ratio must be between 0.0 and 1.0"));
	return (true);
}
