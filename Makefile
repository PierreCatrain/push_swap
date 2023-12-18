# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 10:26:55 by picatrai          #+#    #+#              #
#    Updated: 2023/12/15 16:23:14 by picatrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
SRC = main.c parsing.c ft_split.c rules_push.c rules_reverse_rotate.c rules_rotate.c rules_swap.c \
utilitaires.c up_and_down.c alg.c pick.c ft_transfer.c ft_calcul_cout.c \
double_up_and_down.c
SRC_BONUS = checker.c parsing.c ft_split.c utilitaires.c get_next_line.c get_next_line_utils.c \
rules_push.c rules_reverse_rotate.c rules_rotate.c rules_swap.c
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}
FLAGS = -Wall -Werror -Wextra
CC = cc
HEADER = push_swap.h

.c.o:
	${CC} ${FLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} -g3 ${FLAGS} ${OBJ} -o ${NAME}

bonus: ${OBJ_BONUS}
	${CC} -g3 ${FLAGS} ${OBJ_BONUS} -o ${NAME_BONUS}

all: ${NAME}

clean:
	rm -f ${OBJ} ${OBJ_BONUS}

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}

re: fclean all
