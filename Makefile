# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busmanov <busmanov@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 13:20:11 by busmanov          #+#    #+#              #
#    Updated: 2023/01/21 12:28:29 by busmanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
LIB		=	libft/libft.a
HEADER		=	/includes/push_swap.h

CFLAGS = -Wall -Wextra -Werror
CC = gcc
LFT = -L libft -lft

SRCS		=	src/small_sort.c src/main.c src/ps.c \
				src/rotate.c src/operations.c src/push_swap.c \
				src/list.c src/checkings.c src/stack.c

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

all : lib $(NAME)

$(NAME):${OBJS} ${INCLUDES} ${LIB} Makefile
	@$(CC) $(LFT) $(CFLAGS) $(OBJS) -I includes -o $(NAME)

lib:
	make -C ./libft

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re