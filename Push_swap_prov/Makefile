.PHONY : all clean fclean re

CFLAGS = -Wall -Wextra -Werror -g

LDFLAGS = -LFt_printf -lftprintf -LLibft -lft

NAME = push_swap

INCLUDE = -I./Ft_printf -I./Libft

SRC = ./main.c \
		./algorithm.c \
		./parsing.c \
		./s_.c \
		./r_.c \
		./rr_.c \
		./p_.c \
		./utils.c \
		./utils_list.c \
		./utils_list2.c \
		./search.c

OBJ = ${SRC:.c=.o}

%.o : %.c
	cc $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ)
	cd Ft_printf && make all
	cd Libft && make all
	cc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJ)
	cd Ft_printf && make clean
	cd Libft && make clean

fclean : clean
	rm -f $(NAME)
	cd Ft_printf && make fclean
	cd Libft && make fclean

re : fclean all