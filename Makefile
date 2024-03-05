# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexlowen <alexlowen@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 19:33:34 by ralanes           #+#    #+#              #
#    Updated: 2024/03/05 17:37:44 by alexlowen        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

# Compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Sources
SRC = get_next_line.c \
		get_next_line_utils.c \

OBJS =	$(SRC:.c=.o)

# Linking
INCLUDE = get_next_line.h

$(NAME):$(OBJS)	$(INCLUDE)
	ar -rsc	$(NAME)	$(OBJS)

# Default target for compilation
all: $(NAME)

# Generate .o from respective .c
%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

# Clean objects
clean:
	rm -f $(OBJS)

# Clean objects and executable
fclean: clean
	rm -f $(NAME)

# Clean objects and executable and then compilation but just OBJS
re: fclean all

# Key words
.PHONY: all clean fclean re
