NAME = FdF
SRC = main.c		\
	  draw.c		\
	  calculs.c		\
	  mlx.c			\
	  parsing.c		\
	  utils.c		\
	  zoom_option.c	\
	  move_option.c	\
	  rotate.c		\
	  display.c		\
	  pike.c		\
	  hook.c		\
	  libft/libft.a

FLAG = -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(FLAG)

clean:
	 make -C libft/clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/fclean
	rm -rf $(NAME)

re: fclean all
