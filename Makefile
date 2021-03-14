# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 20:34:01 by gmonitor          #+#    #+#              #
#    Updated: 2021/03/10 20:32:58 by gmonitor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= *.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

INC		= bsq.h

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

BINAME	= bsq.exe

${BINAME}:${SRCS} ${INC}
		${CC} -c ${CFLAGS} ${SRCS}
		${CC} ${CFLAGS} -o ${BINAME} ${OBJS} -I ${INC}

all:	${BINAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${BINAME}

re:		fclean all

.PHONY:	re clean all .c.o fclea
