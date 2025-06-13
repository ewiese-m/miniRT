/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:40:35 by ewiese-men        #+#    #+#             */
/*   Updated: 2025/06/13 21:08:04 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strdup(const char *s)
{
	char	*to_alloc;
	size_t	len;

	len = ft_strlen(s);
	to_alloc = malloc(len + 1);
	if (!to_alloc)
		return (NULL);
	ft_strlcpy(to_alloc, s, len + 1);
	return (to_alloc);
}
