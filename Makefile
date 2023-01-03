# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamasson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 15:28:42 by lamasson          #+#    #+#              #
#    Updated: 2022/11/21 20:30:39 by lamasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -rf

NAME	= libftprintf.a

SRCS	= ft_printf.c ft_printf_utils.c

OBJS	= ${SRCS:.c=.o}

LIBFT	= libft

.c.o:
	${CC} ${CFLAGS} $< -c -o $@

${NAME}:	${OBJS}
	make -C ${LIBFT}
	mv libft/libft.a .
	mv libft.a libftprintf.a
	ar rc ${NAME} ${OBJS}

all:	${NAME}

clean:
	make -C ${LIBFT} clean
	${RM} ${OBJS}

fclean: clean
	make -C ${LIBFT} fclean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
