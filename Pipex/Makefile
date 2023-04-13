# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itahani <itahani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 12:17:10 by itahani           #+#    #+#              #
#    Updated: 2022/12/05 17:51:09 by itahani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./SRC/pipex.c \
./SRC/get_path.c \
./SRC/init_tabs.c \
./SRC/children.c \

OBJS	=	${SRCS:%.c=%.o}

OBJSB	=	

DEPS	=	${OBJS:%.o=%.d}
DEPSB	=	

INCL	=	-I ./Libft

NAME	=	pipex

CC		=	gcc -g3 #-fsanitize=address

CFLAGS	=	-Wall -Werror -Wextra
CPPFLAGS=	#-MMD

RM		=	rm -f

BONUS	=	

LIBFT	=	-L ./Libft/. -lft


all:		${NAME}


.c.o:	
			${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}


${NAME}:	${OBJS} Libft/libft.a
			${CC} ${CPPFLAGS} ${CFLAGS} -o $@ $^ ${LIBFT}

-include ${DEPS}
bonus:	${BONUS}



#-include ${DEPSB}
Libft/libft.a:
	make -C Libft



clean:
	make -C Libft clean

	${RM} ${OBJS} ${DEPS}

fclean:		clean
	make -C Libft fclean
	${RM} ${NAME}

re:			fclean
	make all

.PHONY:		all clean fclean re libftc libftfc bonus
