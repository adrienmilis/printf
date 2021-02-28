DIR = ./srcs/

SRCS = srcs/basic_fcts.c \
		srcs/converters.c \
		srcs/flag_minus.c \
		srcs/flag_point.c \
		srcs/flag_width.c \
		srcs/ft_printf.c \
		srcs/supp_fcts.c
NAME = libftprintf.a
OBJS = $(SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror -c -I./headers
GCC = gcc
RM = rm -rf

all: $(NAME)

%.o: %.c
	@echo "Compiling $<"
	@$(GCC) $(FLAGS) $< -o $(<:c=o)
	@echo "Compiling OK!"

$(NAME): $(OBJS)
	$(GCC) $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
