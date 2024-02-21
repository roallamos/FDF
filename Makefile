NAME = fdf.out

CC = cc

AR = ar

CFLAGS = -Wall -Werror -Wextra

ARFLAGS  = -rcs

SOURCES = ft_read_map.c main.c

OBJECTS = $(SOURCES:.c=.o)

LPATH = ./libft

LNAME = ft

${NAME}: ${OBJECTS}
	${MAKE} -C ${LPATH}
	${MAKE} -C ${LPATH} bonus
	${CC} ${CFLAGS} -L ${LPATH} -l ${LNAME} ${SOURCES} -g

clean:
	${MAKE} -C ./libft clean
	rm -f ${OBJECTS} ${BONUS_OBJ}

fclean: clean
	${MAKE} -C ./libft fclean
	rm -f ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clean fclean re
