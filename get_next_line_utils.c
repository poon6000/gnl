/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:36:50 by nsangnga          #+#    #+#             */
/*   Updated: 2024/01/04 23:04:09 by intrauser        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	contains_newline(t_gnl *list)
{
	char	*current_content;

	if (!list)
		return (0);
	while (list)
	{
		current_content = list->content;
		while (*current_content != '\0')
		{
			if (*current_content == '\n')
				return (1);
			current_content++;
		}
		list = list->next;
	}
	return (0);
}

t_gnl	*ft_find_last_node(t_gnl *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	append_buffer(t_gnl **list, char *buf)
{
	t_gnl	*new_node;
	t_gnl	*last_node;

	last_node = ft_find_last_node(*list);
	new_node = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new_node)
		return ;
	if (!*list)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

int	length_to_newline(t_gnl *list)
{
	int	total_length;
	int	node_length;

	total_length = 0;
	while (list != NULL)
	{
		node_length = 0;
		while (list->content[node_length] != '\0')
		{
			if (list->content[node_length] == '\n')
			{
				total_length += (node_length + 1);
				return (total_length);
			}
			node_length++;
		}
		total_length += node_length;
		list = list->next;
	}
	return (total_length);
}


void	free_list(t_gnl *list)
{
	t_gnl	*temp;

	while (list)
	{
		temp = list->next;
		free(list->content);
		free(list);
		list = temp;
	}
}
