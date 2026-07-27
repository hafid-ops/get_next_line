# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherif <hcherif@student.42warsaw.pl>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/27 13:52:33 by hcherif           #+#    #+#              #
#    Updated: 2026/07/27 15:01:07 by hcherif          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a 
CC = cc 
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs 
MAIN = main.c 
SRC = get_next_line /
	get_next_line_utils

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

%.o%.c: $(SRCS)
    @$(CC) $(CFLAGS) -c -o $< $@ -D BUFFER_SIZE=42 <files>.c 

$(NAME): $(OBJS)
    @$(AR) $@ $^

all: $(NAME)

clean:
    @rm -fr $(OBJS) 
    @echo "gg"

fclean : clean
    @rm -fr $(NAME)

re : fclean all

mm: 
    @$(CC) $(CFLAGS) $(MAIN) $(NAME) -o test -lbsd
    @echo "=================Test START ======================"
    @./test
    @echo "=================END============================="

.PHONY: all clean fclean re mm cmm
 
