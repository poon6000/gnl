/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:37:03 by nsangnga          #+#    #+#             */
/*   Updated: 2023/12/08 11:36:09 by intrauser        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_buffer(char *buffer, char *addition)
{
	char	*new_buffer;

	new_buffer = ft_strjoin_gnl(buffer, addition);
	free(buffer);
	return (new_buffer);
}

int	read_and_store(int fd, char **buffer)
{
	char	read_buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (bytes_read);

		read_buffer[bytes_read] = '\0';
		*buffer = update_buffer(*buffer, read_buffer);
		if (!*buffer)
			return (-1);

		if (ft_strchr_gnl(read_buffer, '\n'))
			break ;
	}
	return (bytes_read);
}


t_gnl	*get_fd_node(t_gnl **head, int fd)
{
	t_gnl	*tmp;

	if (!head)
		return (NULL);
	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_gnl *)malloc(sizeof(t_gnl));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	tmp->content = NULL;
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}

// t_list	*ft_create_new_node(void)
// {
// 	t_list	*new_node;

// 	new_node = (t_list *)malloc(sizeof(t_list));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->node_content = NULL;
// 	new_node->next = NULL;
// 	return (new_node);
// }

// void	ft_listadd_back(t_list **head, t_list *new_node)
// {
// 	t_list	*temp;

// 	if (!head || !new_node)
// 		return ;
// 	if (*head == NULL)
// 	{
// 		*head = new_node;
// 		return ;
// 	}
// 	temp = *head;
// 	while (temp->next)
// 		temp = temp->next;
// 	temp->next = new_node;
// }

// void	free_linked_list(t_list **head)
// {
// 	t_list	*temp;
// 	t_list	*next_node;

// 	if (!head || !*head)
// 		return ;
// 	temp = *head;
// 	while (temp)
// 	{
// 		next_node = temp->next;
// 		free(temp->node_content);
// 		free(temp);
// 		temp = next_node;
// 	}
// 	*head = NULL;
// }

// char	*get_next_line(int fd)
// {
// 	static t_list	*head = NULL;
// 	char			buffer[BUFFER_SIZE + 1];
// 	ssize_t			bytes_read;
// 	char			*next_line;

// 	if (fd < 0 || BUFFER_SIE <= 0 || read(fd, &next_line, 0) < 0)
// 		return (NULL);
// 	if (!head)
// 		head = ft_create_new_node();
// 	while (1)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read < 0)
// 			return (NULL);
// 		buffer[bytes_read] = '\0';
// 		append_buffer_to_list(&head, buffer);
// 		// Additional logic for appending buffer to linked list goes here
//         // Check if buffer contains a newline character
// 		if (newline_found_in_buffer_or_EOF(buffer) || bytes_read < BUFFER_SIZE)
// 			break ;
// 	}
// 	line = extract_line_from_list(&head);  // Function to extract the line from the linked list
// 	cleanup_list(&head); // Function to cleanup or rearrange the linked list

// 	return (line);
// }
