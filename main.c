/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:18:22 by intrauser         #+#    #+#             */
/*   Updated: 2023/12/18 14:13:29 by intrauser        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

// int	main(void)
// 	{
// 	int		fd = open("test.txt", O_RDONLY);
// 	char	*line;

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}

// 	close(fd);
// 	return (0);
// 	}

// #include <stdio.h>

// int main() {
//     t_gnl *list = NULL;

//     // Manually append lines to the list
//     append_to_list(&list, ft_strdup_gnl("Hello, World!\n"));
//     append_to_list(&list, ft_strdup_gnl("Welcome to get_next_line testing.\n"));
//     append_to_list(&list, ft_strdup_gnl("This is a simple file."));

//     // Extract the first line from the list
//     char *extracted_line = extract_line_from_list(&list);
//     if (extracted_line) {
//         printf("Extracted Line: %s\n", extracted_line);
//         free(extracted_line);
//     }

//     // Free the remaining list
//     free_list(&list);
//     return 0;
// }

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd;
    t_gnl *list = NULL;

    // Open a file
    fd = open("test.txt", O_RDONLY); // Replace "test.txt" with your test file path
    if (fd == -1) {
        printf("Error opening file\n");
        return 1;
    }

    // Read from file to list
    if (read_from_fd_to_list(fd, &list) == -1) {
        printf("Error reading from file\n");
        close(fd);
        return 1;
    }

    // Print the contents of the list for debugging
    t_gnl *current_node = list;
    while (current_node != NULL) {
        printf("Node content: '%s'\n", current_node->content);
        current_node = current_node->next;
    }

    // Extract and print the first line from the list
    char *extracted_line = extract_line_from_list(&list);
    if (extracted_line) {
        printf("Extracted Line: %s\n", extracted_line);
        free(extracted_line);
    }

    // Free the remaining list
    free_list(&list);
    close(fd);
    return 0;
}
