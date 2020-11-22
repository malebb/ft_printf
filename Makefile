# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 19:40:00 by mlebrun           #+#    #+#              #
#    Updated: 2020/11/22 06:03:58 by mlebrun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_printf.c srcs/display.c srcs/print_integer.c \
srcs/size.c srcs/print_no_integer.c srcs/precision.c srcs/parse.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes/

NAME = libftprintf.a
RM	= rm -rf

.c.o:		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
			make -C libft/
			mv libft/libft.a libftprintf.a
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			make -C libft/ -f Makefile clean
			${RM} ${OBJS}

fclean:		clean
			make -C libft/ -f Makefile fclean
			${RM} ${NAME}

re:			fclean all
