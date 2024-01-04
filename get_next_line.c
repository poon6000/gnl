/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:37:03 by nsangnga          #+#    #+#             */
/*   Updated: 2024/01/04 16:17:47 by intrauser        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(t_gnl *list)
{
	int		line_length;
	char	*line;
	t_gnl	*temp;
	int		i;

	if (!list)
		return (NULL);
	line_length = length_to_newline(list);
	line = (char *)malloc(sizeof(char) * (line_length + 1));
	if (!line)
		return (NULL);
	i = 0;
	temp = list;
	while (temp && i < line_length)
	{
		if (temp->content[0])
		{
			line[i++] = temp->content[0];
			temp->content++;
		}
		else
			temp = temp->next;
	}
	line[i] = '\0';
	return (line);
}

void	read_to_list(t_gnl **list, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*temp_buf;
	int		i;

	while (!contains_newline(*list))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return ;
		buffer[bytes_read] = '\0';
		temp_buf = malloc(bytes_read + 1);
		if (!temp_buf)
			return ;
		i = 0;
		while (i < bytes_read)
		{
			temp_buf[i] = buffer[i];
			i++;
		}
		temp_buf[i] = '\0';
		append_buffer(list, temp_buf);
	}
}

// char	*get_next_line(int fd)
// {
// 	static t_gnl	*list = NULL;
// 	char			*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
// 		return (NULL);
// 	read_to_list(&list, fd);
// 	if (!list)
// 		return (NULL);
// 	line = extract_line(list);
// 	update_list(&list);
// 	return (line);
// }
