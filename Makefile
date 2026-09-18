# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/27 13:52:33 by hcherif           #+#    #+#              #
#    Updated: 2026/08/10 16:53:34 by hcherif          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

MAIN = main.c
TEST = gnl_test

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST)

re: fclean all

mm: $(NAME)
	$(CC) $(CFLAGS) $(MAIN) $(NAME) -o $(TEST)
	./$(TEST)

.PHONY: all clean fclean re mm