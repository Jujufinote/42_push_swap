.PHONY : all clean fclean re

CFLAGS = -Wall -Wextra -Werror -g

LDFLAGS = -LFt_printf -lftprintf -LLibft -lft

NAME = push_swap

NAME_BONUS = checker

INCLUDE = -I./Ft_printf -I./Libft

CPATH = ./src/

SRC = push_swap.c \
		algorithm.c \
		parsing.c \
		cleaning.c \
		s_.c \
		r_.c \
		rr_.c \
		p_.c \
		cost.c \
		utils.c \
		utils_list.c \
		utils_list2.c \
		search.c

SRC_BONUS = checker.c \
			sorting.c \
			parsing.c \
			parsing_inst.c \
			reading.c \
			cleaning.c \
			s_.c \
			r_.c \
			rr_.c \
			p_.c \
			utils_list.c \
			utils_list2.c \
			utils_bonus.c

OBJ = ${addprefix ${CPATH},${SRC:.c=.o}}

OBJ_BONUS = ${addprefix ${CPATH},${SRC_BONUS:.c=.o}}

%.o : %.c
	cc $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ)
	cd Ft_printf && make all
	cd Libft && make all
	cc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(NAME_BONUS) : $(OBJ_BONUS)
	cd Ft_printf && make all
	cd Libft && make all
	cc $(CFLAGS) $(OBJ_BONUS) $(LDFLAGS) -o $(NAME_BONUS)

all : $(NAME)

bonus : $(NAME_BONUS)

clean :
	rm -f $(OBJ) $(OBJ_BONUS)
	cd Ft_printf && make clean
	cd Libft && make clean

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
	cd Ft_printf && make fclean
	cd Libft && make fclean

re : fclean all
