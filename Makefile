# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 20:03:43 by mledda            #+#    #+#              #
#    Updated: 2026/02/26 13:43:34 by tlopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = ./libft
FT_PRINTF_FD_DIR = ./ft_printf_fd

SRC	 =		add_argv.c check_flags.c create_stack_a.c create_stack.c flags.c main.c push.c\
			reverse_rotate.c rotate.c swap.c ft_atoi_mod.c bucket_sort_utils.c simple_sort_utils.c\
			bucket_sort.c bucket_sort_utils_2.c radix_sort.c simple_sort.c\
		
OBJ		= $(SRC:.c=.o)

LIBFT_A = $(LIBFT_DIR)/libft.a
FT_PRINTF_FD_A = $(FT_PRINTF_FD_DIR)/ft_printf_fd.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I. -I$(LIBFT_DIR) -I$(FT_PRINT_FD_DIR) -fsanitize=address,undefined,leak -g3 -std=c99
RM	= rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(FT_PRINTF_FD_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(FT_PRINTF_FD_A) -o $(NAME)
	
%.o: %.c libft.h push_swap.h ft_printf_fd.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)
	
$(FT_PRINTF_FD_A):
	@$(MAKE) -C $(FT_PRINTF_FD_DIR)

clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_FD_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_FD_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
