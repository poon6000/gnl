/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:37:18 by nsangnga          #+#    #+#             */
/*   Updated: 2024/01/03 22:09:58 by intrauser        ###   ########.fr       */
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
char	*extract_line(t_gnl *list);
void	update_list(t_gnl **list);
void	append_buffer(t_gnl **list, char *buf);

// Utility function prototypes for get_next_line_utils.c
int		contains_newline(t_gnl *list);
int		length_to_newline(t_gnl *list);
void	copy_from_list(t_gnl *list, char *str);
t_gnl	*find_last_node(t_gnl *list);
void	free_list(t_gnl *list);

#endif
