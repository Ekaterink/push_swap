# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mburnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 18:19:52 by mburnett          #+#    #+#              #
#    Updated: 2020/04/07 00:55:04 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMECH = checker
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
OBJSCH = $(SRCH:.c=.o)

SRC =  push_swap_new.c push_swap_first_sort.c checker.c count_operations.c sort_hundred.c\
	   checker_operations_s_p.c checker_validation.c find_functions.c write_functions.c \
	   arguments_string.c flag_v.c

SRCH = checker.c checker_operations_s_p.c checker_validation.c find_functions.c checker_main.c \
	   push_swap_first_sort.c write_functions.c arguments_string.c flag_v.c

all:
		gcc -g $(SRC) LIBFT/*.c -o $(NAME)
			gcc $(SRCH) LIBFT/*.c -o $(NAMECH)

clean:
		rm -rf $(NAME)
			rm -rf $(NAMECH)
