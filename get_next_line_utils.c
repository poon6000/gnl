/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:36:50 by nsangnga          #+#    #+#             */
/*   Updated: 2024/01/07 00:18:00 by intrauser        ###   ########.fr       */
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

void	append_buffer(t_gnl **list, char *buf)
{
	t_gnl	*new_node;
	t_gnl	*last_node;

	last_node = find_last_node(*list);
	new_node = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new_node)
		return ;
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

t_gnl	*find_last_node(t_gnl *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	length_to_newline(t_gnl *list)
{
	int	total_length;
	int	node_length;

	if (!list)
		return (0);
	total_length = 0;
	while (list)
	{
		node_length = 0;
		while (list->content[node_length])
		{
			if (list->content[node_length] == '\n')
			{
				++total_length;
				return (total_length);
			}
			node_length++;
			total_length++;
		}
		list = list->next;
	}
	return (total_length);
}

void	ft_copy_str(t_gnl *list, char *next_str)
{
	int		i;
	int		k;

	k = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				next_str[k++] = '\n';
				next_str[k] = '\0';
				return ;
			}
			next_str[k++] = list->content[i++];
		}
		list = list->next;
	}
	next_str[k] = '\0';
}
