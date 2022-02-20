CC= cc

FLAGS=-Wall -Wextra -Werror

RM= rm -rf

Mandelbort = Mandelbort

julia = julia

FILES = Mandelbort.c my_mlx_pixel_put.c scalling.c Equation_fractal.c zoom_.c julia2.c fractol.c  equation_fractal_julia.c zoom_v2.c  equation_fractal_3.c \
		key_handler.c ft_strcmp.c ft_close.c burnin_ship.c zoom_v3.c

FILES2 = burnin_ship.c zoom_v3.c key_handler.c ft_close.c  Mandelbort.c my_mlx_pixel_put.c scalling.c Equation_fractal.c zoom_.c julia2.c fractol.c  equation_fractal_julia.c zoom_v2.c  equation_fractal_3.c \
		 ft_strcmp.c 


NAME = fractol

OBJ = $(FILES:.c=.o)

OBJ2 = $(FILES2:.c=.o)

HEADER= fractol.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ)  -Ofast -lmlx -framework OpenGL -framework AppKit -o fractol

%.o: %.c $(FILES) $(HEADER)
	$(CC) $(FLAGS) -Ofast -Imlx -c $< -o $@

bonus: $(OBJ2)
	$(CC) $(FLAGS) $(OBJ2)  -Ofast -lmlx -framework OpenGL -framework AppKit -o fractol
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(Mandelbort) $(julia)

re : fclean all

.PHONY: all re clean fclean