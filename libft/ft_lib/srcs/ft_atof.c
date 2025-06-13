/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:44:43 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:14:36 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

double	handle_exp(const char *str, double number)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == 'e' || str[i] == 'E')
	{
		i++;
		if (str[i] == '-')
			number /= ft_pow(10, ft_atoi(str + i + 1));
		else if (str[i] == '+')
			number *= ft_pow(10, ft_atoi(str + i + 1));
		else if (ft_isdigit(str[i]))
			number *= ft_pow(10, ft_atoi(str + i));
	}
	return (number);
}

double	get_decimal(const char *str)
{
	double	result;
	double	decimal;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	decimal = ft_atoi(str + i);
	while (ft_isdigit(str[i + j]))
		j++;
	while (j--)
		decimal /= 10;
	result += decimal;
	return (handle_exp(str + i, result));
}

double	ft_atof(const char *str)
{
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (sign * get_decimal(str + i));
}
