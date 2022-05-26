# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoutaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 21:32:50 by kmoutaou          #+#    #+#              #
#    Updated: 2022/05/26 02:21:17 by kmoutaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

BNAME		= checker_bonus

CC			= cc

FLAGS		= -Wall -Wextra -Werror

SRCS		= push_swap.c tools/lists.c tools/operations1.c tools/atoi.c \
			  tools/operations2.c tools/short_sort.c tools/sort_array.c \
			  tools/long_sort1.c tools/long_sort2.c tools/operations3.c

BSRCS		= checker/checker.c checker/tools/get_next_line.c \
			  checker/tools/get_next_line_utils.c checker/tools/outils.c \
			  tools/lists.c checker/tools/operations1.c tools/atoi.c \
			  checker/tools/operations2.c checker/tools/operations3.c


OBJS		= $(SRCS:.c=.o)

BOBJS		= $(BSRCS:.c=.o)

HEADERS		= include/pushswap.h checker/include.checker.h

all: 		$(NAME)

bonus:		$(BNAME)

$(NAME):	$(SRCS)
			$(CC) $(FLAGS) $(SRCS) -o $(NAME)

$(BNAME):	$(BSRCS)
			$(CC) $(FLAGS) $(BSRCS) -o $(BNAME)

clean:
			rm -f $(NAME) $(BNAME)

fclean: 	clean
			rm -f $(NAME) $(BNAME)

re: 		fclean all

.PHONY: 	all re clean fclean 
