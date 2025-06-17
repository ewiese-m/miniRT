/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:42:45 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 01:56:02 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_format(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == 'e' || str[i] == 'E')
	{
		i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	return (str[i] == '\0');
}

int	ft_isfloat(const char *str)
{
	return (check_format(str));
}
