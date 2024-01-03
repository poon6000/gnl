/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:18:22 by intrauser         #+#    #+#             */
/*   Updated: 2024/01/03 22:15:59 by intrauser        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  // For open()
#include <unistd.h> // For read()

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	(void)argc;
// 	fd = open(argv[1], O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }

//check append_buffer function
// int main()
// {
//     t_gnl *list = NULL;

//     append_buffer(&list, "First line\n");
//     append_buffer(&list, "Second line\n");
//     append_buffer(&list, "Third line\n");

//     // Print the list
//     t_gnl *current = list;
//     while (current != NULL)
//     {
//         printf("%s", current->content);
//         current = current->next;
//     }

//     // Free the list
//     while (list != NULL)
//     {
//         t_gnl *temp = list;
//         list = list->next;
//         free(temp);
//     }

//     return 0;
// }

//check contains_newline function
// int main()
// {
//     // Test case 1: List with a string that contains a newline
//     t_gnl *test1 = (t_gnl *)malloc(sizeof(t_gnl));
//     test1->content = "Line with newline\n";
//     test1->next = NULL;
//     printf("Test 1 - Should find a newline: %s\n", contains_newline(test1) ? "Passed" : "Failed");

//     // Test case 2: List with a string that does not contain a newline
//     t_gnl *test2 = (t_gnl *)malloc(sizeof(t_gnl));
//     test2->content = "Line without newline";
//     test2->next = NULL;
//     printf("Test 2 - Should not find a newline: %s\n", contains_newline(test2) ? "Failed" : "Passed");

//     // Test case 3: List with multiple nodes, newline in second node
//     t_gnl *test3 = (t_gnl *)malloc(sizeof(t_gnl));
//     test3->content = "First line";
//     test3->next = (t_gnl *)malloc(sizeof(t_gnl));
//     test3->next->content = "Second line with newline\n";
//     test3->next->next = NULL;
//     printf("Test 3 - Should find a newline in second node: %s\n", contains_newline(test3) ? "Passed" : "Failed");

//     // Free allocated memory
//     free(test1);
//     free(test2);
//     free(test3->next);
//     free(test3);

//     return 0;
// }

void print_and_free_list(t_gnl *list)
{
    while (list)
    {
        printf("%s", list->content);
        t_gnl *temp = list;
        list = list->next;
        free(temp->content);
        free(temp);
    }
}

int main(int argc, char **argv)
{
    int    fd;
    t_gnl *list = NULL;

    if (argc != 2)
    {
        printf("Usage: %s test.txt\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    read_to_list(&list, fd);
    close(fd);

    print_and_free_list(list);

    return 0;
}