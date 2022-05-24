# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 03:53:28 by kmoutaou          #+#    #+#              #
#    Updated: 2022/05/24 05:21:44 by kmoutaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= checker

CC			= cc

FLAGS		= -Wall -Wextra -Werror

SRCS		= main.c tools/get_next_line.c tools/get_next_line_utils.c \
			  tools/atoi.c tools/lists.c tools/operations1.c \
			  tools/operations2.c tools/operations3.c tools/outils.c

OBJS		= $(SRCS:.c=.o)

HEADERS		= /include/checker.h

all: 		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(FLAGS) -D BUFFER_SIZE=5 $(SRCS) -o $(NAME)

clean:
			rm -f $(NAME)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: 	all re clean fclean
