/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:49:00 by ewiese-men        #+#    #+#             */
/*   Updated: 2025/06/13 21:08:04 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*to_alloc;
	unsigned int	index;
	size_t			len;

	len = ft_strlen(s);
	to_alloc = malloc(len + 1);
	if (!to_alloc)
		return (NULL);
	index = 0;
	while (index < len)
	{
		to_alloc[index] = f(index, s[index]);
		index++;
	}
	to_alloc[index] = '\0';
	return (to_alloc);
}
