# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: intrauser <intrauser@student.42bangkok.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 13:18:14 by nsangnga          #+#    #+#              #
#    Updated: 2023/12/12 15:26:02 by intrauser        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 42

SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = $(SRCS:.c=.o)

FILE_TEST = test.txt

%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	@rm -f $(OBJS)
	clear
	./$(NAME) $(FILE_TEST)

.PHONY: all clean fclean re test
