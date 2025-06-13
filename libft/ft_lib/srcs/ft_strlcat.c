/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:14:26 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:07:04 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	index;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	index = 0;
	if (size == 0)
		return (src_len);
	if (size <= dst_len)
		return (src_len + size);
	while (src[index] && index < size - dst_len - 1)
	{
		dst[dst_len + index] = src[index];
		index++;
	}
	dst[dst_len + index] = '\0';
	return (dst_len + src_len);
}
