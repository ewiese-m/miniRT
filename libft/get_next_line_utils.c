/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:57:03 by ewiese-m          #+#    #+#             */
/*   Updated: 2024/11/15 17:55:03 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_found_newline(t_gnl_list *list)
{
	char	*ptr;

	while (list)
	{
		ptr = list->str_buffer;
		while (*ptr)
		{
			if (*ptr == '\n')
				return (1);
			ptr++;
		}
		list = list->next;
	}
	return (0);
}

t_gnl_list	*ft_find_last_node(t_gnl_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

void	ft_copy_str(t_gnl_list *list, char *str)
{
	char	*dest;
	char	*src;

	dest = str;
	while (list)
	{
		src = list->str_buffer;
		while (*src)
		{
			if (*src == '\n')
			{
				*dest++ = '\n';
				*dest = '\0';
				return ;
			}
			*dest++ = *src++;
		}
		list = list->next;
	}
	*dest = '\0';
}

int	ft_len_to_newline(t_gnl_list *list)
{
	int		len;
	char	*ptr;

	len = 0;
	while (list)
	{
		ptr = list->str_buffer;
		while (*ptr)
		{
			len++;
			if (*ptr == '\n')
				return (len);
			ptr++;
		}
		list = list->next;
	}
	return (len);
}

void	ft_dealloc(t_gnl_list **list, t_gnl_list *clean_node, char *buf)
{
	t_gnl_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buffer);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->str_buffer[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
