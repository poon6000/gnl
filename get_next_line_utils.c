/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsangnga <nsangnga@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:36:50 by nsangnga          #+#    #+#             */
/*   Updated: 2024/01/14 13:27:24 by nsangnga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	contains_newline(t_list *list)
{
	char	*current_ptr;

	while (list)
	{
		if (list->next == NULL)
		{
			current_ptr = list->content;
			while (*current_ptr)
			{
				if (*current_ptr == '\n')
					return (1);
				current_ptr++;
			}
		}
		list = list->next;
	}
	return (0);
}

void	append_buffer(t_list **list, char *temp_buf)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		free_list(list, NULL, NULL);
		free (temp_buf);
		return ;
	}
	new_node->content = temp_buf;
	new_node->next = NULL;
	if (!*list)
		*list = new_node;
	else
	{
		last_node = *list;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

int	length_to_newline(t_list *list)
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

void	ft_copy_str(t_list *list, char *next_str)
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
				break ;
			}
			next_str[k++] = list->content[i++];
		}
		list = list->next;
	}
	next_str[k] = '\0';
}

void	free_list(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

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
