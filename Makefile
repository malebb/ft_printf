# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 19:40:00 by mlebrun           #+#    #+#              #
#    Updated: 2020/11/26 11:09:17 by mlebrun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c display.c print_integer.c \
size.c print_no_integer.c precision.c parse.c display_float.c \
ft_display_float_utils.c ft_display_float_utils_2.c ft_display_float_utils_3.c
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
