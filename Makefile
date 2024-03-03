NAME = fdf.out

CC = cc

AR = ar

CFLAGS = -Wall -Werror -Wextra

ARFLAGS  = -rcs

SOURCES = ft_print.c ft_window.c ft_free_map.c ft_map_array.c ft_read_map.c main.c

SRCPATH = ./src

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

LPATH = ./libft

LNAME = ft

${NAME}: ${OBJECTS}
	${MAKE} -C ${LPATH}
	${MAKE} -C ${LPATH} bonus
	${CC} ${CFLAGS} -Lmlx -lmlx -L ${LPATH} -l ${LNAME} ${SOURCES} -framework OpenGL -framework AppKit -g

clean:
	${MAKE} -C ./libft clean
	rm -f ${OBJECTS} ${BONUS_OBJ}

fclean: clean
	${MAKE} -C ./libft fclean
	rm -f ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clean fclean re
