# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralanes <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 19:33:34 by ralanes           #+#    #+#              #
#    Updated: 2024/02/20 19:33:37 by ralanes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_RESET = \033[0m
COLOR_GREEN = \033[32m
COLOR_YELLOW = \033[33m
COLOR_AZUL = \033[34m

SRC = get_next_line.c
	get_next_line_utils.c

OBJS = $(SRC: .c=.o)

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM_RF = rm -rf
NAME = get_next_line

all : $(NAME)

$(NAME) : $(OBJS)
		@echo "$(COLOR_GREEN)Compilacion en 3, 2, 1 ...$(COLOR_RESET)"
		@ar rcs $(NAME) $(OBJS)
%.o : %.c 
		$(CC) $(CCFLAGS) -c -o $@ $<

clean :
	@echo "$(COLOR_AZUL)Borrando todas las cositas...$(COLOR_RESET)"
	@$(RM_RF) $(NAME) $(OBJS)

 	@$(RM_RF) $(OBJS)

 fclean :
 	@$(RM_RF) $(NAME) $(OBJS)

re: fclean all

.PHONY : all clean fclean re
