# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 01:38:58 by cberganz          #+#    #+#              #
#    Updated: 2021/11/28 15:49:33 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= tester

FLAGS		= -Wall -Wextra -Werror

SRC		= main.c part1_tester.c part2_tester.c

SRCB		= main_bonus.c part1_tester.c part2_tester.c bonus_tester.c

OBJS		= ${SRC:.c=.o}

OBJSB		= ${SRCB:.c=.o}

${NAME}: ${SRC} 
	gcc -o ${NAME} -I../ -L../ ${SRC} -lft -lbsd

bonus: ${SRCB}
	gcc -o ${NAME} -I../ -L../ ${SRCB} -lft -lbsd

all: ${NAME}

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
