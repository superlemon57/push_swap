# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlopez <tlopez@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 20:03:43 by mledda            #+#    #+#              #
#    Updated: 2026/02/28 17:36:19 by tlopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_DIR = ./libft
FT_PRINTF_FD_DIR = ./ft_printf_fd

SRC  =  ft_parse_args.c ft_flags_check.c ft_stack_init.c ft_stack_core.c \
        ft_flags_detect.c main.c ft_op_push.c \
        ft_op_reverse_rotate.c ft_op_rotate.c ft_op_swap.c ft_atoi_mod.c \
        ft_indexation.c ft_stack_utils.c \
        ft_bucket_sort.c ft_stack_pos.c ft_radix_sort.c ft_sort_small.c \
        ft_sort_dispatcher.c
		
OBJ		= $(SRC:.c=.o)

LIBFT_A = $(LIBFT_DIR)/libft.a
FT_PRINTF_FD_A = $(FT_PRINTF_FD_DIR)/ft_printf_fd.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I. -I$(LIBFT_DIR) -I$(FT_PRINT_FD_DIR)
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
