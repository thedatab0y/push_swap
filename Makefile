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
LFT = -L libft -lft #search for libft.a in "libft" to link the libft.a using the name -lft.

SRCS		=	src/small_sort.c src/main.c src/ps.c \
				src/rotate.c src/operations.c src/push_swap.c \
				src/list.c src/checkings.c src/stack.c
#SRCS = small_sort.c ps.c turns into small_sort.o ps.o with the help of $(patsubst %.c,%.o,$(SRCS)) which is the dedicated function to do such work.
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

#when make is called, lib is first built, followed by $(NAME) afterwards
all : lib $(NAME)

#for $(NAME) to be built, we need OBJS using directories in INCLUDES and headers in LIB. NAME is dependant to those.
$(NAME):${OBJS} ${INCLUDES} ${LIB} Makefile
	@$(CC) $(LFT) $(CFLAGS) $(OBJS) -I includes -o $(NAME)
#runs the make in ./libft
lib:
	make -C ./libft

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@# "-c $< -o $@" compile the "srs files $< into an obj files $@"

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re
