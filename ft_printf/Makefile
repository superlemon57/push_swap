NAME	= ft_printf.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar rcs
RM	= rm -f

SRC	=	ft_printf.c ft_which_index.c ft_putstrcount.c\
		ft_putcharcount.c ft_puthexacount.c ft_putuphexacount.c ft_putnbrcount.c\
		ft_putnbru.c ft_adressp.c\

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

