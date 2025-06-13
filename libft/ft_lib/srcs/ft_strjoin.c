/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:24:53 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:04 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		jndex;
	int		loc_size;
	char	*ret_str;

	index = 0;
	jndex = 0;
	loc_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret_str = malloc(loc_size * sizeof(char));
	if (!ret_str)
		return (NULL);
	while (s1[index])
	{
		ret_str[index] = s1[index];
		index++;
	}
	while (s2[jndex])
	{
		ret_str[index + jndex] = s2[jndex];
		jndex++;
	}
	ret_str[index + jndex] = '\0';
	return (ret_str);
}
