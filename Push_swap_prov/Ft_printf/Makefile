.PHONY : all clean fclean re

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

INCLUDE = ./ft_printf.h

SRC = ./ft_printf.c \
		./utils.c 

OBJ = ${SRC:.c=.o}

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar -rs $(NAME) $(OBJ) $(INCLUDE)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all