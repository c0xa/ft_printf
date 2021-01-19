NAME        = libftprintf.a
LIBFT_DIR   = libft/
LIBFT       = libft.a
INCLDS      = includes/
SRC         = ft_printf.c \
				ft_printchar.c \
				ft_printstring.c \
				ft_printint.c \
				ft_printunint.c \
				ft_printpointer.c \
				ft_printsixteenlupper.c \
				ft_printsixteenlower.c \
				ft_flag.c \
				ft_parseflag.c \
				ft_itoasixteen.c
OBJ			= $(SRC:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
.c.o:
	$(CC) $(CFLAGS) -I $(INCLDS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)

all:  $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re:		fclean all

.PHONY: all clean fclean re
