/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:56:57 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/04/19 18:58:45 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gnl_clean_list(t_gnl_list **list)
{
	t_gnl_list	*last_node;
	t_gnl_list	*clean_node;
	int			i;
	int			k;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_gnl_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = ft_find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->str_buffer[i] && last_node->str_buffer[i] != '\n')
		++i;
	while (last_node->str_buffer[i] && last_node->str_buffer[++i])
		buf[k++] = last_node->str_buffer[i];
	buf[k] = '\0';
	clean_node->str_buffer = buf;
	clean_node->next = NULL;
	ft_dealloc(list, clean_node, buf);
}

char	*get_line(t_gnl_list *list)
{
	int		str_len;
	char	*next_str;

	str_len = ft_len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	ft_copy_str(list, next_str);
	return (next_str);
}

void	append(t_gnl_list **list, char *buf)
{
	t_gnl_list	*new_node;
	t_gnl_list	*last_node;

	new_node = malloc(sizeof(t_gnl_list));
	last_node = ft_find_last_node(*list);
	if (!new_node)
		return ;
	new_node->str_buffer = buf;
	new_node->next = NULL;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
}

void	create_list(t_gnl_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!ft_found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*list = NULL;
	char				*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	gnl_clean_list(&list);
	return (next_line);
}
