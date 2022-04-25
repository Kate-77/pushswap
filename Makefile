# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 21:32:50 by kmoutaou          #+#    #+#              #
#    Updated: 2022/04/24 02:07:44 by kmoutaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pushswap

CC			= cc

FLAGS		= -Wall -Wextra -Werror

SRCS		= main.c tools/lists.c tools/operations1.c tools/atoi.c \
			  tools/operations2.c tools/sorting1.c tools/sorting2.c

OBJS		= $(SRCS:.c=.o)

HEADERS		= include/pushswap.h

all: 		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
			rm -f $(NAME)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: 	all re clean fclean 
