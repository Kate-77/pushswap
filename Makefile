# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 21:32:50 by kmoutaou          #+#    #+#              #
#    Updated: 2022/04/15 21:35:17 by kmoutaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pushswap

CC			= cc

FLAGS		= -Wall -Wextra -Werror

SRCS		= main.c tools/lists.c tools/operations1.c tools/atoi.c \

OBJS		= $(SRCS:.c=.o)

HEADERS		= .

all: 		$(NAME)

$(NAME):	$(OBJS) 
			ar rcs $(NAME) $(OBJS)

%.o: %.c
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I $(HEADERS)
			ar rcs $(NAME) ${<:.c=.o}

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: 	all re clean fclean 
