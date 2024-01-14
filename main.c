/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsangnga <nsangnga@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:18:22 by intrauser         #+#    #+#             */
/*   Updated: 2024/01/14 15:57:24 by nsangnga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  // For open()
#include <unistd.h> // For read()

int	main(int argc, char **argv)
{
    int fd;
    char *line;

    // Check if a file name is provided
    if (argc != 2)
    {
        printf("Usage: %s test.txt\n", argv[0]);
        return (1);
    }

    // Open the file
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    // Read lines from the file and print them
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Free the line after printing
    }

    // Close the file
    close(fd);
    return (0);
}
// int	main(void) 
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }

//check append_buffer function
// int main()
// {
//     t_list *list = NULL;

//     append_buffer(&list, "First line\n");
//     append_buffer(&list, "Second line\n");
//     append_buffer(&list, "Third line\n");

//     // Print the list
//     t_list *current = list;
//     while (current != NULL)
//     {
//         printf("%s", current->content);
//         current = current->next;
//     }

//     // Free the list
//     while (list != NULL)
//     {
//         t_list *temp = list;
//         list = list->next;
//         free(temp);
//     }

//     return 0;
// }

// check contains_newline function
// int main()
// {
//     // Test case 1: List with a string that contains a newline
//     t_list *test1 = (t_list *)malloc(sizeof(t_list));
//     test1->content = "Line with newline\n";
//     test1->next = NULL;
//     printf("Test 1 - Should find a newline: %s\n", contains_newline(test1) ? "Passed" : "Failed");

//     // Test case 2: List with a string that does not contain a newline
//     t_list *test2 = (t_list *)malloc(sizeof(t_list));
//     test2->content = "Line without newline";
//     test2->next = NULL;
//     printf("Test 2 - Should not find a newline: %s\n", contains_newline(test2) ? "Failed" : "Passed");

//     // Test case 3: List with multiple nodes, newline in second node
//     t_list *test3 = (t_list *)malloc(sizeof(t_list));
//     test3->content = "First line";
//     test3->next = (t_list *)malloc(sizeof(t_list));
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

//check read
// void print_and_free_list(t_list *list)
// {
//     while (list)
//     {
//         printf("%s", list->content);
//         t_list *temp = list;
//         list = list->next;
//         free(temp->content);
//         free(temp);
//     }
// }

// int main(int argc, char **argv)
// {
//     int    fd;
//     t_list *list = NULL;

//     if (argc != 2)
//     {
//         printf("Usage: %s test.txt\n", argv[0]);
//         return 1;
//     }

//     fd = open(argv[1], O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }

//     read_to_list(&list, fd);
//     close(fd);

//     print_and_free_list(list);

//     return 0;
// }

//check length to newline

// int main()
// {
//     // Test 1: List with a single node containing a newline
//     t_list test1;
//     test1.content = "Hello\n";
//     test1.next = NULL;
//     char *line1 = extract_line(&test1);
//     printf("Test 1 - Line: %s", line1);
//     free(line1);

//     // Test 2: List with three nodes, newline in the second node
//     t_list test2a, test2b, test2c;
//     test2a.content = "Hello ";
//     test2a.next = &test2b;
//     test2b.content = "World ";
//     test2b.next = &test2c;
// 	test2c.content = "Again!\n";
// 	test2c.next = NULL;
//     char *line2 = extract_line(&test2a);
//     printf("Test 2 - Line: %s", line2);
//     free(line2);

//     // Test 3: List with a single node without a newline
//     t_list test3;
//     test3.content = "Hello";
//     test3.next = NULL;
//     char *line3 = extract_line(&test3);
//     printf("Test 3 - Line: %s", line3);
//     free(line3);

//     return 0;
// }

// check extract_line
// int main() {
//     // Create a simple linked list
//     t_list *list = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     t_list *node3 = malloc(sizeof(t_list));

//     // Simulate list after reading some data
//     list->content = "Hello\n";
//     list->next = node2;
//     node2->content = "World\n";
//     node2->next = node3;
//     node3->content = "This is a test\n";
//     node3->next = NULL;

//     // Extract and print lines using ft_get_line
//     char *line;
//     while ((line = extract_line(list)) != NULL) {
//         printf("%s", line);
//         free(line);  // Free the line after printing
//         list = list->next; // Move to the next node for next call
//     }

//     // Free the list
//     while (list != NULL) {
//         t_list *temp = list;
//         list = list->next;
//         free(temp->content);
//         free(temp);
//     }

//     return 0;
// }
