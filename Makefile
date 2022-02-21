CC= cc

FLAGS=-Wall -Wextra -Werror

MANDATORY_MAIN=fractol.o
FILES = Mandelbort.c my_mlx_pixel_put.c scalling.c Equation_fractal.c zoom_.c julia2.c equation_fractal_julia.c zoom_v2.c \
		key_handler.c ft_strcmp.c ft_close.c 

BONUS_MAIN=bonus/bonus_bonus.o
FILES2 = bonus/burnin_ship_bonus.c bonus/keyhandler3_bonus.c bonus/zoom_v3_bonus.c bonus/equation_fractal_3_bonus.c

NAME = fractol

HEADER = fractol.h

NAME_BONUS=fractol_bonus

OBJ = $(FILES:.c=.o)

OBJ2 = $(FILES2:.c=.o)

HEADER = fractol.h

.PHONY: all re clean fclean bonus

all: $(NAME)

$(NAME): $(OBJ) $(MANDATORY_MAIN) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) $(MANDATORY_MAIN) -Ofast -lmlx -framework OpenGL -framework AppKit -o fractol

%.o: %.c 
	$(CC) $(FLAGS) -Ofast -Imlx -I . -c $< -o $@

bonus: $(NAME_BONUS) $(HEADER)

$(NAME_BONUS): $(OBJ2) $(OBJ) $(BONUS_MAIN)
	$(CC) $(FLAGS) $(OBJ2) $(OBJ) $(BONUS_MAIN) -Ofast -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ2) $(MANDATORY_MAIN) $(BONUS_MAIN)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all
