/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:37:18 by nsangnga          #+#    #+#             */
/*   Updated: 2023/12/12 15:23:28 by intrauser        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl
{
	int				fd;
	char			*content;
	struct s_gnl	*next;
}	t_gnl;

// Function prototypes for get_next_line.c
char	*get_next_line(int fd);
int		find_newline_in_list(t_gnl *list);
int		read_from_fd_to_list(int fd, t_gnl **list);
char	*extract_line_from_list(t_gnl **list);
void	free_list(t_gnl **list);

// Function prototypes for get_next_line_utils.c
void	append_to_list(t_gnl **list, char *content);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s);
size_t	get_list_length(t_gnl *list);
void	copy_list_to_string(t_gnl *list, char *str);

#endif
