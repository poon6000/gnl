/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsangnga <nsangnga@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:37:18 by nsangnga          #+#    #+#             */
/*   Updated: 2024/01/07 19:27:01 by nsangnga         ###   ########.fr       */
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

typedef struct s_gnl
{
	char			*content;
	struct s_gnl	*next;
}	t_gnl;

// Function prototypes for get_next_line.c
char	*get_next_line(int fd);
void	read_to_list(t_gnl **list, int fd);
char	*extract_line(t_gnl **list);
void	update_list(t_gnl **list);
void	free_list(t_gnl **list, t_gnl *clean_node, char *buf);

// Utility function prototypes for get_next_line_utils.c
int		contains_newline(t_gnl *list);
void	append_buffer(t_gnl **list, char *buf);
t_gnl	*find_last_node(t_gnl *list);
// void	process_leftover_chars(t_gnl *last_node, char *buf);
int		length_to_newline(t_gnl *list);
void	ft_copy_str(t_gnl *list, char *next_str);

#endif
