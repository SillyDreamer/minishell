NAME = minishell

CFLAGS =  -I libft/includes/ -I srcs/ft_printf/ -I ./includes

SRC = ./ft_printf/ft_printf.c ./ft_printf/ft_specifier.c ./ft_printf/ft_type.c \
      ./srcs/main.c ./srcs/ft_comands.c ./srcs/ft_eenv.c ./srcs/ft_signal.c \
	  ./srcs/ft_setenv.c ./srcs/ft_unsetenv.c ./srcs/ft_cd.c ./srcs/ft_echo.c ./srcs/ft_path.c \
	  ./srcs/utils.c ./srcs/ft_dir.c ./srcs/ft_tab.c ./srcs/ft_tab2.c \
	  ./getnextline/get_next_line.c \


OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@ 

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\x1B[34m(✿｡✿)"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
