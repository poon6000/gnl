/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsangnga <nsangnga@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:37:03 by nsangnga          #+#    #+#             */
/*   Updated: 2024/01/07 19:45:49 by nsangnga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_list(t_gnl **list, t_gnl *clean_node, char *buf)
{
	t_gnl	*tmp;

	if (!*list || !list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	if (clean_node)
	{
		*list = NULL;
		if (clean_node->content[0])
			*list = clean_node;
		else
		{
			free(buf);
			free(clean_node);
		}
	}
}

void	update_list(t_gnl **list)
{
	t_gnl	*last_node;
	t_gnl	*clean_node;
	char	*buf;
	int		i;
	int		k;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		free_list (list, NULL, NULL);
		return ;
	}
	clean_node = malloc(sizeof(t_gnl));
	if (!clean_node)
	{
		free (buf);
		free_list (list, NULL, NULL);
		return ;
	}
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		buf[k++] = last_node->content[i];
	buf[k] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	free_list(list, clean_node, buf);
}

char	*extract_line(t_gnl **list)
{
	int		str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	str_len = length_to_newline(*list);
	next_str = malloc(str_len + 1);
	if (!next_str)
	{
		free_list(list, NULL, NULL);
		return (NULL);
	}
	ft_copy_str(*list, next_str);
	return (next_str);
}

void	read_to_list(t_gnl **list, int fd)
{
	int		bytes_read;
	char	*temp_buf;

	while (!contains_newline(*list))
	{
		temp_buf = malloc(BUFFER_SIZE + 1);
		if (!temp_buf)
		{
			free_list(list, NULL, NULL);
			return ;
		}
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(temp_buf);
			if (bytes_read == -1)
				free_list(list, NULL, NULL);
			return ;
		}
		temp_buf[bytes_read] = '\0';
		append_buffer(list, temp_buf);
	}
}
		// if temp_buf have newline
		// break ;

char	*get_next_line(int fd)
{
	static t_gnl	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_to_list(&list, fd);
	if (!list)
		return (NULL);
	line = extract_line(&list);
	if (line)
		update_list(&list);
	return (line);
}
