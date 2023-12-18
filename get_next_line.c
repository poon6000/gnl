/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:37:03 by nsangnga          #+#    #+#             */
/*   Updated: 2023/12/18 14:03:58 by intrauser        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_list(t_gnl **list)
{
	t_gnl	*temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->content);
		free(temp);
	}
}

void	copy_list_to_string(t_gnl *list, char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (list)
	{
		j = 0;
		while (list->content[j])
		{
			str[i++] = list->content[j++];
		}
		list = list->next;
	}
	str[i] = '\0';
}

char	*extract_line_from_list(t_gnl **list)
{
	size_t	len;
	char	*line;
	t_gnl	*temp;

	if (!list)
		return (NULL);
	len = get_list_length(*list);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		if (find_newline_in_list(temp))
		{
			free(temp->content);
			free(temp);
			break ;
		}
		free(temp->content);
		free(temp);
	}
	return (line);
}

int	read_from_fd_to_list(int fd, t_gnl **list)
{
	char	*buffer;
	ssize_t	bytes_read;
	int		result;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		append_to_list(list, ft_strdup_gnl(buffer));
		if (find_newline_in_list(*list))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read > 0)
		result = 1;
	else if (bytes_read == 0)
	{
		free(buffer);
		return (0);
	}
	else
		result = -1;
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static t_gnl	*list = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_from_fd_to_list(fd, &list) == -1)
		return (NULL);
	line = extract_line_from_list(&list);
	if (!line || !*line)
	{
		free_list(&list);
		return (NULL);
	}
	return (line);
}