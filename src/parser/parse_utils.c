/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/11 15:44:51 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	ft_atof(const char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		decimal_places;

	result = 0.0;
	decimal = 0.0;
	sign = 1;
	decimal_places = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str && ft_isdigit(*str))
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str && ft_isdigit(*str))
		{
			decimal = decimal * 10.0 + (*str++ - '0');
			decimal_places++;
		}
	}
	while (decimal_places--)
		decimal /= 10.0;
	return (sign * (result + decimal));
}

bool	parse_vector(t_vec3 *vec, char *str)
{
	char	**coords;
	int		i;

	if (!str || !vec)
		return (false);
	coords = ft_split(str, ',');
	if (!coords)
		return (false);
	i = 0;
	while (coords[i])
		i++;
	if (i != 3)
	{
		ft_free_split(coords);
		return (error_message("Vector must have 3 coordinates"));
	}
	vec->x = ft_atof(coords[0]);
	vec->y = ft_atof(coords[1]);
	vec->z = ft_atof(coords[2]);
	ft_free_split(coords);
	return (true);
}

bool	parse_color(t_color *color, char *str)
{
	char	**values;
	int		i;

	if (!str || !color)
		return (false);
	values = ft_split(str, ',');
	if (!values)
		return (false);
	i = 0;
	while (values[i])
		i++;
	if (i != 3)
	{
		ft_free_split(values);
		return (error_message("Color must have 3 values"));
	}
	color->r = ft_atoi(values[0]);
	color->g = ft_atoi(values[1]);
	color->b = ft_atoi(values[2]);
	ft_free_split(values);
	return (validate_color(color));
}

static int	count_words(char *str)
{
	int		count;
	bool	in_word;

	count = 0;
	in_word = false;
	while (*str)
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
		{
			if (!in_word)
			{
				count++;
				in_word = true;
			}
		}
		else
			in_word = false;
		str++;
	}
	return (count);
}

char	**ft_split_whitespace(char *str)
{
	char	**result;
	int		words;
	int		i;
	int		j;
	int		start;

	if (!str)
		return (NULL);
	words = count_words(str);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < words)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		start = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		result[j] = ft_substr(str, start, i - start);
		if (!result[j++])
		{
			while (--j >= 0)
				free(result[j]);
			free(result);
			return (NULL);
		}
	}
	result[j] = NULL;
	return (result);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
