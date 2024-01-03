/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:37:03 by nsangnga          #+#    #+#             */
/*   Updated: 2024/01/03 22:36:28 by intrauser        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			break ;
		buffer[bytes_read] = '\0';
		temp_buf = malloc(bytes_read + 1);
		if (!temp_buf)
		{
			free(temp_buf);
			return ;
		}
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

char	*get_next_line(int fd)
{
	static t_gnl	*list = NULL;
	char			*line;

	// Check for valid file descriptor and buffer size
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;

	// Read data from file descriptor into the list
	read_to_list(&list, fd);
	if (!list)
		return (NULL);

	// Extract the line from the list
	line = extract_line(list);

	// Update the list by removing the extracted line
	update_list(&list);

	return (line);  // Return the extracted line
}


// char	*get_next_line(int fd)
// {
//     static t_gnl *list = NULL;
//     char          *line;

//     if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
//         return (NULL);

//     read_to_list(&list, fd);
//     if (!list)
//         return (NULL);

//     line = extract_line(list);
//     update_list(&list);

//     return (line);
// }
