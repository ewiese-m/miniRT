/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:18:24 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:04 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
	{
		index++;
	}
	return (index);
}
