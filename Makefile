NAME = so_long

SRCS =  Get_Next_Line/get_next_line.c 	  \
      	Get_Next_Line/get_next_line_utils.c \
	  	so_long.c							\
		so_long_utils.c					\
		moves.c					\
		exit.c					\
		helper.c				\
		check.c 				\
		ft_printf/ft_format.c			\
		ft_printf/ft_printhex.c			\
		ft_printf/ft_printf.c			\
		ft_printf/ft_pointer.c		\
		ft_printf/ft_printunsigned.c		\
		ft_printf/ft_putchar.c			\
		ft_printf/ft_putnbr.c			\
		ft_printf/ft_putstr.c


OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g3 -Wall -Werror -Wextra #-fsanitize=address

EXEC = so_long

all : $(NAME)

$(NAME): $(OBJS)
	(cd mlx && make)
	(cd libft && make)
	$(CC) $(CFLAGS) $(OBJS) -L ./libft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(EXEC) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) && cd mlx && make clean
	cd libft && make fclean
re: fclean all