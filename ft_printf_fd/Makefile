NAME	= ft_printf_fd.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar rcs
RM	= rm -f

SRC	=	ft_printf_fd.c ft_which_index.c ft_putstrcount_fd.c\
		ft_putcharcount_fd.c ft_puthexacount_fd.c ft_putuphexacount_fd.c ft_putnbrcount_fd.c\
		ft_putnbru_fd.c ft_adress_fd.c ft_putfloat_fd.c\

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf_fd.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

