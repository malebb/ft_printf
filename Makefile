# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 19:40:00 by mlebrun           #+#    #+#              #
#    Updated: 2020/11/26 18:01:31 by mlebrun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c display.c print_integer.c print_integer_utils.c print_integer_utils_2.c \
size.c print_no_integer.c print_no_integer_utils.c precision.c parse.c display_float.c \
ft_display_float_utils.c ft_display_float_utils_2.c ft_display_float_utils_3.c\
ft_display_float_utils_4.c \
ft_parse_utils.c

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
