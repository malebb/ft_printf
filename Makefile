# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 19:40:00 by mlebrun           #+#    #+#              #
#    Updated: 2020/11/27 11:33:41 by mlebrun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c srcs/utils/display.c srcs/integer/print_integer.c \
srcs/integer/print_integer_utils.c srcs/integer/print_integer_utils_2.c \
srcs/utils/size.c srcs/no_integer/print_no_integer.c \
srcs/no_integer/print_no_integer_utils.c srcs/utils/precision.c \
srcs/parse/parse.c srcs/float/display_float.c \
srcs/float/ft_display_float_utils.c srcs/float/ft_display_float_utils_2.c \
srcs/float/ft_display_float_utils_3.c \
srcs/float/ft_display_float_utils_4.c srcs/parse/parse_utils.c \
srcs/utils/ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes/ -I libft/

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

bonus:		${NAME}

re:			fclean all
