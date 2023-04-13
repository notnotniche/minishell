NAME =		 minishell

PARSER_DIR = parser/

LEXER_DIR =	lexer/

MAIN = 		main.c

SRCS = 		${PARSER_DIR}read_line.c

MAIN_M = 	${MAIN:.c=.o}
OBJS = 		${SRCS:.c = 0}

CC = 		clang

RM = 		rm -f

CFLAGS = 	-Wall -Wextra -Werror -fstandalone-debug -g3

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${MAIN_M} ${OBJS} $(MLX_LIB)
			${CC} ${CFLAGS} ${MAIN_M} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}
			${RM} ${MAIN_M}

fclean:		clean
			${RM} ${NAME}

re: 		fclean
			${MAKE} all -j

.phony:		all clean fclean re