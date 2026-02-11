NAME	= push_swap

LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf

SRC	 =		add_argv.c check_flags.c create_stack_a.c create_stack.c flags.c main.c push.c\
			reverse_rotate.c rotate.c swap.c ft_atoi_mod.c\
		
OBJ		= $(SRC:.c=.o)

LIBFT_A = $(LIBFT_DIR)/libft.a
FT_PRINTF_A = $(FT_PRINTF_DIR)/ft_printf.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I. -I$(LIBFT_DIR) -I$(FT_PRINT_DIR) -fsanitize=address,undefined,leak -g3
RM	= rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(FT_PRINTF_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(FT_PRINTF_A) -o $(NAME)
	
%.o: %.c libft.h push_swap.h ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)
	
$(FT_PRINTF_A):
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
