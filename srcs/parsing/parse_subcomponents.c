/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subcomponents.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 21:07:41 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 03:02:53 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_parse_point(char *line, t_tuple *tuple)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || !ft_isfloat(tab[0])
		|| !ft_isfloat(tab[1]) || !ft_isfloat(tab[2]))
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_POINT);
		return (0);
	}
	tuple->x = ft_atof(tab[0]);
	tuple->y = ft_atof(tab[1]);
	tuple->z = ft_atof(tab[2]);
	tuple->w = 1;
	ft_free_2d_list(tab);
	return (1);
}

int	ft_parse_vector(char *line, t_vector *vector)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || !ft_isfloat(tab[0])
		|| !ft_isfloat(tab[1]) || !ft_isfloat(tab[2]))
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_VECTOR);
		return (0);
	}
	vector->x = ft_atof(tab[0]);
	vector->y = ft_atof(tab[1]);
	vector->z = ft_atof(tab[2]);
	vector->w = 0;
	ft_free_2d_list(tab);
	if (tuple_mag(*vector) < 1 - EPSILON
		|| tuple_mag(*vector) > 1 + EPSILON)
	{
		ft_error(ERROR_VECTOR_NORMALIZED);
		return (0);
	}
	return (1);
}

int	ft_parse_color(char *line, t_color *color)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (!tab)
		return (ft_error(ERROR_MALLOC), 0);
	if (ft_tablen(tab) != 3 || !ft_isint(tab[0])
		|| !ft_isint(tab[1]) || !ft_isint(tab[2]))
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_COLOR);
		return (0);
	}
	color->r = 1 / 255.0 * ft_atoi(tab[0]);
	color->g = 1 / 255.0 * ft_atoi(tab[1]);
	color->b = 1 / 255.0 * ft_atoi(tab[2]);
	if (color->r < 0 || color->r > 1
		|| color->g < 0 || color->g > 1
		|| color->b < 0 || color->b > 1)
	{
		ft_free_2d_list(tab);
		ft_error(ERROR_PARSING_COLOR);
		return (0);
	}
	ft_free_2d_list(tab);
	return (1);
}
