# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 19:33:34 by ralanes           #+#    #+#              #
#    Updated: 2024/03/13 19:07:21 by alexlowen        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = get_next_line.c \
		get_next_line_utils.c \

OBJS =	$(SRC:.c=.o)

INCLUDE = get_next_line.h

$(NAME):$(OBJS)	$(INCLUDE)
	ar -rsc	$(NAME)	$(OBJS)

all: $(NAME)
%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
