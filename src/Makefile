NAME = fdf.out

CC = cc

AR = ar

CFLAGS = -Wall -Werror -Wextra

ARFLAGS  = -rcs

SOURCES = move.c ft_window.c ft_free_map.c ft_map_array.c ft_read_map.c errors.c bonus.c draw.c main.c mouse.c rotations.c bresenham.c colour.c

SRCPATH = ./src

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
LPATH = ./libft

LNAME = ft

${NAME}: ${OBJECTS}
	${MAKE} -C ${LPATH}
	${MAKE} -C ${LPATH} bonus
	$(CC) $(OBJECTS) -Lmlx_linux -lmlx_Linux -L $(LPATH) -l$(LNAME) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
clean:
	${MAKE} -C ./libft clean
	rm -f ${OBJECTS} ${BONUS_OBJ}

fclean: clean
	${MAKE} -C ./libft fclean
	rm -f ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clean fclean re
