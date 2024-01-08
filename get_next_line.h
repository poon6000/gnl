/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:37:18 by nsangnga          #+#    #+#             */
/*   Updated: 2024/01/08 18:49:59 by intrauser        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

// Function prototypes for get_next_line.c
char	*get_next_line(int fd);
void	read_to_list(t_list **list, int fd);
char	*extract_line(t_list **list);
void	update_list(t_list **list);
void	update_list_helper(t_list **list, char *buf, t_list *last_node, \
t_list *clean_node);
// Utility function prototypes for get_next_line_utils.c
int		contains_newline(t_list *list);
void	append_buffer(t_list **list, char *buf);
int		length_to_newline(t_list *list);
void	ft_copy_str(t_list *list, char *next_str);
void	free_list(t_list **list, t_list *clean_node, char *buf);
#endif
