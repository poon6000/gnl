/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:36:50 by nsangnga          #+#    #+#             */
/*   Updated: 2023/12/14 17:43:35 by intrauser        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	append_to_list(t_gnl **list, char *content)
{
	t_gnl	*new_node;
	t_gnl	*last_node;

	new_node = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->next = NULL;
	if (*list == NULL)
		*list = new_node;
	else
	{
		last_node = *list;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen_gnl(s) + 1;
	dup = (char *)malloc(sizeof(char) * len);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	find_newline_in_list(t_gnl *list)
{
	char	*current_content;

	while (list)
	{
		current_content = list->content;
		while (current_content && *current_content)
		{
			if (*current_content == '\n')
				return (1);
			current_content++;
		}
		list = list->next;
	}
	return (0);
}

size_t	get_list_length(t_gnl *list)
{
	size_t	length;

	length = 0;
	while (list)
	{
		length += ft_strlen_gnl(list->content);
		list = list->next;
	}
	return (length);
}
